#ifndef RAY_H
#define RAY_H
#include <shaderprogram.h>

#include <shaderprogram.h>


#include <QOpenGLContext>
#include <QOpenGLBuffer>
#include <QOpenGLShaderProgram>
#include "scene/camera.h"
#include "la.h"



class Ray : public ShaderProgram::Drawable
{

private:
    int count;
    QOpenGLBuffer bufIdx;
    QOpenGLBuffer bufPos;
    QOpenGLBuffer bufNor;
    QOpenGLBuffer bufCol;


public:


    Ray();
    Ray(glm::vec4 eye, glm::vec4 d);
    ~Ray();


    glm::vec4 origin;
    glm::vec4 direction;


    void create();
    void destroy();

    glm::vec4 getOrigin();
    glm::vec4 getDirection();

    virtual GLenum drawMode();
    virtual int elemCount();
    virtual bool bindIdx();
    virtual bool bindPos();
    virtual bool bindNor();
    virtual bool bindCol();

};


glm::vec4 intersectCube(const Ray& r, const glm::mat4& transform);

glm::vec4 intersectCylinder(const Ray& r, const glm::mat4& transform);

glm::vec4 intersectSphere(const Ray& r, const glm::mat4& transform, Camera* c);

//float intersectOctNode(const Ray& r, Octnode& octroot);


/// Prints the ray to a stream in a nice format
std::ostream &operator<<(std::ostream &o, const Ray &r);


#endif // RAY_H
