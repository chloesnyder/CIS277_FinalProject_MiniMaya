#ifndef FACE_H
#define FACE_H

#include "la.h"
#include "halfedge.h"

#include <QListWidgetItem>
#include <QString>

#include "shaderprogram.h"
#include <QOpenGLContext>
#include <QOpenGLBuffer>
#include <QOpenGLShaderProgram>

class HalfEdge;

class Face : public QListWidgetItem, public ShaderProgram::Drawable
{
private:

    HalfEdge* start_edge;
    glm::vec4 face_color;
    int id;


    int count;

    QOpenGLBuffer bufIdx;
    QOpenGLBuffer bufPos;
    QOpenGLBuffer bufNor;
    QOpenGLBuffer bufCol;


public:

    Face(int i);
    Face(Face* f);
    //Face(HalfEdge* s);
    HalfEdge* getStartEdge();
    void setStartEdge(HalfEdge* s);
    int getid();

    glm::vec4 getColor();
    void setColor(glm::vec4 col);
    void setColor(int newColVal, int RGB);
    void setColor(float newR, float newG, float newB, float tint);
    //catmull-clark subdivision stuff
    glm::vec4 calculateCentroid();

    void quadrangulate();

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

#endif // FACE_H
