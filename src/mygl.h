#pragma once

#include <QOpenGLVertexArrayObject>
#include <QOpenGLShaderProgram>

#include <glwidget277.h>
#include <la.h>
#include <shaderprogram.h>
#include <scene/cylinder.h>
#include <scene/sphere.h>
#include <scene/camera.h>
#include <la.h>
#include <iostream>
#include "mesh.h"
#include "joint.h"
#include <QFile>
#include <QTreeWidget>
#include <QTreeWidgetItem>

#include <include/bmp/EasyBMP.h>
#include "ray.h"

#include <QListWidgetItem>

#include <QVariant>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>


#include <la.h>


#include <iostream>
#include <QApplication>
#include <QKeyEvent>
#include <QList>
#include <QFileDialog>


#include <stdlib.h>
#include <cstdlib>

#include <tbb/tbb.h>
#include <tbb/parallel_for.h>
#include <tbb/blocked_range.h>


using namespace glm;
class MyGL
    : public GLWidget277
{
    Q_OBJECT
private:
    QOpenGLVertexArrayObject vao;

    Cylinder geom_cylinder;
    Sphere geom_sphere;

    QList<Mesh*> allMeshes;
    QList<Frame*> allFrames;

    ShaderProgram prog_lambert;
    ShaderProgram prog_wire;
    ShaderProgram prog_skel;
    HalfEdge* selectedHalfEdge;
    Vertex* selectedVertex;
    Face* selectedFace;
    Joint* jroot;
    Joint* selectedJoint;
    int jointCount;
    int numFrames;
    int curFrameTime;

    bool needCowVertices;

    bool disableUpdate;

    QList<glm::mat4> jointMatsForShaderProg;
    QList<glm::mat4> bindMatsForShaderProg;

    Ray ray;
    Camera camera;

    float u_shininess;

    Mesh* selectedMesh;

public:

    vec4 AccLightSource(Face* f, Ray &r, vec4 light_pos, QList<Mesh*>& meshes, vec4 normal, float t1);

    QList<QList<Vertex *> > triangulateFaceForRayTrace(Face* f);

    bool mousePressed = false;
    int mouse_xi;
    int mouse_yi;
    int mouse_xf;
    int mouse_yf;

    int max_mesh_id;

    explicit MyGL(QWidget *parent = 0);
    ~MyGL();

    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();

    float area(glm::vec4 a, glm::vec4 b, glm::vec4 c);

    float intersectTriangle(Ray r, QList<Vertex *> verts);

    vec4 raytrace(Ray& r, QList<Mesh *> &meshes, int depth);

    //read in joint data
    Joint* readJoints(Joint* parent, QJsonObject jobj);

    glm::mat4 getSQUAD();
    std::vector<std::vector<vec3>> color_array;

    bool playingFromTimeline;

    bool isInEdgeLoop(Vertex* v);

    bool meshHasBeenImported = false;
public slots:
    void slot_ReceiveSelectedHalfEdge(QListWidgetItem* half_edge);
    void slot_ReceiveSelectedVertex(QListWidgetItem* vertex);
    void slot_ReceiveSelectedFace(QListWidgetItem* face);
    void slot_AddVertex();

    void slot_updateVertX(double dx);
    void slot_updateVertY(double dy);
    void slot_updateVertZ(double dz);

    void slot_triangulateFace();
    void slot_deleteVertex();

    void slot_updateR(int R);
    void slot_updateG(int G);
    void slot_updateB(int B);


    void slot_shiftToBarycenter();
    void slot_quadrangulate();
    void slot_showSym();
    void slot_showNext();

    void slot_showSelectedHalfEdgeFace();
    void slot_smoothMesh();
    void slot_discoTime();
    void slot_showEdge();
    void slot_showStartEdge();
    void slot_showVertexFace();

    void slot_importObjFile();
    void slot_exportObjFile();
    void slot_setDisplayCowVertices();

    //keyframe stuff
    void slot_receiveNumFrames(int i);
    void slot_createFrameTimeline();

    //joint stuff
    void slot_importJSONFile();
    void traverseJoints(Joint * joint, glm::mat4 T);
    void slot_calculateBindMatrices();

    void slot_receiveSelectedJoint(QTreeWidgetItem* joint, int);

    void slot_updateJointX(double jx);
    void slot_updateJointY(double jy);
    void slot_updateJointZ(double jz);

    void slot_updateJointRoX(double rx);
    void slot_updateJointRoY(double ry);
    void slot_updateJointRoZ(double rz);

    Ray Raycast(float x, float y);
    void slot_exportBMP();

    void slot_createNewKeyFrame();
    void slot_receiveSelectedFrame(QListWidgetItem* curFrame);

    void slot_updateRefraction(double r);
    void slot_updateReflection(double r);

    void slot_selectMesh(QListWidgetItem* mesh);
    void slot_insertEdgeLoop();

    void slot_meshTranslateX(double x);
    void slot_meshTranslateY(double y);
    void slot_meshTranslateZ(double z);
//    void slot_meshRotateX(double x);
//    void slot_meshRotateY(double y);
//    void slot_meshRotateZ(double z);
    void slot_meshScaleX(double x);
    void slot_meshScaleY(double y);
    void slot_meshScaleZ(double z);

    void slot_extrudeFace();
    void slot_extrudeEdge();



signals:
    void sig_SendHalfEdge(QListWidgetItem* half_edge);
    void sig_SendVertex(QListWidgetItem* vertex);
    void sig_SendFace(QListWidgetItem* face);

    void sig_ResetSpinBoxX(double curX);
    void sig_ResetSpinBoxY(double curY);
    void sig_ResetSpinBoxZ(double curZ);

    void sig_ResetR(int R);
    void sig_ResetG(int G);
    void sig_ResetB(int B);

    void sig_sendNewlySelectedFace(QListWidgetItem* face);
    void sig_restartFaces();
    void sig_sendNewlySelectedHalfEdge(QListWidgetItem* halfedge);

    void sig_sendListOfFaces(QList<QListWidgetItem*> facesList);

    void sig_sendRootJoint(QTreeWidgetItem* root);

    void sig_sendJointX(double jx);
    void sig_sendJointY(double jy);
    void sig_sendJointZ(double jz);

    void sig_sendJointRoX(double roX);
    void sig_sendJointRoY(double roY);
    void sig_sendJointRoZ(double roZ);

    void sig_makeNewTimeline();
    void sig_sendFrame(QListWidgetItem* frame);

    void sig_sendMesh(QListWidgetItem* m);


protected:
    void keyPressEvent(QKeyEvent *e);
    void mousePressEvent(QMouseEvent *e);
};


glm::vec4 listAverage(QList<glm::vec4> vectorList);
