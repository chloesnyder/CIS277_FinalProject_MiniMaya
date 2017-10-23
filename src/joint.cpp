#include "joint.h"

Joint::Joint()  :
    QTreeWidgetItem(),
    bufIdx(QOpenGLBuffer::IndexBuffer),
    bufPos(QOpenGLBuffer::VertexBuffer),
    bufNor(QOpenGLBuffer::VertexBuffer),
    bufCol(QOpenGLBuffer::VertexBuffer)
{
    pos = glm::vec4(0, 0, 0, 1);
    ro = glm::quat(1, 0, 0, 0);
    parent = NULL;
    overallTransformation = glm::mat4();





}

glm::vec4 Joint::lerpVecs(glm::vec4 a, glm::vec4 b, float t) {

    return glm::vec4(glm::vec3((1 - t) * a + t * b), 1);

}


Joint::Joint(QString nme, Joint* prnt, glm::vec4 ps, glm::quat rt, int i) {
    name = nme;
    parent = prnt;
    pos = ps;
    ro = rt;
    id = i;

    //qtreewidget stuff
    setText(0, nme);
    parent->addChild(this);
}

Joint::~Joint() {

}

void printableMatrix(glm::mat4 print) {


    //to row major
    print = glm::transpose(print);
    std::cout << print[0][0] << "  " << print[0][1] << "  " << print[0][2] << "  " << print[0][3] << std::endl;
    std::cout << print[1][0] << "  " << print[1][1] << "  " << print[1][2] << "  " << print[1][3] << std::endl;
    std::cout << print[2][0] << "  " << print[2][1] << "  " << print[2][2] << "  " << print[2][3] << std::endl;
    std::cout << print[3][0] << "  " << print[3][1] << "  " << print[3][2] << "  " << print[3][3] << std::endl;
    std::cout << std::endl;

}



glm::mat4 Joint::getLocalTransformation() {

    //from pos, get translation
    glm::mat4 T;
    T[0] = glm::vec4(1, 0, 0, 0);
    T[1] = glm::vec4(0, 1, 0, 0);
    T[2] = glm::vec4(0, 0, 1, 0);
    T[3] = glm::vec4(pos[0], pos[1], pos[2], 1);


    //from quat, get rotation
    glm::mat4 R = glm::mat4_cast(ro);


    return T * R;

}


glm::mat4 Joint::getOverallTransformation() {

    return overallTransformation;

}

void Joint::setOverallTransformation(glm::mat4 T) {
    overallTransformation = T;
}

void Joint::setBindMatrix() {
    bindmat = la::inverse(overallTransformation);
}

glm::mat4 Joint::getBindMatrix() {
    return bindmat;
}

glm::vec4 Joint::getPos() {
    return pos;

}

glm::quat Joint::getRotation() {
    return ro;

}


void Joint::setRotation(glm::quat newRo) {
    ro = newRo;
}

glm::vec4 Joint::getParentPos() {
    return parent->getPos();
}


QList<Joint*> Joint::getChildren() {
    return children;
}

void Joint::getAllDescendants(QList<Joint*>& descendants) {
    for (Joint* child : children) {
        descendants.push_back(child);
        child->getAllDescendants(descendants);
    }
}


void Joint::setParent(Joint *p) {
    parent = p;
}

void Joint::addChild(Joint* ch) {
    children.push_back(ch);
}

void Joint::setColor(glm::vec4 newColor) {
    highlightColor = newColor;

}

void Joint::toggleSelectedness() {
    isSelected = !isSelected;
}

void Joint::updatePosition(glm::vec4 newPos) {
    pos = newPos;


}

