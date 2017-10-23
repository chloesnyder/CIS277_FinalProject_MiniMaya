#include "shaderprogram.h"
#include <la.h>
#include <iostream>
#include "joint.h"


void ShaderProgram::create(const char *vertfile, const char *fragfile)
{
    prog.addShaderFromSourceFile(QOpenGLShader::Vertex  , vertfile);
    prog.addShaderFromSourceFile(QOpenGLShader::Fragment, fragfile);
    prog.link();

    attrPos = prog.attributeLocation("vs_Pos");
    attrNor = prog.attributeLocation("vs_Nor");
    attrCol = prog.attributeLocation("vs_Col");
    unifModel      = prog.uniformLocation("u_Model");
    unifModelInvTr = prog.uniformLocation("u_ModelInvTr");
    unifViewProj   = prog.uniformLocation("u_ViewProj");

    attrWeights = prog.attributeLocation("weights");
    attrJointIDs = prog.attributeLocation("jointIDs");
    unifBindMats = prog.uniformLocation("bindmats");
    unifJMats = prog.uniformLocation("jmats");

}


void ShaderProgram::createBinds() {

    attrWeights = prog.attributeLocation("weights");
    attrJointIDs = prog.attributeLocation("jointIDs");
    unifBindMats = prog.uniformLocation("bindmats");
    unifJMats = prog.uniformLocation("jmats");

}

void ShaderProgram::setModelMatrix(const glm::mat4 &model)
{
    prog.bind();

    if (unifModel != -1) {
        prog.setUniformValue(unifModel, la::to_qmat(model));
    }

    if (unifModelInvTr != -1) {
        glm::mat4 modelinvtr = glm::transpose(model);
        modelinvtr = glm::inverse(glm::transpose(model));
        prog.setUniformValue(unifModelInvTr, la::to_qmat(modelinvtr));
    }
}

void ShaderProgram::setViewProjMatrix(const glm::mat4& vp)
{
    prog.bind();

    if(unifViewProj != -1){
        prog.setUniformValue(unifViewProj, la::to_qmat(vp));
    }
}


void ShaderProgram::setBindMatrices(const QList<glm::mat4>& bm) {
    prog.bind();

    //create a mat4 array
    QMatrix4x4* bmats = new QMatrix4x4[bm.size()];


    for (int i = 0; i < bm.size(); i++) {
        bmats[i] = la::to_qmat(bm.at(i));
    }

    //send it off
    if (unifBindMats != -1) {
         prog.setUniformValueArray(unifBindMats, bmats, bm.size());
    }
}

void ShaderProgram::setJointMatrices(const QList<glm::mat4>& jm) {
    prog.bind();

    QMatrix4x4* jmatrices = new QMatrix4x4[jm.size()];

    for (int i = 0; i < jm.size(); i++) {

        jmatrices[i] = la::to_qmat(jm.at(i));
    }


    if (unifJMats != -1) {
        prog.setUniformValueArray(unifJMats, jmatrices, jm.size());
    }
}

// This function, as its name implies, uses the passed in GL widget
void ShaderProgram::draw(GLWidget277 &f, Drawable &d)
{
    prog.bind();

    // Each of the following blocks checks that:
    //   * This shader has this attribute, and
    //   * This Drawable has a vertex buffer for this attribute.
    // If so, it binds the appropriate buffers to each attribute.

    bool b = false;
    if (attrPos != -1 && (b = d.bindPos())) {
        prog.enableAttributeArray(attrPos);
        f.glVertexAttribPointer(attrPos, 4, GL_FLOAT, false, 0, NULL);
    }

    if (attrNor != -1 && (b = d.bindNor())) {
        prog.enableAttributeArray(attrNor);
        f.glVertexAttribPointer(attrNor, 4, GL_FLOAT, false, 0, NULL);
    }

    if (attrCol != -1 && (b = d.bindCol())) {
        prog.enableAttributeArray(attrCol);
        f.glVertexAttribPointer(attrCol, 4, GL_FLOAT, false, 0, NULL);
    }


    if (attrWeights != -1 && (b = d.bindWeights())) {
        prog.enableAttributeArray(attrWeights);
        f.glVertexAttribPointer(attrWeights, 2, GL_FLOAT, false, 0, NULL);
    }


    if (attrJointIDs != -1 && (b = d.bindJointIDs())) {
        prog.enableAttributeArray(attrJointIDs);
        f.glVertexAttribIPointer(attrJointIDs, 2, GL_INT, 0, NULL);
    }
    // Bind the index buffer and then draw shapes from it.
    // This invokes the shader program, which accesses the vertex buffers.
    d.bindIdx();
    f.glDrawElements(d.drawMode(), d.elemCount(), GL_UNSIGNED_INT, 0);

    if (attrPos != -1) prog.disableAttributeArray(attrPos);
    if (attrNor != -1) prog.disableAttributeArray(attrNor);
    if (attrCol!= -1) prog.disableAttributeArray(attrCol);
    if (attrWeights!= -1) prog.disableAttributeArray(attrWeights);
    if (attrJointIDs!= -1) prog.disableAttributeArray(attrJointIDs);

    f.printGLErrorLog();
}


bool ShaderProgram::Drawable::bindWeights() {
    return 0;

}
bool ShaderProgram::Drawable::bindJointIDs() {
    return 0;
}
