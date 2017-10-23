#ifndef HALFEDGE_H
#define HALFEDGE_H
#include "la.h"
#include "face.h"
#include "vertex.h"
#include <iostream>

#include <QListWidgetItem>
#include <QString>

#include "shaderprogram.h"
#include <QOpenGLContext>
#include <QOpenGLBuffer>
#include <QOpenGLShaderProgram>

class Face;

class HalfEdge : public QListWidgetItem, public ShaderProgram::Drawable
{
private:
    Face* face;
    Vertex* vert;
    QString name;
    int id;

    QOpenGLBuffer bufIdx;
    QOpenGLBuffer bufPos;
    QOpenGLBuffer bufNor;
    QOpenGLBuffer bufCol;


public:

    HalfEdge* next;
    HalfEdge* sym;

    HalfEdge();
    HalfEdge(HalfEdge*h);
    HalfEdge(Face* face, Vertex* vert, HalfEdge* next, HalfEdge* sym, int id);

    Vertex* getVert();

    HalfEdge* getNext();
    void setNext(HalfEdge* n);

    HalfEdge* getSym();
    void setSym(Face* f, Vertex* v, HalfEdge* n, HalfEdge* s, int i);
    void setSym(HalfEdge* e);
    std::string toString();
    int getid();
    void setVert(Vertex* v);

    Face* getFace();
    void setFace(Face * newFace);

    HalfEdge* getPrev();

    //subdivision functions
    float getSmoothedMidpoint();

    //drawable functions
    void create();
    void destroy();

    virtual GLenum drawMode();

    virtual int elemCount();
    virtual bool bindIdx();
    virtual bool bindPos();
    virtual bool bindNor();
    virtual bool bindCol();


};

#endif // HALFEDGE_H
