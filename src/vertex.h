#ifndef VERTEX_H
#define VERTEX_H

#include <QListWidgetItem>
#include <QString>
#include "la.h"
#include "joint.h"


#include <stdio.h>
#include <math.h>

#include "shaderprogram.h"
#include <QOpenGLContext>
#include <QOpenGLBuffer>
#include <QOpenGLShaderProgram>

class HalfEdge;


class Vertex : public QListWidgetItem, public ShaderProgram::Drawable
{
private:
    glm::vec4 pos;
    HalfEdge* edge;
    int id;
    QString name;

    std::vector<float> jointWeights;
    std::vector<int> jointIDs;

    QOpenGLBuffer bufIdx;
    QOpenGLBuffer bufPos;
    QOpenGLBuffer bufNor;
    QOpenGLBuffer bufCol;

    //don't need these no mo because in scope of mesh
    //QOpenGLBuffer bufJointIDs;
    //QOpenGLBuffer bufWeights;


    glm::ivec2 jointIDsForBuffer;
    glm::vec2 jointWeightsForBuffer;

public:
    Vertex();
    Vertex(glm::vec4 pos,int id);
    Vertex(Vertex* v);

    int getid();

    //catmull clark stuff
    glm::vec4& getPos();
    std::string printPos();
    void setPos(glm::vec4 newPos);
    void updateID(int newID);
    HalfEdge* getEdge();
    void setEdge(HalfEdge* e);
    bool noFacesLeft();
    void shiftToBarycenter();

    void createJointBinds();




    //joints stuff
    void setClosestJoints(QList<Joint*> allJoints);
    glm::ivec2 getJointIDsForBuffer();
    glm::vec2 getJointWeightsForBuffer();


    //drawable functions
    void create();
    void destroy();

    virtual GLenum drawMode();

    virtual int elemCount();
    virtual bool bindIdx();
    virtual bool bindPos();
    virtual bool bindNor();
    virtual bool bindCol();
    //virtual bool bindWeights();
    //virtual bool bindJointIDs();
};

#endif // VERTEX_H