glm::mat4 Joint::getTransformationAtFrame(int curTime) {
    //never hurts to double check :D
    if(keyframes.size() == 0) {

        return getLocalTransformation();
    }


    //if has keyframe, return transformation at that keyframe
    if (keyframes.contains(curTime)) {
        return keyframes[curTime]->getTransformation();
    }



    //otherwise, SQUAD
    int prevFrameTime = getPrevKeyframeTime(curTime);
    int prevPrevFrameTime = getPrevKeyframeTime(prevFrameTime);

    int nextFrameTime = getNextKeyframeTime(curTime);
    int nextNextFrameTime = getNextKeyframeTime(nextFrameTime);

    //q(i -1)
    glm::quat qh = keyframes[prevPrevFrameTime]->getRotation();

    //qi
    glm::quat qi = keyframes[prevFrameTime]->getRotation();


    //q(i + 1)
    glm::quat qj = keyframes[nextFrameTime]->getRotation();

    //q(i + 1 + 1)
    glm::quat qk = keyframes[nextNextFrameTime]->getRotation();


    //calculate intermediate quats
    glm::quat si = glm::intermediate(qh, qi, qj);
    glm::quat sj = glm::intermediate(qi, qj, qk);



    //calculate time paramter
    float t = (float) (curTime - prevFrameTime)/(nextFrameTime - prevFrameTime);

    if (nextFrameTime == prevFrameTime) {
       if (curTime < prevFrameTime) {
           return keyframes[prevFrameTime]->getTransformation();
       }

       if (curTime > nextFrameTime) {
           return keyframes[nextFrameTime]->getTransformation();
       }
    }


    glm::quat squadded = glm::squad(qi, qj, si, sj, t);



    //get prev and next translations
    glm::vec4 prevPrevTranslation = keyframes[prevPrevFrameTime]->getTranslation();
    glm::vec4 prevTranslation = keyframes[prevFrameTime]->getTranslation();
    glm::vec4 nextTranslation = keyframes[nextFrameTime]->getTranslation();
    glm::vec4 nextNextTranslation = keyframes[nextNextFrameTime]->getTranslation();

    //calculate spline of translations
    glm::vec4 spline = cubicSpline(prevPrevTranslation, prevTranslation, nextTranslation, nextNextTranslation, t); //lerpVecs(prevTranslation, nextTranslation, t);


    //from pos, get translation
    glm::mat4 T;
    T[0] = glm::vec4(1, 0, 0, 0);
    T[1] = glm::vec4(0, 1, 0, 0);
    T[2] = glm::vec4(0, 0, 1, 0);
    T[3] = glm::vec4(spline[0], spline[1], spline[2], 1);



    //from quat, get rotation
    glm::mat4 R = glm::mat4_cast(squadded);


    //return both as a rotation
    return T * R;
    //return getLocalTransformation();
}


glm::vec4 Joint::cubicSpline(glm::vec4 a, glm::vec4 b, glm::vec4 c, glm::vec4 d, float t) {

    glm::vec4 handle1 = a  + glm::vec4(b - a);
    glm::vec4 handle2 = c - glm::vec4(d - c);


    glm::vec4 p1 = lerpVecs(b, handle1, t);
    glm::vec4 p2 = lerpVecs(handle1, handle2, t);
    glm::vec4 p3 = lerpVecs(handle2, c, t);

    glm::vec4 q1 = lerpVecs(p1, p2, t);
    glm::vec4 q2 = lerpVecs(p2, p3, t);

    glm::vec4 x = lerpVecs(q1, q2, t);

    return x;

}


int Joint::getID() {
    return id;
}


int Joint::getNextKeyframeTime(int frameTime) {

    //get greatest key
    int maxFrameTime = 0;

    for (int kf : keyframes.keys()) {
        if (kf > maxFrameTime) {
            maxFrameTime = kf;
        }
    }

    //loop until greatest key
    int nextFrameTime = frameTime;
    while (nextFrameTime < maxFrameTime) {
        nextFrameTime++;
        if (keyframes.keys().contains(nextFrameTime)) {
            return nextFrameTime;
        }
    }

    //if frametime is greater than maxframe time, return max time with key
    if (frameTime > maxFrameTime) {
        return maxFrameTime;
    }
    //no next, so just return current frameTime
    return frameTime;

}



int Joint::getPrevKeyframeTime(int frameTime) {


    //get smallest key
    int minFrameTime = 1000000; //lol

    for (int kf : keyframes.keys()) {
        if (kf < minFrameTime) {
            minFrameTime = kf;
        }
    }

    int prevFrameTime = frameTime;
    while (prevFrameTime > 0) {
        prevFrameTime--;
        if (keyframes.keys().contains(prevFrameTime)) {
            return prevFrameTime;
        }
    }

    //if frametime is less than min frame time, return min
    if (frameTime < minFrameTime) {
        return minFrameTime;
    }

    //no prev, so just return current frameTime
    return frameTime;

}


void Joint::addNewKeyframe(int frameTime) {
    keyframes.insert(frameTime, new Frame(this->getPos(), this->getRotation(), frameTime));
   }

QList<Frame*> Joint::getKeyframes() {

    QList<Frame*> frames;
    for (int time : keyframes.keys()) {
        frames.push_back(keyframes[time]);
    }

    return frames;
}


bool Joint::hasKeyframe(Frame * f) {

    if (keyframes.isEmpty()) {
        return false;
    }

    return keyframes.keys().contains(f->getTime());
}

bool Joint::hasKeyframeTime(int time) {

    if (keyframes.size() == 0) {
        return false;
    }
    return keyframes.keys().contains(time);
}

