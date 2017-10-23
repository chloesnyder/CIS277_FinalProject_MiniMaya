#ifndef MESH_H
#define MESH_H

#pragma once

#include "la.h"
#include "face.h"

#include <shaderprogram.h>

#include <QOpenGLContext>
#include <QOpenGLBuffer>
#include <QOpenGLShaderProgram>
#include <QMap>

#include <QListWidgetItem>
#include <QString>

class Mesh : public ShaderProgram::Drawable, public QListWidgetItem
{
private:
    QList<Face*> faces;
    QList<Vertex*> vertexList;
    QList<HalfEdge*> halfEdgeList;

    QMap<Face*, glm::vec4> faceCentroids;


    int faceID;
    int count;

    QOpenGLBuffer bufIdx;
    QOpenGLBuffer bufPos;
    QOpenGLBuffer bufNor;
    QOpenGLBuffer bufCol;//Can be used to pass per-vertex color information to the shader, but is currently unused.

    QOpenGLBuffer bufJointIDs;
    QOpenGLBuffer bufWeights;


    QMap<Face*, glm::vec4> centroidFaces;
    bool isBound = false;

    int meshID;
    QString name;




public:
    static int max_mesh_id;

    Mesh();
    Mesh(QList<Face*> faces, QList<Vertex*> vertexList, QList<HalfEdge*> halfEdgeList);
    Mesh(Mesh const &m);
    QList<HalfEdge *> &getMeshHalfEdges();
    QList<Vertex*> &getMeshVertices();
    QList<Face*> &getMeshFaces();

    std::vector<glm::ivec2> allJointIDsForBuffer;
    std::vector<glm::vec2> allJointWeightsForBuffer;

    float reflectivity;
    float transparency;
    float refractive_index;
    float specularity;

    void setName(int i);

    void setBoundTrue();
    bool hasBeenBound();

    void makeSquarePlane();
    void makeCube();
    void removeFaceFromList(Face * f);
    void removeVertexFromList(Vertex* v);
    void removeHalfEdgeFromList(HalfEdge* e);

    void addHalfEdge(HalfEdge* e);
    void extrudeFace(HalfEdge* start, glm::vec4 direction);
    void extrudeEdge(HalfEdge* e);
    void bevelEdge(HalfEdge* e);

    Vertex* addVertex(HalfEdge* selected);
    void triangulate(Face* f, HalfEdge* startEdge);

    //calculate face-to-centroid list
    QMap<Face*, glm::vec4> getMeshCentroids();

    Vertex* addMidPoint(HalfEdge* selected, glm::vec4 midPos, QList<HalfEdge*> &allEdgesWithMidPoints);

    //quadrangulate all faces of mesh
    void quadrangulateFaces(QMap<Face*, glm::vec4> centroidsOfFaces, QList<HalfEdge*> midpointEdges);

    void discoMesh(QMap<Face*, glm::vec4> centroidsOfFaces, QList<HalfEdge*> midpointEdges);

    void create();
    void destroy();

    virtual GLenum drawMode();
    virtual int elemCount();
    virtual bool bindIdx();
    virtual bool bindPos();
    virtual bool bindNor();
    virtual bool bindCol();
    virtual bool bindWeights();
    virtual bool bindJointIDs();
};


glm::vec4 cross(glm::vec4 v1, glm::vec4 v2);

#endif // MESH_H
