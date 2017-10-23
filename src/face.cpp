#include "face.h"

#include "mygl.h"

Face::Face(int i) :  QListWidgetItem(),
    bufIdx(QOpenGLBuffer::IndexBuffer),
    bufPos(QOpenGLBuffer::VertexBuffer),
    bufNor(QOpenGLBuffer::VertexBuffer),
    bufCol(QOpenGLBuffer::VertexBuffer)
{
    this->id = i;
    this->face_color = glm::vec4(1, 1, 1, 1);
    this->setText(QString::fromStdString(std::to_string(id)));
}

Face::Face(Face* f) : QListWidgetItem(),
    bufIdx(QOpenGLBuffer::IndexBuffer),
    bufPos(QOpenGLBuffer::VertexBuffer),
    bufNor(QOpenGLBuffer::VertexBuffer),
    bufCol(QOpenGLBuffer::VertexBuffer)
{
    this->id = f->getid();
    this->face_color = f->face_color;
    this->setText(QString::fromStdString(std::to_string(this->id)));
    this->start_edge = new HalfEdge(f->getStartEdge());
}
/*
Face::Face(HalfEdge* s) : QListWidgetItem(),
    bufIdx(QOpenGLBuffer::IndexBuffer),
    bufPos(QOpenGLBuffer::VertexBuffer),
    bufNor(QOpenGLBuffer::VertexBuffer),
    bufCol(QOpenGLBuffer::VertexBuffer)
{
    start_edge = s;
    s->setFace(this);

}*/
void Face::setColor(glm::vec4 col) {
    face_color = col;
}


void Face::create() {
    std::vector<glm::vec4> vertices;


    std::vector<glm::vec4>colors;

    HalfEdge* edge = start_edge;




    while(edge->getNext() != start_edge) {
        vertices.push_back(edge->getVert()->getPos());
        edge = edge->getNext();
        colors.push_back(glm::vec4(0, 1, 0, 1));

    }
    vertices.push_back(edge->getVert()->getPos());
    colors.push_back(glm::vec4(0, 1, 0, 1));


    std::vector<GLuint> indices;


    for (unsigned int i = 0; i < vertices.size() - 1; i++) {
        indices.push_back(i);
        indices.push_back(i + 1);
    }

    indices.push_back(vertices.size() - 1);
    indices.push_back(0);

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
    bufCol.allocate(colors.data(), colors.size()* sizeof(glm::vec4));


}


HalfEdge* Face::getStartEdge() {
    return start_edge;
}

glm::vec4 Face::getColor() {
    return face_color;
}


void Face::setColor(int newColVal, int RGB) {
    float newColor = newColVal / 255.0f;
    face_color[RGB] = newColor;
}


void Face::setColor(float newR, float newG, float newB, float tint) {
    glm::vec4 newColor = glm::vec4(newR*tint, newG*tint, newB*tint, 1);
    face_color = newColor;
}

void Face::setStartEdge(HalfEdge* s) {
    start_edge = s;
    s->setFace(this);
}


glm::vec4 Face::calculateCentroid() {

    QList<glm::vec4> faceCorners;

    faceCorners.push_back(start_edge->getVert()->getPos());

    HalfEdge* loop = start_edge->getNext();
    while (loop != start_edge) {
        faceCorners.push_back(loop->getVert()->getPos());
        loop = loop->getNext();
    }

   glm::vec4 centroid = listAverage(faceCorners);


   return centroid;




}


void Face::quadrangulate() {


}

void Face::destroy()
{
    bufIdx.destroy();
    bufPos.destroy();
    bufNor.destroy();
    bufCol.destroy();
}

GLenum Face::drawMode()
{
    return GL_LINES;
}

int Face::elemCount()
{
    return count;
}



bool Face::bindIdx()
{
    return bufIdx.bind();
}

bool Face::bindPos()
{
    return bufPos.bind();
}

bool Face::bindNor()
{
    return bufNor.bind();
}

bool Face::bindCol()
{
    return bufCol.bind();
}


int Face::getid() {
    return id;
}