glm::mat4 Joint::getKeyframeTransformation(int time) {
    return keyframes[time]->getTransformation();
}

void Joint::create() {

    std::vector<glm::vec4> vertices;
    std::vector<glm::vec4>colors;
    glm::vec4 v;



    // Store roll vertex (IDX 0 - 19)
    for (int i = 0; i < 20; i++) {
        v = overallTransformation * glm::rotate(glm::mat4(1.0f), i / 20.f * TWO_PI, glm::vec3(0, 1, 0)) * glm::vec4(0.5f, 0, 0, 1);
        vertices.push_back(v);

        if (!isSelected) {
            colors.push_back(glm::vec4(1, 0, 0, 1));
        }

        else {
            colors.push_back(highlightColor);
        }


    }
    // Store pitch  verts (IDX 20 - 39)
    for (int i = 0; i < 20; i++) {
        v = overallTransformation * glm::rotate(glm::mat4(1.0f), i / 20.f * TWO_PI, glm::vec3(1, 0, 0)) * glm::vec4(0, 0, 0.5f, 1);
        vertices.push_back(v);
        if (!isSelected) {
            colors.push_back(glm::vec4(0, 0, 1, 1));
        }

        else {
            colors.push_back(highlightColor);
        }
    }


    // Store yaw cap verts (IDX 40 - 59)
    for (int i = 0; i < 20; i++) {
        v = overallTransformation * glm::rotate(glm::mat4(1.0f), i / 20.f * TWO_PI, glm::vec3(0, 0, 1)) * glm::vec4(0, 0.5f, 0, 1);
        vertices.push_back(v);


        if (!isSelected) {
            colors.push_back(glm::vec4(0, 1, 0, 1));
        }

        else {
            colors.push_back(highlightColor);
        }
    }

    //don't need to do nothing here
    std::vector<glm::vec4> norms;


    std::vector<GLuint> indices;

    //first ring
    for (int i = 0; i < 19; i++) {
        indices.push_back(i);
        indices.push_back(i + 1);
    }
    indices.push_back(19);
    indices.push_back(0);

    //second ring
    for (int i = 20; i < 39; i++) {
        indices.push_back(i);
        indices.push_back(i + 1);
    }
    indices.push_back(39);
    indices.push_back(20);

    //third ring
    for (int i = 40; i < 59; i++) {
        indices.push_back(i);
        indices.push_back(i + 1);
    }
    indices.push_back(59);
    indices.push_back(40);



    //push our position in world space
    indices.push_back(60);
    vertices.push_back(overallTransformation * glm::vec4(0,0,0,1) );
    colors.push_back(glm::vec4(1, 1, 0, 1));


    //EIGHT HOURS OF DEBUGGING LATER REALIZE ALL I NEEDED WAS TO MOVE THIS OUTSIDE THE IF STATEMENT
    //I LOVE GRAPHICS.
    indices.push_back(61);


    if (parent != NULL) {
        vertices.push_back(parent->getOverallTransformation() * glm::vec4(0,0,0,1) );
        colors.push_back(glm::vec4(0, 0, 0, 1));
    }

    count = indices.size();

    bufIdx.create();
    bufIdx.bind();
    bufIdx.setUsagePattern(QOpenGLBuffer::StaticDraw);
    bufIdx.allocate(indices.data(), indices.size() * sizeof(GLuint));

    bufPos.create();
    bufPos.bind();
    bufPos.setUsagePattern(QOpenGLBuffer::StaticDraw);
    bufPos.allocate(vertices.data(), vertices.size() * sizeof(glm::vec4));

    bufCol.create();
    bufCol.bind();
    bufCol.setUsagePattern(QOpenGLBuffer::StaticDraw);
    bufCol.allocate(colors.data(), colors.size() * sizeof(glm::vec4));

    bufNor.create();
    bufNor.bind();
    bufNor.setUsagePattern(QOpenGLBuffer::StaticDraw);
    bufNor.allocate(norms.data(), 2 * sizeof(glm::vec4));



}

void Joint::destroy()
{
    bufIdx.destroy();
    bufPos.destroy();
    bufNor.destroy();
    bufCol.destroy();
}

GLenum Joint::drawMode()
{
    return GL_LINES;
}

int Joint::elemCount()
{
    return count;
}


bool Joint::bindIdx()
{
    return bufIdx.bind();
}

bool Joint::bindPos()
{
    return bufPos.bind();
}

bool Joint::bindNor()
{
    return bufNor.bind();
}

bool Joint::bindCol()
{
    return bufCol.bind();
}

QString Joint::getName() {
    return name;
}



