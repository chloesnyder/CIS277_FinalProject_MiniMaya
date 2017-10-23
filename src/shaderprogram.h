#pragma once

#include <glwidget277.h>
#include <la.h>

#include <QOpenGLFunctions_3_2_Core>
#include <QOpenGLShaderProgram>
#include <QOpenGLBuffer>


class ShaderProgram
{
public:
    // This defines a class which can be rendered by our shader program.
    // Make any geometry a subclass of ShaderProgram::Drawable in order to render it with the ShaderProgram class.
    class Drawable
    {
    public:
        virtual GLenum drawMode() = 0;
        virtual int elemCount() = 0;
        virtual bool bindIdx() = 0;
        virtual bool bindPos() = 0;
        virtual bool bindNor() = 0;
        virtual bool bindCol() = 0;
        virtual bool bindWeights(); //returning false by default
        virtual bool bindJointIDs();
    };

public:
    QOpenGLShaderProgram prog;

    int attrPos;
    int attrNor;
    int attrCol;

    int unifModel;
    int unifModelInvTr;
    int unifViewProj;
    int unifColor;


    int attrWeights;
    int attrJointIDs;
    int unifBindMats;
    int unifJMats;

public:
    void create(const char *vertfile, const char *fragfile);
    void createBinds();
    void setModelMatrix(const glm::mat4 &model);
    void setViewProjMatrix(const glm::mat4& vp);
    void draw(GLWidget277 &f, Drawable &d);

    void setBindMatrices(const QList<glm::mat4>& bm);
    void setJointMatrices(const QList<glm::mat4>& jm);
};
