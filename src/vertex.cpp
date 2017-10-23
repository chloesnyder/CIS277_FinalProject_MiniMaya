#include "vertex.h"
#include "face.h"

Vertex::Vertex() :
    QListWidgetItem(),
    bufIdx(QOpenGLBuffer::IndexBuffer),
    bufPos(QOpenGLBuffer::VertexBuffer),
    bufNor(QOpenGLBuffer::VertexBuffer),
    bufCol(QOpenGLBuffer::VertexBuffer)

{
}

Vertex::Vertex(Vertex* v):
    QListWidgetItem(),
    bufIdx(QOpenGLBuffer::IndexBuffer),
    bufPos(QOpenGLBuffer::VertexBuffer),
    bufNor(QOpenGLBuffer::VertexBuffer),
    bufCol(QOpenGLBuffer::VertexBuffer)

{
    this->pos = v->pos;
    this->edge = new HalfEdge(v->edge);
    this->id = v->id;
    this->name = v->name;
}

Vertex::Vertex(glm::vec4 pos, int id) :
    QListWidgetItem(),
    bufIdx(QOpenGLBuffer::IndexBuffer),
    bufPos(QOpenGLBuffer::VertexBuffer),
    bufNor(QOpenGLBuffer::VertexBuffer),
    bufCol(QOpenGLBuffer::VertexBuffer)

{

    this->pos = pos;
    this->id = id;
    this->name = QString::fromStdString(std::to_string(id));
    this->setText(name);

}

void Vertex::setEdge(HalfEdge* e) {
    this->edge = e;
}

HalfEdge* Vertex::getEdge() {
    return edge;
}


void Vertex::shiftToBarycenter() {



    QList<Face*> incidentFaces;
    QList<Vertex*> adjacentMidpoints;

    HalfEdge* e = edge;
    Face* curFace = e->getFace();

    if (curFace == NULL) {

        curFace = e->getSym()->getFace();

    }

    //traverse to find all adjacent midpoints and incident faces



    while (!incidentFaces.contains(curFace)) {
        incidentFaces.push_back (curFace);
        adjacentMidpoints.push_back(e->getSym()->getVert());

        e = e->getNext();
        if (e->getSym()->getVert() == this) {
            //move onto opposite face
            e = e->getSym();
            curFace = e->getFace();

        }
    }

    glm::vec4 sume = glm::vec4(0.f);
    for (Vertex* adj : adjacentMidpoints) {
        sume += adj->getPos();
    }
    float n = adjacentMidpoints.size();
    float nsq = pow(n, 2);

    //sum of all incident face centroids
    glm::vec4 sumf = glm::vec4(0.0);
    for (Face* face : incidentFaces) {
        sumf+= face->calculateCentroid();
    }




    glm::vec4 oldPos = pos;

    glm::vec4 newPos = ((n - 1) * oldPos/n)  + sume/nsq + sumf/nsq;

    pos = newPos;
    std::cout << "vertex:: shifted to barycenter!" << std::endl
              << glm::to_string(oldPos) << " to "
              << glm::to_string(newPos) << std::endl;
}

void Vertex::create() {

    std::vector<glm::vec4> vertices;

    vertices.push_back(pos);


    std::vector<glm::vec4> norms;

    std::vector<glm::vec4>colors;
    colors.push_back(glm::vec4(0, 0, 0, 1));


    std::vector<GLuint> indices;
    indices.push_back(0);


    bufIdx.create();
    bufIdx.bind();
    bufIdx.setUsagePattern(QOpenGLBuffer::StaticDraw);
    bufIdx.allocate(indices.data(), sizeof(GLuint));

    bufPos.create();
    bufPos.bind();
    bufPos.setUsagePattern(QOpenGLBuffer::StaticDraw);
    bufPos.allocate(vertices.data(),sizeof(glm::vec4));

    bufCol.create();
    bufCol.bind();
    bufCol.setUsagePattern(QOpenGLBuffer::StaticDraw);
    bufCol.allocate(colors.data(), sizeof(glm::vec4));

    bufNor.create();
    bufNor.bind();
    bufNor.setUsagePattern(QOpenGLBuffer::StaticDraw);
    bufNor.allocate(norms.data(), sizeof(glm::vec4));





}

