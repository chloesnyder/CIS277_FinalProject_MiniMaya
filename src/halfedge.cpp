#include "halfedge.h"

HalfEdge::HalfEdge()
    :
     QListWidgetItem(),
     bufIdx(QOpenGLBuffer::IndexBuffer),
     bufPos(QOpenGLBuffer::VertexBuffer),
     bufNor(QOpenGLBuffer::VertexBuffer),
     bufCol(QOpenGLBuffer::VertexBuffer)

{


}
HalfEdge::HalfEdge(HalfEdge* h) :
    QListWidgetItem(),
    bufIdx(QOpenGLBuffer::IndexBuffer),
    bufPos(QOpenGLBuffer::VertexBuffer),
    bufNor(QOpenGLBuffer::VertexBuffer),
    bufCol(QOpenGLBuffer::VertexBuffer)

{
    this->face = new Face(h->face);
    this->id = h->id;
    this->name = QString::fromStdString(std::to_string(this->id));
    this->next = new HalfEdge(h->next);
    this->sym = new HalfEdge(h->sym);
    this->vert = new Vertex(h->vert);

}



HalfEdge::HalfEdge(Face* f, Vertex* v, HalfEdge* n, HalfEdge* s, int i) : QListWidgetItem(){
    this->face = f;
    this->vert = v;

    if (v != NULL) {
        v->setEdge(this);
    }

    this->next = n;

    this->sym = s;

    if (s != NULL) {
        s->setSym(this);
    }

    this->id = i;
    this->name = QString::fromStdString(std::to_string(id));
    this->setText(name);


}


void HalfEdge::create() {

    std::vector<glm::vec4> vertices;

    vertices.push_back(vert->getPos());
    vertices.push_back(sym->getVert()->getPos());

    std::vector<glm::vec4> norms;

    std::vector<glm::vec4>colors;
    colors.push_back(glm::vec4(1, 1, 0, 1));
    colors.push_back(glm::vec4(0.7, 0.5, 1, 1));

    std::vector<GLuint> indices;
    indices.push_back(0);
    indices.push_back(1);


    bufIdx.create();
    bufIdx.bind();
    bufIdx.setUsagePattern(QOpenGLBuffer::StaticDraw);
    bufIdx.allocate(indices.data(), 2 * sizeof(GLuint));

    bufPos.create();
    bufPos.bind();
    bufPos.setUsagePattern(QOpenGLBuffer::StaticDraw);
    bufPos.allocate(vertices.data(),2 * sizeof(glm::vec4));

    bufCol.create();
    bufCol.bind();
    bufCol.setUsagePattern(QOpenGLBuffer::StaticDraw);
    bufCol.allocate(colors.data(), 2 * sizeof(glm::vec4));

    bufNor.create();
    bufNor.bind();
    bufNor.setUsagePattern(QOpenGLBuffer::StaticDraw);
    bufNor.allocate(norms.data(), 2 * sizeof(glm::vec4));

}

HalfEdge* HalfEdge::getNext() {
    return next;
}

void HalfEdge::setNext(HalfEdge* n) {
    next = n;

}

HalfEdge* HalfEdge::getSym() {
    return sym;

}

void HalfEdge::setVert(Vertex* v) {
    vert = v;

    if (vert != NULL) {
        v->setEdge(this);
    }
}

void HalfEdge::setSym(Face* f, Vertex * v, HalfEdge* n, HalfEdge* s, int i) {
    sym = new HalfEdge(f, v, n, s, i);
    sym->setSym(this);

}

void HalfEdge::setSym(HalfEdge* e) {
    sym = e;

    if (sym != NULL && e->getSym() != this) {
        e ->setSym(this);
    }
}

Vertex* HalfEdge::getVert() {
    return vert;
}

int HalfEdge::getid() {
    return id;
}

Face* HalfEdge::getFace() {
    return face;
}

std::string HalfEdge::toString() {

   vert->printPos();


   return "halfedge " + std::to_string(id);


}

void HalfEdge::setFace(Face* newFace) {
    face = newFace;
}

HalfEdge* HalfEdge::getPrev() {
    HalfEdge* loop = next;
    while (loop->getNext() != this) {
        loop = loop->getNext();
    }

    return loop;
}

float HalfEdge::getSmoothedMidpoint() {
    glm::vec4 v1 = vert->getPos();
    glm::vec4 v2 = sym->getVert()->getPos();
    return 0;//for now


}

void HalfEdge::destroy()
{
    bufIdx.destroy();
    bufPos.destroy();
    bufNor.destroy();
    bufCol.destroy();
}

GLenum HalfEdge::drawMode()
{
    return GL_LINES;
}

int HalfEdge::elemCount()
{
    return 2;
}



bool HalfEdge::bindIdx()
{
    return bufIdx.bind();
}

bool HalfEdge::bindPos()
{
    return bufPos.bind();
}

bool HalfEdge::bindNor()
{
    return bufNor.bind();
}

bool HalfEdge::bindCol()
{
    return bufCol.bind();
}

