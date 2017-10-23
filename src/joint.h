#ifndef JOINT_H
#define JOINT_H

#include "shaderprogram.h"
#include <QTreeWidgetItem>

#include "la.h"
#include <iostream>

#include "frame.h"

class Joint : public QTreeWidgetItem, public ShaderProgram::Drawable
{

private:
    QString name;
    Joint* parent;
    QList<Joint*> children;

    //local translation
    glm::vec4 pos;
    //local rotation
    glm::quat ro;

    //concatenated transformation
    glm::mat4 overallTransformation;
    //aaanad its inverse
    glm::mat4 bindmat;

    glm::vec4 highlightColor = glm::vec4(1, 1, 1, 1);
    bool isSelected = false;

    int id;

    //for keyframing
    QMap<int, Frame*> keyframes;


    //for drawability
    int count;
    QOpenGLBuffer bufIdx;
    QOpenGLBuffer bufPos;
    QOpenGLBuffer bufNor;
    QOpenGLBuffer bufCol;
public:
    Joint();
    Joint(QString nme, Joint* prnt, glm::vec4 ps, glm::quat rt, int i);
    ~Joint();

    void setOverallTransformation(glm::mat4 T);
    glm::mat4 getLocalTransformation();
    glm::mat4 getOverallTransformation();

    void setBindMatrix();
    glm::mat4 getBindMatrix();
    glm::vec4 getPos();
    glm::vec4 getParentPos();
    void setParent(Joint* p);
    void addChild(Joint* ch);

    void setColor(glm::vec4 newColor);
    void toggleSelectedness();

    void updatePosition(glm::vec4 newPos);
    glm::quat getRotation();
    void setRotation(glm::quat newRo);


    int getNextKeyframeTime(int frameTime);
    int getPrevKeyframeTime(int frameTime);

    QString getName();

    QList<Joint*> getChildren();
    void getAllDescendants(QList<Joint*>& descendants);

    int getID();
    glm::vec4 lerpVecs(glm::vec4 a, glm::vec4 b, float t);
    glm::vec4 cubicSpline(glm::vec4 a, glm::vec4 b, glm::vec4 c, glm::vec4 d, float t);

    //for keyframing
    //void addNewKeyframe(glm::vec4 newPos, glm::quat newRo, int frameTime);
    void addNewKeyframe(int frameTime);
    QList<Frame*> getKeyframes();
    bool hasKeyframe(Frame * f);
    bool hasKeyframeTime(int time);
    //glm::mat4 getSQUAD();

    glm::mat4 getKeyframeTransformation(int time);
    glm::mat4 getTransformationAtFrame(int curTime);

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

void printableMatrix(glm::mat4);

#endif // JOINT_H