//MESH FUNCTION
/*
void Vertex::createJointBinds() {

    //if nothing in the jointIDs
    if (jointIDs.size() > 0) {


        std::vector<glm::vec2> jointWeightsToSend;

        //calculate joint weights

        std::vector<glm::ivec2> jointIDsToSend;
        glm::ivec2 jointIDVec  = glm::ivec2(jointIDs.at(0), jointIDs.at(1));



        bufJointIDs.create();
        bufJointIDs.bind();
        bufJointIDs.setUsagePattern(QOpenGLBuffer::StaticDraw);
        bufJointIDs.allocate(jointIDsToSend.data(), sizeof(glm::ivec2));

        bufWeights.create();
        bufWeights.bind();
        bufWeights.setUsagePattern(QOpenGLBuffer::StaticDraw);
        bufWeights.allocate(jointWeightsToSend.data(), sizeof(glm::vec2));

    }

}*/


glm::vec4& Vertex::getPos() {
    return pos;
}

std::string Vertex::printPos() {


    return glm::to_string(pos);


}

void Vertex::setPos(glm::vec4 newPos) {
    pos = newPos;
}

int Vertex::getid() {
    return id;
}

void Vertex::updateID(int newID) {
    id = newID;
}

bool Vertex::noFacesLeft() {
    return false;
}

void Vertex::setClosestJoints(QList<Joint*> allJoints) {
    //clear old round of joints
    jointIDs.clear();
    jointWeights.clear();



    QMap<float, Joint*> distances;

    //calculate distance from each joint and sort
    for (Joint * joint : allJoints) {
        glm::vec4 globalPos = joint->getOverallTransformation() * glm::vec4(0, 0, 0, 1);
        float distance = glm::distance(globalPos, pos);
        distances.insert(distance, joint);
    }


    //keeps closest 2 joints
    QMap<float, Joint*> jointDistancesToVertex;



    //get the two closeset joints with the most ratchet code possible
    int numInfluences = 2;
    int totalDistanceFromVertex = 0;
    for (float dist : distances.keys()) {

        //get total distance from vertex

        totalDistanceFromVertex += dist;


        jointWeights.push_back(dist);


        jointIDs.push_back(distances.value(dist)->getID());


        //std::cout << id << "influenced by joint: "<< distances.value(dist)->getName().toStdString() << std::endl;

        jointDistancesToVertex.insert(dist, distances.value(dist));

        numInfluences--;
        if (numInfluences == 0) {
            break;
        }

    }






    //calculate the jointWeights
    for (float weight : jointWeights) {

        weight /= totalDistanceFromVertex;
        weight = 1 - weight;

    }




    //make an ivec2 of the joint IDS
    jointIDsForBuffer = glm::ivec2(jointIDs.at(0), jointIDs.at(1));


   //make a vec2 of the weights
    jointWeightsForBuffer = glm::vec2(jointWeights.at(0), jointWeights.at(1));


}


glm::ivec2 Vertex::getJointIDsForBuffer() {
    return jointIDsForBuffer;
}

glm::vec2 Vertex::getJointWeightsForBuffer() {
    return jointWeightsForBuffer;
}

int Vertex::elemCount()
{
    return 1;
}


void Vertex::destroy()
{
    bufIdx.destroy();
    bufPos.destroy();
    bufNor.destroy();
    bufCol.destroy();


}


GLenum Vertex::drawMode()
{
    return GL_POINTS;
}



bool Vertex::bindIdx()
{
    return bufIdx.bind();
}

bool Vertex::bindPos()
{
    return bufPos.bind();
}

bool Vertex::bindNor()
{
    return bufNor.bind();
}

bool Vertex::bindCol()
{
    return bufCol.bind();
}


/*moved all this to mesh
 * bool Vertex::bindWeights() {
    return bufWeights.bind();

}
bool Vertex::bindJointIDs() {

    //if a buffer has been created, it can be bound
    return bufJointIDs.bind();
}*/
