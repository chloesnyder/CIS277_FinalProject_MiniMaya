#include "mygl.h"
#include "easybmp.h"
#include <cmath>

#include "QtDebug"
using namespace tbb;

MyGL::MyGL(QWidget *parent)
    : GLWidget277(parent)
{
    setFocusPolicy(Qt::ClickFocus);
}

MyGL::~MyGL()
{
    makeCurrent();

    vao.destroy();
    geom_cylinder.destroy();
    geom_sphere.destroy();

}

void MyGL::initializeGL()
{


    // Create an OpenGL context
    initializeOpenGLFunctions();
    // Print out some information about the current OpenGL context
    debugContextVersion();

    // Set a few settings/modes in OpenGL rendering
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LINE_SMOOTH);
    glEnable(GL_POLYGON_SMOOTH);
    glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
    glHint(GL_POLYGON_SMOOTH_HINT, GL_NICEST);
    // Set the size with which points should be rendered
    glPointSize(5);
    // Set the color with which the screen is filled at the start of each render call.
    glClearColor(0.5, 0.5, 0.5, 1);

    printGLErrorLog();

    // Create a Vertex Attribute Object
    vao.create();

    // Create the example sphere (you should delete this when you add your own code elsewhere)
    geom_cylinder.create();

    geom_sphere.create();

    ray.create();

    //    Mesh* mesh = new Mesh();


    //  mesh->makeCube();
    //  mesh->create();

    //   this->allMeshes.append(mesh);
    // Create and set up the diffuse shader
    prog_lambert.create(":/glsl/lambert.vert.glsl", ":/glsl/lambert.frag.glsl");
    // Create and set up the wireframe shader
    prog_wire.create(":/glsl/wire.vert.glsl", ":/glsl/wire.frag.glsl");

    //Create and set up the skeleton-based shader
    //check to make sure this actually worked?
    prog_skel.create(":/glsl/skeleton.vert.glsl", ":/glsl/skeleton.frag.glsl");



    // We have to have a VAO bound in OpenGL 3.2 Core. But if we're not
    // using multiple VAOs, we can just bind one once.
    vao.bind();

    //initialize to something otherwise just a garbage pointer
    selectedHalfEdge = NULL;
    selectedVertex = NULL;
    selectedFace = NULL;
    jroot = NULL;
    selectedJoint = NULL;
    jointCount = 0;


    if(!allMeshes.empty()) {
        for (HalfEdge* e : allMeshes[allMeshes.size() - 1]->getMeshHalfEdges()) {

            emit sig_SendHalfEdge(e);
        }

        for (Vertex* v : allMeshes[allMeshes.size() - 1]->getMeshVertices()) {

            emit sig_SendVertex(v);
        }


        for (Face* f : allMeshes[allMeshes.size() - 1]->getMeshFaces()) {

            emit sig_SendFace(f);
        }
    }
}

void MyGL::resizeGL(int w, int h)
{
    camera = Camera(w, h);

    glm::mat4 viewproj = camera.getViewProj();

    // Upload the projection matrix
    prog_lambert.setViewProjMatrix(viewproj);
    prog_wire.setViewProjMatrix(viewproj);
    prog_skel.setViewProjMatrix(viewproj);

    printGLErrorLog();
}

// This function is called by Qt any time your GL window is supposed to update
// For example, when the function updateGL is called, paintGL is called implicitly.
void MyGL::paintGL()
{
    // Clear the screen so that we only see newly drawn images
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Update the viewproj matrix
    prog_lambert.setViewProjMatrix(camera.getViewProj());
    prog_wire.setViewProjMatrix(camera.getViewProj());
    prog_skel.setViewProjMatrix(camera.getViewProj());

    // Sphere
    glm::mat4 model = glm::translate(glm::mat4(1.0f), glm::vec3(-2, 0, 0)) * glm::scale(glm::mat4(1.0f), glm::vec3(3, 3, 3));
    // prog_lambert.setModelMatrix(model);
    // prog_lambert.draw(*this, geom_sphere);
    // Cylinder
    model = glm::translate(glm::mat4(1.0f), glm::vec3(2, 2, 0)) * glm::rotate(glm::mat4(1.0f), -45.0f, glm::vec3(0, 0, 1));
    // prog_lambert.setModelMatrix(model);
    //prog_lambert.draw(*this, geom_cylinder);

    prog_wire.setModelMatrix(glm::mat4(1.0));
    prog_wire.draw(*this, ray);

    if(!allMeshes.empty()) {
        if (allMeshes[allMeshes.size() - 1]->hasBeenBound()) {




            prog_skel.setModelMatrix(glm::mat4(1.0f));
            prog_skel.setBindMatrices(bindMatsForShaderProg);
            prog_skel.setJointMatrices(jointMatsForShaderProg);
            //  prog_skel.draw(*this, allMeshes[allMeshes.size() - 1]);
            for(Mesh* m : allMeshes) {
                //  m->create();
                prog_skel.draw(*this, *m);
            }




            glDisable(GL_DEPTH_TEST);
            if (selectedHalfEdge != NULL) {
                prog_skel.draw(*this, *selectedHalfEdge);
            }
            if (selectedVertex != NULL) {
                prog_skel.draw(*this, *selectedVertex);
            }
            if (selectedFace!= NULL) {
                prog_skel.draw(*this, *selectedFace);
            }
            if (jroot != NULL) {
                traverseJoints(jroot, glm::mat4());
            }

            glEnable(GL_DEPTH_TEST);
        }

        else {
            prog_lambert.setModelMatrix(glm::mat4(1.0f));
            // prog_lambert.draw(*this, allMeshes[allMeshes.size() - 1]);
            for(Mesh* m : allMeshes) {
                //m->create();
                prog_lambert.draw(*this, *m);
            }

            glDisable(GL_DEPTH_TEST);
            if (selectedHalfEdge != NULL) {
                prog_lambert.draw(*this, *selectedHalfEdge);
            }
            if (selectedVertex != NULL) {
                prog_lambert.draw(*this, *selectedVertex);
            }
            if (selectedFace!= NULL) {
                prog_lambert.draw(*this, *selectedFace);
            }
            if (jroot != NULL) {

                traverseJoints(jroot, glm::mat4());
            }

            glEnable(GL_DEPTH_TEST);
        }

    }

    for(Mesh* m : allMeshes) {
        emit sig_sendMesh(m);
    }
}

void MyGL::keyPressEvent(QKeyEvent *e)
{
    // http://doc.qt.io/qt-5/qt.html#Key-enum
    if (e->key() == Qt::Key_Escape) {
        QApplication::quit();
    } else if (e->key() == Qt::Key_Right) {
        camera.theta += 5.0f * DEG2RAD;
    } else if (e->key() == Qt::Key_Left) {
        camera.theta -= 5.0f * DEG2RAD;
    } else if (e->key() == Qt::Key_Up) {
        camera.phi -= 5.0f * DEG2RAD;
    } else if (e->key() == Qt::Key_Down) {
        camera.phi += 5.0f * DEG2RAD;
    } else if (e->key() == Qt::Key_I) {
        camera.zoom -= 0.5f;
    } else if (e->key() == Qt::Key_O) {
        camera.zoom += 0.5f;
    } else if (e->key() == Qt::Key_1) {
        camera.fovy += 5.0f * DEG2RAD;
    } else if (e->key() == Qt::Key_2) {
        camera.fovy -= 5.0f * DEG2RAD;
    }
    camera.RecomputeEye();
    update();  // Calls paintGL, among other things
}

///When press mouse, pass x and y position for first ray direction
void MyGL::mousePressEvent(QMouseEvent *e) {
    mousePressed = !mousePressed;
    setMouseTracking(true);
    mouse_xi = e->pos().x();
    mouse_yi = e->pos().y();

    ray = Raycast(mouse_xi, mouse_yi);
    ray.create();

}


void MyGL::slot_ReceiveSelectedHalfEdge(QListWidgetItem* half_edge) {
    selectedHalfEdge = (HalfEdge*) half_edge;


    selectedHalfEdge->create();



    update();
}

void MyGL::slot_showSym() {

    if (selectedHalfEdge != NULL) {
        selectedHalfEdge = selectedHalfEdge->getSym();
        selectedHalfEdge->create();
    }

    update();
}

void MyGL::slot_showNext() {

    if (selectedHalfEdge != NULL) {
        selectedHalfEdge = selectedHalfEdge->getNext();
        selectedHalfEdge->create();
    }


    update();

}

void MyGL::slot_ReceiveSelectedVertex(QListWidgetItem* vertex) {


    selectedVertex = (Vertex* ) vertex;


    emit sig_ResetSpinBoxX(selectedVertex->getPos()[0]);
    emit sig_ResetSpinBoxY(selectedVertex->getPos()[1]);
    emit sig_ResetSpinBoxZ(selectedVertex->getPos()[2]);

    selectedVertex->create();

    update();
}

void MyGL::slot_ReceiveSelectedFace(QListWidgetItem* face) {
    selectedFace = (Face* ) face;


    selectedFace->create();



    HalfEdge* e =selectedFace->getStartEdge()->getNext();


    while(e != selectedFace->getStartEdge()) {


        e= e->getNext();
    }



    update();



}

void MyGL::slot_AddVertex() {


    if (selectedHalfEdge == NULL) {
        return;
    }
    selectedVertex = allMeshes[allMeshes.size() - 1]->addVertex(selectedHalfEdge);


    prog_lambert.draw(*this, *selectedVertex);
    selectedHalfEdge = NULL;


    //update list widget
    for (HalfEdge* e : allMeshes[allMeshes.size() - 1]->getMeshHalfEdges()) {

        emit sig_SendHalfEdge(e);
    }

    for (Vertex* v : allMeshes[allMeshes.size() - 1]->getMeshVertices()) {

        emit sig_SendVertex(v);
    }


    for (Face* f : allMeshes[allMeshes.size() - 1]->getMeshFaces()) {

        emit sig_SendFace(f);
    }

    selectedVertex->create();
    //    mesh.create();

    update();
}

void MyGL::slot_updateVertX(double dx) {



    if (selectedVertex != NULL) {

        glm::vec4 curPos = selectedVertex->getPos();
        glm::vec4 newPos = glm::vec4(dx, curPos[1], curPos[2], 1);
        selectedVertex->setPos(newPos);

        selectedVertex->create();
        allMeshes[allMeshes.size() - 1]->create();

    }

    update();

}

void MyGL::slot_updateVertY(double dy) {

    if (selectedVertex != NULL) {

        glm::vec4 curPos = selectedVertex->getPos();
        glm::vec4 newPos = glm::vec4(curPos[0], dy, curPos[2], 1);
        selectedVertex->setPos(newPos);

        selectedVertex->create();
        allMeshes[allMeshes.size() - 1]->create();

    }

    update();

}

void MyGL::slot_updateVertZ(double dz) {
    if (selectedVertex != NULL) {

        glm::vec4 curPos = selectedVertex->getPos();
        glm::vec4 newPos = glm::vec4(curPos[0], curPos[1], dz, 1);
        selectedVertex->setPos(newPos);

        selectedVertex->create();
        allMeshes[allMeshes.size() - 1]->create();


    }



    update();

}

void MyGL::slot_triangulateFace() {
    if (selectedFace != NULL) {
        allMeshes[allMeshes.size() - 1]->triangulate(selectedFace, selectedFace->getStartEdge());

        selectedFace->create();
        allMeshes[allMeshes.size() - 1]->create();

    }

    for (Face* f : allMeshes[allMeshes.size() - 1]->getMeshFaces()) {

        emit sig_SendFace(f);
    }


    //mesh.getMeshCentroids();
    update();

}

void MyGL::slot_updateR(int R) {

    if (selectedFace != NULL) {

        selectedFace->setColor(R, 0);
    }
    allMeshes[allMeshes.size() - 1]->create();
    update();

}

void MyGL::slot_updateG(int G) {
    if (selectedFace != NULL) {

        selectedFace->setColor(G, 1);
    }

    allMeshes[allMeshes.size() - 1]->create();
    update();

}

void MyGL::slot_updateB(int B) {
    if (selectedFace != NULL) {

        selectedFace->setColor(B, 2);
    }

    allMeshes[allMeshes.size() - 1]->create();

    update();


}



void MyGL::slot_deleteVertex() {

    if (selectedVertex == NULL) {
        return;
    }

    if (selectedVertex->getEdge() == NULL) {
        std::cout << "i want nullbody nullbody but you " << std::endl;
    }





    //choose any halfedge entering v
    HalfEdge* e = selectedVertex->getEdge();
    Face* curFace = e->getFace();

    if (curFace == NULL) {

        curFace = e->getSym()->getFace();

    }


    //start with any face incident to vertex
    QList<Face*> incidentFaces;

    //collect all faces incident to vertex

    while (!incidentFaces.contains(curFace)) {
        incidentFaces.push_back (curFace);

        e = e->getNext();
        if (e->getSym()->getVert() == selectedVertex) {
            //move onto opposite face
            e = e->getSym();
            curFace = e->getFace();

        }
    }


    QList<HalfEdge*> edgesToDelete;


    //loop through all faces in incident faces to collect a list of edges to delete
    for (Face* f : incidentFaces) {


        HalfEdge* start = f->getStartEdge();


        HalfEdge* curEdge = start;
        while (curEdge->getNext() != start) {


            curEdge->setFace(NULL);

            if (curEdge->getSym()->getFace() == NULL) {


                edgesToDelete.push_back(curEdge);
            }


            curEdge = curEdge->getNext();

        }


        curEdge->setFace(NULL);

        if (curEdge->getSym()->getFace() == NULL) {



            edgesToDelete.push_back(curEdge);
        }


    }



    QList<Vertex*> verticesVisited;
    QList<HalfEdge*> edgesToDeletePlusSyms;

    //keep a list of the prev edges whose nexts need to be updated
    for (HalfEdge* e : edgesToDelete) {
        edgesToDeletePlusSyms.push_back(e);
        edgesToDeletePlusSyms.push_back(e->getSym());


    }



    QList<HalfEdge*> prevEdges;


    //traverse halfedges and sysm, setting their prev pointers
    for (HalfEdge* e : edgesToDeletePlusSyms) {

        //keep one copy of every vertex whose edges might be deleted
        if (!verticesVisited.contains(e->getVert())) {
            verticesVisited.push_back(e->getVert());
        }

        if (!edgesToDeletePlusSyms.contains(e->getPrev())) {
            //reset all neighboring vertices to have edges at the prevs
            HalfEdge* prev = e->getPrev();
            Vertex* vertToSet = e->getSym()->getVert();
            vertToSet->setEdge(prev);
            verticesVisited.erase(std::remove(verticesVisited.begin(), verticesVisited.end(), vertToSet), verticesVisited.end());
            prevEdges.push_back(e->getPrev());
        }

    }
    //set the nexts of the nondeleted edges
    QList<HalfEdge* > newNexts;
    for (HalfEdge * p : prevEdges) {

        newNexts.push_back(p->getNext()->getSym()->getNext());

    }
    //reset vertices not to delete by prev pointers
    for (int i = 0; i < prevEdges.size(); i++) {
        prevEdges.at(i)->setNext(newNexts.at(i));

        verticesVisited.erase(std::remove(verticesVisited.begin(), verticesVisited.end(), prevEdges.at(i)->getVert()), verticesVisited.end());
    }


    //delete edges to delete and their syms
    for (HalfEdge* toDelete : edgesToDeletePlusSyms) {
        allMeshes[allMeshes.size() - 1]->removeHalfEdgeFromList(toDelete);
        delete toDelete;
    }

    for (Face* faceToDelete : incidentFaces) {
        allMeshes[allMeshes.size() - 1]->removeFaceFromList(faceToDelete);
        delete faceToDelete;
    }

    for (Vertex* v : verticesVisited) {

        //delete vertices that have no more faces or edges pointing to them
        allMeshes[allMeshes.size() - 1]->removeVertexFromList(v);
        delete v;
    }


    allMeshes[allMeshes.size() - 1]->create();

    selectedVertex = NULL;
    selectedFace = NULL;

    update();
}

void MyGL::slot_smoothMesh() {

    //YOYOYO
    allMeshes[allMeshes.size() - 1]->destroy();


    //create a face-to-centroid map
    QMap<Face*, glm::vec4> centroidsOfFaces = allMeshes[allMeshes.size() - 1]->getMeshCentroids();


    //collect one halfedge for every edge in mesh
    QList<HalfEdge*> edgesToGiveMidPoints;
    for (HalfEdge* he : allMeshes[allMeshes.size() - 1]->getMeshHalfEdges() ) {
        if (!edgesToGiveMidPoints.contains(he->getSym())) {
            edgesToGiveMidPoints.push_back(he);
        }

    }

    /*std::cout << "edges to give midpoints" << std::endl;
    for (HalfEdge* hehe1 : edgesToGiveMidPoints) {
        std::cout << "edge hehe" << hehe1->getid() << " " << std::endl;
    }*/

    //make a copy of the original vertices
    QList<Vertex*> verticesToSmooth = allMeshes[allMeshes.size() - 1]->getMeshVertices();


    //calculate smoothed midpoints
    QList<glm::vec4> neighboringVertices;
    QList<HalfEdge*> allEdgesWithMidPoints;

    for (HalfEdge* hehe : edgesToGiveMidPoints) {

        //v1
        neighboringVertices.push_back(hehe->getVert()->getPos());

        //v2
        neighboringVertices.push_back(hehe->getSym()->getVert()->getPos());

        if (hehe->getFace() != NULL) {
            //f1
            neighboringVertices.push_back(centroidsOfFaces[hehe->getFace()]);
        }

        if (hehe->getSym()->getFace() != NULL) {
            //f2
            neighboringVertices.push_back(centroidsOfFaces[hehe->getSym()->getFace()]);
        }



        selectedVertex = allMeshes[allMeshes.size() - 1]->addMidPoint(hehe, listAverage(neighboringVertices), allEdgesWithMidPoints);
        selectedVertex->create();

        neighboringVertices.clear();
    }



    //shiftToBarycenter

    for (Vertex* curVert : verticesToSmooth) {

        HalfEdge* curEdge = curVert->getEdge();
        Face* curFace = curEdge->getFace();

        if (curFace == NULL) {

            curFace = curEdge->getSym()->getFace();

        }

        //traverse to find all adjacent midpoints and incident faces
        QList<Vertex*> adjacentMidpoints;
        QList<Face*> incidentFaces;


        while (!incidentFaces.contains(curFace)) {
            incidentFaces.push_back (curFace);
            adjacentMidpoints.push_back(curEdge->getSym()->getVert());

            curEdge = curEdge->getNext();
            if (curEdge->getSym()->getVert() == curVert) {
                //move onto opposite face
                curEdge = curEdge->getSym();
                curFace = curEdge->getFace();

            }
        }



        glm::vec4 sume = glm::vec4(0.f);
        for (Vertex* adj : adjacentMidpoints) {
            sume += adj->getPos();
        }
        float n = adjacentMidpoints.size();
        float nsq = glm::pow(n, 2);

        //sum of all incident face centroids
        glm::vec4 sumf = glm::vec4(0.0);
        for (Face* face : incidentFaces) {
            sumf+= centroidsOfFaces[face];
        }




        glm::vec4 oldPos = curVert->getPos();

        glm::vec4 newPos = ((n - 2) * oldPos/n)  + sume/nsq + sumf/nsq;

        curVert->setPos(newPos);

        incidentFaces.clear();


        adjacentMidpoints.clear();
    }



    //quadrangulate faces

    //create list of midpoints
    allMeshes[allMeshes.size() - 1]->quadrangulateFaces(centroidsOfFaces, allEdgesWithMidPoints);




    allMeshes[allMeshes.size() - 1]->create();






    prog_lambert.draw(*this, *selectedVertex);
    selectedHalfEdge = NULL;
    selectedFace = NULL;



    //update list widget
    for (HalfEdge* ed : allMeshes[allMeshes.size() - 1]->getMeshHalfEdges()) {
        emit sig_SendHalfEdge(ed);
    }

    for (Vertex* ve : allMeshes[allMeshes.size() - 1]->getMeshVertices()) {

        emit sig_SendVertex(ve);
    }


    for (Face* f : allMeshes[allMeshes.size() - 1]->getMeshFaces()) {
        emit sig_SendFace(f);
    }






    update();




}

void MyGL::slot_showSelectedHalfEdgeFace() {
    if (selectedHalfEdge == NULL) {
        return;
    }

    selectedFace = selectedHalfEdge->getFace();
    selectedFace->create();

    emit sig_sendNewlySelectedFace(selectedFace);

    update();
}

void MyGL::slot_shiftToBarycenter() {


    if (selectedVertex == NULL) {
        return;
    }

    selectedVertex->shiftToBarycenter();

    selectedVertex->create();
    allMeshes[allMeshes.size() - 1]->create();
    update();
}

//quadrangulate faces with given
void MyGL::slot_quadrangulate() {

    allMeshes[allMeshes.size() - 1]->destroy();


    //create a face-to-centroid map
    QMap<Face*, glm::vec4> centroidsOfFaces = allMeshes[allMeshes.size() - 1]->getMeshCentroids();


    //collect one halfedge for every edge in mesh
    QList<HalfEdge*> edgesToGiveMidPoints;
    for (HalfEdge* he : allMeshes[allMeshes.size() - 1]->getMeshHalfEdges() ) {
        if (!edgesToGiveMidPoints.contains(he->getSym())) {
            edgesToGiveMidPoints.push_back(he);
        }

    }
    std::cout << "edges to give midpoints" << allMeshes[allMeshes.size() - 1]->getMeshHalfEdges().size()
              << std::endl <<
                 edgesToGiveMidPoints.size() << std::endl;

    //calculate smoothed midpoints for each edge
    QList<glm::vec4> neighboringVertices;

    QList<HalfEdge*> allEdgesWithMidPoints;
    for (HalfEdge* hehe : edgesToGiveMidPoints) {

        //v1
        neighboringVertices.push_back(hehe->getVert()->getPos());

        //v2
        neighboringVertices.push_back(hehe->getSym()->getVert()->getPos());

        if (hehe->getFace() != NULL) {
            //f1
            neighboringVertices.push_back(centroidsOfFaces[hehe->getFace()]);
        }

        if (hehe->getSym()->getFace() != NULL) {
            //f2
            neighboringVertices.push_back(centroidsOfFaces[hehe->getSym()->getFace()]);
        }



        selectedVertex = allMeshes[allMeshes.size() - 1]->addMidPoint(hehe, listAverage(neighboringVertices), allEdgesWithMidPoints);
        selectedVertex->create();

        neighboringVertices.clear();
    }

    //create list of midpoints
    allMeshes[allMeshes.size() - 1]->quadrangulateFaces(centroidsOfFaces, allEdgesWithMidPoints);
    allMeshes[allMeshes.size() - 1]->create();

    // emit sig_restartFaces();


    //update list widget
    for (HalfEdge* ed : allMeshes[allMeshes.size() - 1]->getMeshHalfEdges()) {
        emit sig_SendHalfEdge(ed);
    }

    for (Vertex* ve : allMeshes[allMeshes.size() - 1]->getMeshVertices()) {
        emit sig_SendVertex(ve);
    }


    for (Face* f : allMeshes[allMeshes.size() - 1]->getMeshFaces()) {
        emit sig_SendFace(f);
    }


    update();

}


glm::vec4 listAverage(QList<glm::vec4> vectorList) {
    glm::vec4 avg = glm::vec4(0.0f);
    float listSize = (float) vectorList.size();
    for (glm::vec4 pos : vectorList) {


        avg[0] += pos[0]/listSize;
        avg[1] += pos[1]/listSize;
        avg[2] += pos[2]/listSize;
        avg[3] += pos[3]/listSize;



    }

    return avg;

}


void MyGL::slot_discoTime() {
    //YOYOYO
    allMeshes[allMeshes.size() - 1]->destroy();


    //create a face-to-centroid map
    QMap<Face*, glm::vec4> centroidsOfFaces = allMeshes[allMeshes.size() - 1]->getMeshCentroids();


    //collect one halfedge for every edge in mesh
    QList<HalfEdge*> edgesToGiveMidPoints;
    for (HalfEdge* he : allMeshes[allMeshes.size() - 1]->getMeshHalfEdges() ) {
        if (!edgesToGiveMidPoints.contains(he->getSym())) {
            edgesToGiveMidPoints.push_back(he);
        }

    }



    //make a copy of the original vertices
    QList<Vertex*> verticesToSmooth = allMeshes[allMeshes.size() - 1]->getMeshVertices();


    //calculate smoothed midpoints
    QList<glm::vec4> neighboringVertices;
    QList<HalfEdge*> allEdgesWithMidPoints;

    for (HalfEdge* hehe : edgesToGiveMidPoints) {

        //v1
        neighboringVertices.push_back(hehe->getVert()->getPos());

        //v2
        neighboringVertices.push_back(hehe->getSym()->getVert()->getPos());

        if (hehe->getFace() != NULL) {
            //f1
            neighboringVertices.push_back(centroidsOfFaces[hehe->getFace()]);
        }

        if (hehe->getSym()->getFace() != NULL) {
            //f2
            neighboringVertices.push_back(centroidsOfFaces[hehe->getSym()->getFace()]);
        }



        selectedVertex = allMeshes[allMeshes.size() - 1]->addMidPoint(hehe, listAverage(neighboringVertices), allEdgesWithMidPoints);
        selectedVertex->create();

        neighboringVertices.clear();
    }



    //shiftToBarycenter

    //traverse to find

    std::cout <<" how many buggers need to be smoothed" << verticesToSmooth.size();
    std::cout << " start at this guy " << glm::to_string(verticesToSmooth.at(0)->getPos()) << std::endl;
    for (Vertex* curVert : verticesToSmooth) {//.at(0);

        HalfEdge* curEdge = curVert->getEdge();
        Face* curFace = curEdge->getFace();

        if (curFace == NULL) {

            curFace = curEdge->getSym()->getFace();

        }

        //traverse to find all adjacent midpoints and incident faces
        QList<Vertex*> adjacentMidpoints;
        QList<Face*> incidentFaces;


        while (!incidentFaces.contains(curFace)) {
            incidentFaces.push_back (curFace);
            adjacentMidpoints.push_back(curEdge->getSym()->getVert());

            curEdge = curEdge->getNext();
            if (curEdge->getSym()->getVert() == curVert) {
                //move onto opposite face
                curEdge = curEdge->getSym();
                curFace = curEdge->getFace();

            }
        }



        glm::vec4 sume = glm::vec4(0.f);
        for (Vertex* adj : adjacentMidpoints) {
            sume += adj->getPos();
        }
        float n = adjacentMidpoints.size();
        float nsq = glm::pow(n, 2);

        //sum of all incident face centroids
        glm::vec4 sumf = glm::vec4(0.0);
        for (Face* face : incidentFaces) {
            sumf+= centroidsOfFaces[face];
        }




        glm::vec4 oldPos = curVert->getPos();

        glm::vec4 newPos = ((n - 2) * oldPos/n)  + sume/nsq + sumf/nsq;

        curVert->setPos(newPos);

        incidentFaces.clear();


        adjacentMidpoints.clear();
    }


    //quadrangulate faces

    //create list of midpoints
    allMeshes[allMeshes.size() - 1]->quadrangulateFaces(centroidsOfFaces, allEdgesWithMidPoints);

    allMeshes[allMeshes.size() - 1]->create();

    prog_lambert.draw(*this, *selectedVertex);
    selectedHalfEdge = NULL;

    //update list widget
    for (HalfEdge* ed : allMeshes[allMeshes.size() - 1]->getMeshHalfEdges()) {
        emit sig_SendHalfEdge(ed);
    }

    for (Vertex* ve : allMeshes[allMeshes.size() - 1]->getMeshVertices()) {
        emit sig_SendVertex(ve);
    }


    for (Face* f : allMeshes[allMeshes.size() - 1]->getMeshFaces()) {
        emit sig_SendFace(f);
    }
    update();
}


void MyGL::slot_showEdge() {
    if (selectedVertex == NULL) {
        return;
    }

    selectedHalfEdge = selectedVertex->getEdge();
    selectedHalfEdge->create();

    emit sig_sendNewlySelectedHalfEdge(selectedHalfEdge);

    update();
}

void MyGL::slot_showStartEdge() {
    if (selectedFace == NULL) {
        return;
    }

    selectedHalfEdge = selectedFace->getStartEdge();
    selectedHalfEdge->create();

    emit sig_sendNewlySelectedHalfEdge(selectedHalfEdge);

    update();

}


void MyGL::slot_showVertexFace() {
    if (selectedVertex == NULL) {
        return;
    }

    HalfEdge* edge = selectedVertex->getEdge();

    selectedFace = edge->getFace();
    //std::cout << "selected face: " << selectedFace->getid() << std::endl;
    selectedFace->create();

    emit sig_sendNewlySelectedFace(selectedFace);

    update();

}


void MyGL::slot_importObjFile() {
    meshHasBeenImported = true;

    selectedFace = NULL;
    selectedHalfEdge = NULL;
    selectedVertex = NULL;

    emit sig_restartFaces();

    int faceID = 0;
    int vertID = 0;
    int edgeID = 0;


    //QString filename = QFileDialog::getOpenFileName(this, tr("Mooo time for an obj import"), "/Users/Nancy/Desktop/cis 277/hw06/objs/", "*.obj");
    QString filename = QFileDialog::getOpenFileName(this, tr("Mooo time for an obj import"), "../../../objs", "*.obj");


    if (filename == NULL) {
        return;
    }

    //QString filename = "/Users/Nancy/Desktop/cis 277/hw06/objs/cube.obj";
    QFile file(filename);


    file.open(QIODevice::ReadOnly);

    QTextStream in(&file);

    QList<glm::vec4> objPoses;
    QList<Vertex*> objVertices;
    QList<HalfEdge*> objHalfEdges;
    QMap<Vertex*, QList<HalfEdge*>> vertsToIncidentHalfEdges;
    QList<Face*> objFaces;

    QString l = in.readLine();

    QStringList strlist;

    int randGen = 0;



    while (!l.isNull()) {


        //positions
        if (l.contains("v ")) {


            //read the line
            strlist = l.split(" ", QString::SkipEmptyParts);


            glm::vec4 vec = glm::vec4(1.f);
            for (int i = 1; i < 4; i++) {

                vec[i - 1] = strlist.at(i).toFloat();
            }

            objPoses.push_back(vec);

            Vertex* vert = new Vertex(vec, vertID++);
            objVertices.push_back(vert);

            QList<HalfEdge*> incidentEdges;
            vertsToIncidentHalfEdges.insert(vert, incidentEdges);

        }

        //faces
        else if (l.contains("f ")) {


            strlist = l.split(" ", QString::SkipEmptyParts);

            Face* face = new Face(faceID++);


            //generate a random color amount for each face
            srand (randGen++);
            float tint = rand() % 100;
            face->setColor(1, 1, 1, tint/100);
            objFaces.push_back(face);

            HalfEdge* prevEdge = NULL;
            HalfEdge* firstEdge = NULL;

            //loop through vertices of each face


            for (int i = 1; i < strlist.size(); i++) {

                QString str = strlist.at(i); // num/num/num

                int vertIdx = str.split("/").at(0).toInt(); //get the v indx

                Vertex* vert = objVertices.at(vertIdx - 1); //get the v


                //make a halfedge
                HalfEdge* edge = new HalfEdge(face, vert, NULL, NULL, edgeID++);
                objHalfEdges.push_back(edge);

                //at first prevEdge will be null
                if (prevEdge == NULL) {
                    prevEdge = edge;
                    firstEdge = edge;
                    face->setStartEdge(edge);

                }
                //set up prev's nextEdge, update prevEdge to this edge
                else {
                    prevEdge->setNext(edge);
                    prevEdge = edge;
                }
                //add edge to vert's mapping
                vertsToIncidentHalfEdges[vert].push_back(edge);

                //aaaand give it a halfEdge pointing to it
                vert->setEdge(edge);

            }
            //manually set last halfedge's next to first halfedge
            prevEdge->setNext(firstEdge);
        }
        l = in.readLine();
    }

    //set up syms for all halfedges
    for (HalfEdge* giveSym : objHalfEdges) {

        //examine the list halfedges also incident to giveSym's vertex
        QList<HalfEdge*> potentialSyms = vertsToIncidentHalfEdges[giveSym->getVert()];

        std::cout << "hay hay hay " << giveSym->getid() << std::endl;
        std::cout << " my vert " << giveSym->getVert()->getid() << std::endl;

        for (HalfEdge* potentialSym : potentialSyms) {

            if (potentialSym->getNext()->getVert() == giveSym->getPrev()->getVert()) {

                giveSym->setSym(potentialSym->getNext());

            }
        }
    }

    Mesh* newMesh = new Mesh(objFaces, objVertices, objHalfEdges);
    newMesh->create();
    newMesh->setName(max_mesh_id);
    max_mesh_id++;
    allMeshes.append(newMesh);

    QList<QListWidgetItem*> hackySolution;


    emit sig_sendListOfFaces(hackySolution);
    update();


    if (allMeshes[allMeshes.size() - 1]->getMeshVertices().size() < 1000  || needCowVertices) {
        for (Face * fsend : allMeshes[allMeshes.size() - 1]->getMeshFaces()) {
            emit sig_SendFace(fsend);
            hackySolution.push_back( (QListWidgetItem*) fsend);
        }

        int edgeCount = 0;
        for (Vertex * vsend : allMeshes[allMeshes.size() - 1]->getMeshVertices()) {
            edgeCount++;
            if (edgeCount % 1000 == 0) {
                std::cout<< "aaaalmost there! only " << edgeCount <<
                            " out of " << allMeshes[allMeshes.size() - 1]->getMeshHalfEdges().size()
                         << " edges left to go!" << std::endl;
            }

            emit sig_SendVertex(vsend);
        }

        edgeCount = 0;
        for (HalfEdge * hsend : allMeshes[allMeshes.size() - 1]->getMeshHalfEdges()) {
            edgeCount++;
            if (edgeCount % 1000 == 0) {
                std::cout<< "aaaalmost there! only " << edgeCount <<
                            " out of " << allMeshes[allMeshes.size() - 1]->getMeshHalfEdges().size()
                         << " edges left to go!" << std::endl;
            }
            emit sig_SendHalfEdge(hsend);
        }


    }




}


void MyGL::slot_exportObjFile() {
    std::cout << "WRITE " << std::endl;

    QString filename = "../../../objs/mymesh.obj";
    QFile file(filename);
    if (!file.open(QIODevice::ReadWrite)) {
        return;

    }


    QTextStream out (&file);

    for (Vertex * v : allMeshes[allMeshes.size() - 1]->getMeshVertices()) {
        glm::vec4 pos = v->getPos();
        out << "v " << pos[0] << " " << pos[1] << " " << pos[2] << endl;
    }

    for (Face* f : allMeshes[allMeshes.size() - 1]->getMeshFaces()) {
        out << "f ";
        HalfEdge* e  = f->getStartEdge();
        out << (e->getVert()->getid() + 1) << "// ";
        e = e->getNext();
        while (e != f->getStartEdge()) {
            out << (e->getVert()->getid() + 1) << "// ";
            e = e->getNext();
        }
        out << endl;
    }
}

void MyGL::slot_selectMesh(QListWidgetItem* mesh) {
    selectedMesh = (Mesh*)mesh;
    update();
}


void MyGL::slot_importJSONFile(){

    QString filename = QFileDialog::getOpenFileName(this, tr("Mooo time for an obj import"), "../../../jsons", "*.json");


    if (filename == NULL) {
        std::cout << "marrrp";
        return;
    }


    QFile file(filename);
    file.open(QIODevice::ReadOnly);

    QTextStream in(&file);

    QString jstuff = in.readAll();

    file.close();

    QJsonDocument jdoc = QJsonDocument::fromJson(jstuff.toUtf8());
    QJsonObject jobj (jdoc.object());

    QJsonValue jval = jobj.value("root");


    jroot = new Joint();
    jroot->setText(0, QString::fromStdString("root"));
    jroot = readJoints(jroot, jval.toObject());

    jroot->create();

    selectedJoint = jroot;

    emit sig_sendRootJoint(jroot);




    update();

}




Joint* MyGL::readJoints(Joint* parent, QJsonObject jobj) {


    //set name
    QString name = jobj.value("name").toString();
    QJsonArray posData = jobj.value("pos").toArray();
    QJsonArray roData = jobj.value("rot").toArray();
    QJsonArray childrenData = jobj.value("children").toArray();


    //set intial local translation
    float p0 = posData.at(0).toDouble();
    float p1 = posData.at(1).toDouble();
    float p2 = posData.at(2).toDouble();

    glm::vec4 pos = glm::vec4(p0, p1, p2, 1);


    //set local rotation
    float a = roData.at(0).toDouble();
    //float a = 30;
    float x = roData.at(1).toDouble();
    float y = roData.at(2).toDouble();
    float z = roData.at(3).toDouble();

    //normalize


    // glm::quat ro = glm::quat(rw, rx, ry, rz);
    glm::quat ro = glm::angleAxis(a, glm::vec3(x, y, z));


    Joint* child = new Joint(name, parent, pos, ro, jointCount++);

    //add it to its parent's list of children
    parent->QTreeWidgetItem::addChild(child);

    //recursively call children
    for (QJsonValue v : childrenData) {
        readJoints(child, v.toObject());
    }

    return parent;

}

void MyGL::traverseJoints(Joint * joint, glm::mat4 T) {

    if (playingFromTimeline) {
        T = T * joint->getTransformationAtFrame(curFrameTime);
    }

    else {
        T = T * joint->getLocalTransformation();
    }


    joint->setOverallTransformation(T);
    joint->create();


    for (Joint* child : joint->getChildren()) {
        traverseJoints(child, T);

        prog_lambert.draw(*this, *child);

    }

    return;

}

//might not be necessary anymore lol
glm::mat4 MyGL::getSQUAD() {
    /*if (keyframes.contains(curTime)) {
            return keyframes[curTime]->getTransformation();
        }

            //prev key
            int k0 = curTime;

            while (!keyframes.contains(k0) && k0 > 0) {
                k0--;
            }

            //next key
            int k1 = curTime;
            while(!keyframes.contains(k1) && k1 <= keyframes.maxKey()) {
                k1++;
            }

            //take care of endpoints cases
            calculateSQUAD(k0, k1);*/
}

void MyGL::slot_calculateBindMatrices() {

    if (jroot == NULL) {
        return;
    }

    //draw using the skeleton fragment shader rather than the progwire or whatever
    allMeshes[allMeshes.size() - 1]->setBoundTrue();

    //put all the joints in a qlist, excluding root
    QList<Joint*> allJoints;
    jroot->getAllDescendants(allJoints);

    //set current overall transformation as bind matrix
    for (Joint* jay : allJoints) {
        jay->setBindMatrix();

        jointMatsForShaderProg.push_back(jay->getOverallTransformation());
        bindMatsForShaderProg.push_back(jay->getBindMatrix());

    }


    //set weights and ids of closest joints to each vertex
    for (Vertex * bert : allMeshes[allMeshes.size() - 1]->getMeshVertices()) {
        bert->setClosestJoints(allJoints);
    }

    //recreate mesh, now with joints bound
    allMeshes[allMeshes.size() - 1]->create();

    update();


}



void MyGL::slot_receiveSelectedJoint(QTreeWidgetItem* joint, int) {

    if(selectedJoint != NULL) {

        selectedJoint->toggleSelectedness();
    }



    selectedJoint = (Joint*) joint;


    selectedJoint->toggleSelectedness();

    disableUpdate = true;
    glm::vec4 selectedJointPos = selectedJoint->getOverallTransformation() * glm::vec4(0, 0, 0, 1);
    //update spin boxes
    emit sig_sendJointX(selectedJointPos[0]);
    emit sig_sendJointY(selectedJointPos[1]);
    emit sig_sendJointZ(selectedJointPos[2]);


    glm::quat selectedJointRo = selectedJoint->getRotation();
    emit sig_sendJointRoX(selectedJointRo[1]);
    emit sig_sendJointRoY(selectedJointRo[2]);
    emit sig_sendJointRoZ(selectedJointRo[3]);

    disableUpdate = false;

    update();
}


void MyGL::slot_updateJointX(double jx) {

    if (selectedJoint == NULL || disableUpdate) {
        return;
    }

    //get current world coordinates
    glm::vec4 oldWorldPos = selectedJoint->getOverallTransformation() * glm::vec4(0, 0, 0, 1);


    //should be either 0.001 in one direction or another
    float dx = jx - oldWorldPos[0];

    glm::vec4 newPos = selectedJoint->getPos();

    newPos[0] += dx;


    //update position relative to parent
    selectedJoint->updatePosition(newPos);


    QList<Joint*> allJoints;
    jroot->getAllDescendants(allJoints);
    jointMatsForShaderProg.clear();

    for (Joint* jay : allJoints) {

        jointMatsForShaderProg.push_back(jay->getOverallTransformation());
        // bindMatsForShaderProg.push_back(jay->getBindMatrix());

    }
    allMeshes[allMeshes.size() - 1]->create();



    prog_skel.setJointMatrices(jointMatsForShaderProg);
    playingFromTimeline = false;

    update();

}

void MyGL::slot_updateJointY(double jy) {

    if (selectedJoint == NULL || disableUpdate) {
        return;
    }
    //get current world coordinates
    glm::vec4 oldWorldPos = selectedJoint->getOverallTransformation() * glm::vec4(0, 0, 0, 1);


    //should be either 0.001 in one direction or another
    float dy = jy - oldWorldPos[1];

    glm::vec4 newPos = selectedJoint->getPos();

    newPos[1] += dy;


    //update position relative to parent
    selectedJoint->updatePosition(newPos);

    QList<Joint*> allJoints;
    jroot->getAllDescendants(allJoints);
    jointMatsForShaderProg.clear();

    //set current overall transformation as bind matrix
    for (Joint* jay : allJoints) {
        // jay->setBindMatrix();

        jointMatsForShaderProg.push_back(jay->getOverallTransformation());
        // bindMatsForShaderProg.push_back(jay->getBindMatrix());

    }
    allMeshes[allMeshes.size() - 1]->create();



    prog_skel.setJointMatrices(jointMatsForShaderProg);
    playingFromTimeline = false;
    update();

}

void MyGL::slot_updateJointZ(double jz) {

    if (selectedJoint == NULL || disableUpdate) {
        return;
    }

    //get current world coordinates
    glm::vec4 oldWorldPos = selectedJoint->getOverallTransformation() * glm::vec4(0, 0, 0, 1);


    //should be either 0.001 in one direction or another
    float dz = jz - oldWorldPos[2];

    glm::vec4 newPos = selectedJoint->getPos();

    newPos[2] += dz;


    //update position relative to parent
    selectedJoint->updatePosition(newPos);

    QList<Joint*> allJoints;
    jroot->getAllDescendants(allJoints);
    jointMatsForShaderProg.clear();

    //set current overall transformation as bind matrix
    for (Joint* jay : allJoints) {
        jointMatsForShaderProg.push_back(jay->getOverallTransformation());
    }
    allMeshes[allMeshes.size() - 1]->create();

    prog_skel.setJointMatrices(jointMatsForShaderProg);
    playingFromTimeline = false;
    update();
}

void MyGL::slot_updateJointRoX(double rx) {

    if (selectedJoint == NULL || disableUpdate) {
        return;
    }
    glm::quat oldRo = selectedJoint->getRotation();

    //get change in degrees along x
    glm::vec3 prevVec = glm::normalize(glm::axis(oldRo));
    float prevX = glm::angle(oldRo) * prevVec[0]; //get old x component
    float dx = rx - prevX;

    //rotate by change in degrees along x
    glm::quat newRo = glm::rotate(oldRo, dx, glm::vec3(1, 0, 0));

    selectedJoint->setRotation(newRo);


    QList<Joint*> allJoints;
    jroot->getAllDescendants(allJoints);
    jointMatsForShaderProg.clear();

    //set current overall transformation as bind matrix
    for (Joint* jay : allJoints) {
        // jay->setBindMatrix();

        jointMatsForShaderProg.push_back(jay->getOverallTransformation());
        // bindMatsForShaderProg.push_back(jay->getBindMatrix());

    }
    allMeshes[allMeshes.size() - 1]->create();

    prog_skel.setJointMatrices(jointMatsForShaderProg);
    playingFromTimeline = false;
    update();
}

void MyGL::slot_updateJointRoY(double ry) {
    if (selectedJoint == NULL || disableUpdate) {
        return;
    }

    glm::quat oldRo = selectedJoint->getRotation();

    //get change in degrees along x
    glm::vec3 prevVec = glm::normalize(glm::axis(oldRo));
    float prevX = glm::angle(oldRo) * prevVec[1]; //get old x component
    float dx = ry - prevX;

    //rotate by change in degrees along x
    glm::quat newRo = glm::rotate(oldRo, dx, glm::vec3(0, 1, 0));

    selectedJoint->setRotation(newRo);


    QList<Joint*> allJoints;
    jroot->getAllDescendants(allJoints);
    jointMatsForShaderProg.clear();

    //set current overall transformation as bind matrix
    for (Joint* jay : allJoints) {

        jointMatsForShaderProg.push_back(jay->getOverallTransformation());

    }
    allMeshes[allMeshes.size() - 1]->create();



    prog_skel.setJointMatrices(jointMatsForShaderProg);
    playingFromTimeline = false;
    update();

}

void MyGL::slot_updateJointRoZ(double rz) {

    if (selectedJoint== NULL  || disableUpdate) {
        return;
    }


    glm::quat oldRo = selectedJoint->getRotation();

    //get change in degrees along x
    glm::vec3 prevVec = glm::normalize(glm::axis(oldRo));
    float prevX = glm::angle(oldRo) * prevVec[2]; //get old x component
    float dx = rz - prevX;

    //rotate by change in degrees along x
    glm::quat newRo = glm::rotate(oldRo, dx, glm::vec3(0, 0, 1));

    selectedJoint->setRotation(newRo);


    QList<Joint*> allJoints;
    jroot->getAllDescendants(allJoints);
    jointMatsForShaderProg.clear();

    //set current overall transformation as bind matrix
    for (Joint* jay : allJoints) {
        jointMatsForShaderProg.push_back(jay->getOverallTransformation());
    }
    allMeshes[allMeshes.size() - 1]->create();

    prog_skel.setJointMatrices(jointMatsForShaderProg);
    playingFromTimeline = false;
    update();

}


void MyGL::slot_setDisplayCowVertices() {
    needCowVertices = !needCowVertices;
}

float MyGL::area(glm::vec4 a, glm::vec4 b, glm::vec4 c) {
    //heron's formula
    vec4 ab = b - a;
    vec4 ca = a - c;
    vec4 bc = c - b;

    float s1 = length(ab);
    float s2 = length(ca);
    float s3 = length(bc);

    float s = (s1 + s2 + s3) / 2;
    float area = std::sqrt((float) (s*(s-s1)*(s-s2)*(s-s3)));
    return area;

}

float MyGL::intersectTriangle(Ray r, QList<Vertex*> verts) {

    vec4 P1 = verts[0]->getPos();
    vec4 P2 = verts[1]->getPos();
    vec4 P3 = verts[2]->getPos();

    vec4 n = normalize(cross(P1 - P2,P1 - P3));
    n.w = 0;
    vec4 s = P1;
    float t = dot(n, (s - r.origin)) / dot(n, r.direction);

    vec4 P = r.getOrigin() + (t * r.getDirection());

    float s0 = area(P1, P2, P3);
    float s1 = area(P, P2, P3) / s0;
    float s2 = area(P, P3, P1) / s0;
    float s3 = area(P, P1, P2) / s0;
    //for some reason this math isn't working out? going over 1. Check this.

    if((s1 >= 0 && s1 <= 1) && (s2 >= 0 && s2 <= 1) && (s3 >= 0 && s3 <= 1) && (s1 +  s2 + s3 <= 1 + .01 && s1 + s2 + s3 >= 1 - .01)) {
        return t;
    } else {
        return -1;
    }

}
QList<QList<Vertex*>>  MyGL::triangulateFaceForRayTrace(Face* f) {
    //Triangulate the face
    //Go through the face, break up into triangular faces, return list of faces
    HalfEdge* start = f->getStartEdge();
    HalfEdge* e = start->getNext();

    QList<Vertex*> verts;
    QList<QList<Vertex*>> vert_sets;
    QList<Vertex> vobj;
    QList<QList<Vertex>> vobsets;

    verts.append(start->getVert());
    vobj.append(*start->getVert());
    do {
        vobj.append(*e->getVert());
        verts.append(e->getVert());
        e = e->getNext();
    } while(e != start);

    for(int i = 0; i < verts.size() - 2; i++) {
        Vertex* v0 = verts[0];
        Vertex* v1 = verts[i + 1];
        Vertex* v2 = verts[i + 2];
        QList<Vertex*> set;
        set.append(v0);
        set.append(v1);
        set.append(v2);
        vert_sets.append(set);
        vobsets.append(vobj);
    }
    return vert_sets;

}

vec4 MyGL::AccLightSource(Face* f, Ray &r, vec4 light_pos, QList<Mesh*>& meshes, vec4 normal, float t1) {

    vec4 material_color = f->getColor();
    float ambient_light = 0.1;
    vec4 color = material_color;
    //find ray from f toward l
    float epsilon = .01;
    vec4 P = normalize(r.origin + (t1 * r.direction)); //this is app 0, 0, 1. Does that make sense?
    Ray f_to_l = Ray(normalize(P + (light_pos - P)*epsilon), normalize(light_pos - P));
    for(Mesh* m : meshes) {
        for(Face* f2 : m->getMeshFaces()) {
            //get list of sets of 3 points that are "triangles" to triangulate the face
            QList<QList<Vertex*>> tris = triangulateFaceForRayTrace(f2);
            //for every set, see if intersects
            for(QList<Vertex*> vertices : tris) {

                float t = intersectTriangle(f_to_l, vertices);

                if(t >= 0) { //intersection, so compute shadow
                    return vec4(.2,.2,.2,1);
                }
            }
        }
    }
    //didn't intersect, compute lambert
    //add diffuse intensity

    //l is the lightsource to the normal
    vec4 l = normalize(light_pos - P);
    float brightness_value = clamp(dot(normal, l), 0.f, 1.f);

    vec4 light_color = vec4(1, 1, 1, 1);
    color = material_color * (brightness_value + ambient_light) * light_color;

    //add specular highlight (Phong)
    vec4 V = normalize(camera.eye - P);
    vec4 H = normalize((V + l));
    H /= 2;
    H.w = 0;
    V.w = 0;
    float specular = fmax(pow(dot(H,normal), u_shininess), 0);
    color += specular;
    color.w = 1;
    //color is ending up being over 1 here... normalize?
    return color;
}

vec4 MyGL::raytrace(Ray& r, QList<Mesh*>& meshes, int depth) {

    /*PSEUDOCODE
     * REFERENCED THIS PAPER: http://www.fsz.bme.hu/~szirmay/ray.pdf
     * If depth > max depth, return background color
     *
     * Check if ray intersects face
     * if doesn't intersect, return background color
     * if interesects:
     *  color = acclightsource(face)
     *  if reflective:
     *      reflected ray = ray toward inverse direction of reflection
     *      color += raytrace(reflected ray, d+1)
     *  if refractive:
     *      refracted ray = ray toward inverse direction of refraction
     *      color += raytrace(refracted ray, d+1)
     * return c;
     *
*/
    vec4 col = vec4(.1,.1,.1,1);
    if(depth < 5) {
        vec4 light_pos = vec4(5, 5, 3, 1);
        float t = 0;
        float tmin = INFINITY;
        //iterate through all faces in all meshes to check if ray intersects
        int i = 0;
        for(Mesh* m : allMeshes) {
            //  std::cout<<"Mesh " << i++ << std::endl;
            u_shininess = m->specularity;
            QList<Face> o_list;
            for(Face* f : m->getMeshFaces()) {
                QList<QList<Vertex*>> faces = triangulateFaceForRayTrace(f);
                for(QList<Vertex*> vertlist : faces) {
                    t = intersectTriangle(r, vertlist);
                    if(t > 0) {
                        vec4 a = f->getStartEdge()->getNext()->getVert()->getPos();
                        vec4 b = f->getStartEdge()->getNext()->getNext()->getVert()->getPos();
                        vec4 c = f->getStartEdge()->getVert()->getPos();
                        vec4 ab = b - a;
                        vec4 ac = c - a;
                        vec4 normal = normalize(cross(ab, ac));
                        normal.w = 0;

                        if(t < tmin && t > 0) {
                            tmin = t;
                            col = AccLightSource(f, r, light_pos, meshes, normal, tmin);
                            vec4 intersection = normalize(r.origin + (t*r.direction));
                            //if reflective
                            if(m->reflectivity > 0) {
                                u_shininess = m->reflectivity;
                                Ray reflectedRay = Ray(intersection, glm::reflect(normalize(r.direction - r.origin),normal));
                                col += raytrace(reflectedRay,meshes, depth++);
                            }
                            //if refractive
                            if(m->refractive_index > 0) {
                                Ray refractedRay = Ray(intersection,glm::refract(normalize(r.direction - r.origin), normal, m->refractive_index));
                                col += raytrace(refractedRay, meshes, depth++);
                            }
                        }
                    }
                }
            }
            return col;
        }
    }
}



void MyGL::slot_exportBMP() {

    int depth = 0;

    BMP output;
    output.SetSize(camera.width, camera.height);
    output.SetBitDepth(24);
    vec4 light_pos = vec4(3, 4, 5, 1);

    //make a vector of vec3s (2d array)
    //in this loop, store the color to this array
    //then go throug hte array and compute compute output
    color_array = std::vector<std::vector<vec3>>(camera.width, std::vector<vec3> (camera.height, glm::vec3(0,0,0)));

    parallel_for<size_t>(0, camera.width, 1, [=](int x){
        for(int y = 0; y < camera.height; y++){

            //antialisaing jitter method
            //divide pixel (x,y) into 4 subsections
            float xdiv = .5;
            float ydiv = .5;
            // float f = ((float)rand() / RAND_MAX);
            float f = .5;

            float sample1x = x + f*(xdiv);
            float sample2x = (x + xdiv) + f*(xdiv);
            float sample1y = y + f*(ydiv);
            float sample2y = (y + ydiv) + f*(ydiv);

            Ray r1 = Raycast(sample1x, sample1y);
            Ray r2 = Raycast(sample1x, sample2y);
            Ray r3 = Raycast(sample2x, sample1y);
            Ray r4 = Raycast(sample2x, sample2y);

            vec4 rgb1 = 255.0f * raytrace(r1, allMeshes, depth);
            vec4 rgb2 = 255.0f * raytrace(r2, allMeshes, depth);
            vec4 rgb3 = 255.0f * raytrace(r3, allMeshes, depth);
            vec4 rgb4 = 255.0f * raytrace(r4, allMeshes, depth);

            vec4 rgb = rgb1 + rgb2 + rgb3 + rgb4;
            rgb /= 4.0f;
            //            Ray r = Raycast(x,y);
            //            vec4 rgb = 255.0f * raytrace(r, allMeshes, depth);

            //store in color array
            color_array[x][y] = glm::vec3(rgb);
        }
    });
    //loop through the color array, set output xyz

    for(int x = 0; x < camera.width; x++) {
        for(int y = 0; y < camera.height; y++) {
            vec3 rgb = color_array[x][y];
            output(x, y)->Red = rgb[0];
            output(x, y)->Green = rgb[1];
            output(x, y)->Blue = rgb[2];
            //printf("X: %d, Y: %d\n", x, y);
        }
    }

    output.WriteToFile("/Users/chloesnyder/Desktop/CIS277/minimaya/rays.bmp");

    update();
}


Ray MyGL::Raycast(float x, float y) {

    double len = glm::length(camera.ref - camera.eye);
    double alpha = camera.fovy/2;

    float sx = (2 * x / camera.width) - 1;
    float sy = 1 - (2 * y/camera.height);


    glm::vec4 F = normalize(camera.ref - camera.eye);
    glm::vec4 R = normalize(glm::vec4(glm::cross(glm::vec3(F), glm::vec3(camera.up)), 0));
    glm::vec4 U = normalize(glm::vec4(glm::cross(glm::vec3(R), glm::vec3(F)), 0));

    glm::vec4 V = U * (float) len * (float) tan(alpha);

    glm::vec4 H = R * (float) len * (float) camera.width/camera.height * (float) tan(alpha);

    glm::vec4 p = camera.ref + sx * H + sy * V;

    return Ray(camera.eye, (p - camera.eye)/glm::length(p - camera.eye));
}


void MyGL::slot_receiveNumFrames(int i) {
    numFrames = i;
}


void MyGL::slot_createNewKeyFrame() {

    if (selectedJoint == NULL || curFrameTime == 0) {
        return;
    }


    selectedJoint->addNewKeyframe(curFrameTime);
}


void MyGL::slot_createFrameTimeline() {

    emit sig_makeNewTimeline();

    //keyframes are 1-indexed
    //allFrames is 0-indexed
    for (int i = 1; i <= numFrames; i++) {
        Frame * blankFrame = new Frame(i);
        emit sig_sendFrame(blankFrame);
    }

}

void MyGL::slot_receiveSelectedFrame(QListWidgetItem* curFrame) {


    curFrameTime = ((Frame*)curFrame)->getTime();

    playingFromTimeline = true;

    if (jroot == NULL) {
        return;
    }
    QList<Joint*> allJoints;
    jroot->getAllDescendants(allJoints);
    jointMatsForShaderProg.clear();

    //re-get the overall transformations
    for (Joint* jay : allJoints) {
        jointMatsForShaderProg.push_back(jay->getOverallTransformation());
    }
    allMeshes[allMeshes.size() - 1]->create();

    prog_skel.setJointMatrices(jointMatsForShaderProg);


    update();
}


void MyGL::slot_updateRefraction(double r){
    if(selectedMesh != NULL) {
        selectedMesh->refractive_index = (float)r;
        update();
    }

}

void MyGL::slot_updateReflection(double r){
    if(selectedMesh != NULL) {
        selectedMesh->reflectivity = (float)r;
        update();
    }

}

bool MyGL::isInEdgeLoop(Vertex *v) {
    //a vertex is in an edge loop if there are 4 incoming edges or if between 2 faces on a cube
    QList<HalfEdge*> incident_edges;
    //loop through each edge in the mesh, check to see how many point to v
    for(HalfEdge* he :  selectedMesh->getMeshHalfEdges()) {
        if(he->getVert() == v) {
            incident_edges.append(he);
        }
    }
    if(incident_edges.size() == 4) {
        return true;
    } else {
        //check if on cube
        //        if(incident_edges.size() == 3) {
        //            //check if face is square
        //        }

        return false;
    }



    //    HalfEdge* he = v->getEdge();
    //    incident_edges.append(he);
    //    HalfEdge* start = v->getEdge();
    //    he = he->getSym();
    //    do {
    //        //loop through edge loop to get edge pointing to v
    //        while(he->getVert() != v) {
    //            he = he->getNext();
    //        }
    //        //add to list, go to sym edge to visit next loop
    //        incident_edges.append(he);
    //        he = he->getSym();
    //    } while(he != start);

    //    if(incident_edges.size() == 4) {
    //        return true;
    //    } else {
    //        return false;
    //    }
}

void MyGL::slot_insertEdgeLoop() {
    /*PSEUDOCODE:
     * For selectedEdge, get the vert and the sym vert.
     * Check that there are 4 incoming edges OR get the edge loop around a face if a cube or something
     * Find the next edge, check that, etc until back at start edge
     * If selected edge is between 2 edge loops, split the edge
     * Using edge loop, find the next edge to split. Split all edges
     * Create new half edges between the new vertices
     * Link up, create the edge loop
     * */
    if(selectedHalfEdge != NULL) {
        QList<Vertex*> visited_verts_from_one_loop;
        HalfEdge* start1 = selectedHalfEdge->getNext()->getSym();
        HalfEdge* start2 = selectedHalfEdge->getSym()->getNext();
        HalfEdge* e1 = start1->getNext();
        HalfEdge* e2 = start2->getNext();

        Vertex* v1 = selectedHalfEdge->getVert();
        Vertex* v2 = selectedHalfEdge->getSym()->getVert();
        bool isEdgeLoop1 = isInEdgeLoop(v1);
        bool isEdgeLoop2 = isInEdgeLoop(v2);
        visited_verts_from_one_loop.append(v1);

        if(!isEdgeLoop1 || !isEdgeLoop2 ) {
            return; //stop, not in an edge loop
        } else { //check the rest of the loop
            do {
                v1 = e1->getVert();
                v2 = e2->getVert();
                isEdgeLoop1 = isInEdgeLoop(v1);
                isEdgeLoop2 = isInEdgeLoop(v2);
                if(!isEdgeLoop1 || !isEdgeLoop2 ) {
                    return; //stop if either not in an edge loop
                }
                visited_verts_from_one_loop.append(v1);
                e1 = e1->getNext();
                e2 = e2->getNext();
            } while(e1 != start1);
        }

        //at this point we know that the edge we wish to bisect is between 2 edge loops
        //now we need to get all the edges we need to split and draw new edges between
        QList<HalfEdge*> edges_to_bisect;
        QList<Vertex*> new_verts;

        HalfEdge* e = selectedHalfEdge->getNext();

        //get the edges you need to bisect
        //figure out a way to generalize this. There's a pattern of .next.next to .sym.next.next



        /*edges_to_bisect.append(selectedHalfEdge);
        edges_to_bisect.append(selectedHalfEdge->getNext()->getNext());
        edges_to_bisect.append(selectedHalfEdge->getSym()->getNext()->getNext());
        edges_to_bisect.append(selectedHalfEdge->getSym()->getNext()->getNext()->getSym()->getNext()->getNext());



//        for(HalfEdge* he : edges_to_bisect) {
//            Vertex* new_vert = selectedMesh->addVertex(he);
//            new_verts.append(new_vert);
//            prog_lambert.draw(*this, *new_vert);
//            new_vert->create();
//        }
//        QList<HalfEdge*> new_edges;
//        for(int j = 0; j < 2; j++) {
//            for(int i = 0; i < new_verts.size(); i++) {
//                HalfEdge* he = new HalfEdge();
//                HalfEdge* he2 = new HalfEdge();
//                he->setVert(new_verts[i]);
//                new_edges.append(he);
//                selectedMesh->addHalfEdge(he);
//            }
//        }

//        //LOL FIX
//        new_edges[0]->setNext(new_edges[1]);
//        new_edges[1]->setNext(new_edges[2]);
//        new_edges[2]->setNext(new_edges[3]);
//        new_edges[3]->setNext(new_edges[0]);

//        new_edges[4]->setNext(new_edges[5]);
//        new_edges[5]->setNext(new_edges[6]);
//        new_edges[6]->setNext(new_edges[7]);
//        new_edges[7]->setNext(new_edges[4]);

//        new_edges[0]->setSym(new_edges[7]);
//        new_edges[1]->setSym(new_edges[6]);
//        new_edges[2]->setSym(new_edges[5]);
//        new_edges[3]->setSym(new_edges[4]);

*/

        //redraw new mesh
        selectedHalfEdge = NULL;
        //update list widget
        for (HalfEdge* e : selectedMesh->getMeshHalfEdges()) {

            emit sig_SendHalfEdge(e);
        }

        for (Vertex* v : selectedMesh->getMeshVertices()) {

            emit sig_SendVertex(v);
        }


        for (Face* f : selectedMesh->getMeshFaces()) {

            emit sig_SendFace(f);
        }
        update();
    }
}

void MyGL::slot_meshTranslateX(double x) {
    if(selectedMesh != NULL) {
        for(Vertex* v : selectedMesh->getMeshVertices()) {
            vec4 new_pos = v->getPos();
            new_pos.x += x;
            v->setPos(new_pos);
        }
    }
    update();
}

void MyGL::slot_meshTranslateY(double y) {
    if(selectedMesh != NULL) {
        for(Vertex* v : selectedMesh->getMeshVertices()) {
            vec4 new_pos = v->getPos();
            new_pos.y += y;
            v->setPos(new_pos);
        }
    }
    update();
}

void MyGL::slot_meshTranslateZ(double z) {
    if(selectedMesh != NULL) {
        for(Vertex* v : selectedMesh->getMeshVertices()) {
            vec4 new_pos = v->getPos();
            new_pos.z += z;
            v->setPos(new_pos);
        }
    }
    update();
}

//void slot_meshRotateX(double x);
//void slot_meshRotateY(double y);
//void slot_meshRotateZ(double z);

void MyGL::slot_meshScaleX(double x) {
    if(selectedMesh != NULL) {
        for(Vertex* v : selectedMesh->getMeshVertices()) {
            vec4 new_pos = v->getPos();
            new_pos.x *= x;
            v->setPos(new_pos);
        }
    }
    update();
}

void MyGL::slot_meshScaleY(double y) {
    if(selectedMesh != NULL) {
        for(Vertex* v : selectedMesh->getMeshVertices()) {
            vec4 new_pos = v->getPos();
            new_pos.y *= y;
            v->setPos(new_pos);
        }
    }
    update();
}

void MyGL::slot_meshScaleZ(double z) {
    if(selectedMesh != NULL) {
        for(Vertex* v : selectedMesh->getMeshVertices()) {
            vec4 new_pos = v->getPos();
            new_pos.z *= z;
            v->setPos(new_pos);
        }
        selectedMesh->destroy();
        selectedMesh->create();
    }

    update();
    //prog_lambert.draw(*this, *selectedMesh);
}



void MyGL::slot_extrudeFace() {
    if (selectedMesh == NULL) {
        if (!allMeshes.size() == 1) {
            std::cout << "trying to extrude face buuuut mesh is null so yeah woops try importing lol " << std::endl;
            return;
        }

        selectedMesh = allMeshes.at(0);
    }

    if(selectedHalfEdge == NULL && selectedFace == NULL) {
        std::cout << "trying to extrude face buuuut no face selected " << std::endl;
        return;
    }

    HalfEdge* cur_edge = selectedHalfEdge;
    if (selectedHalfEdge == NULL) {
        cur_edge = selectedFace->getStartEdge();
    }


    Face* origFace = cur_edge->getFace();

    glm::vec4 EndPoint1 = cur_edge->getVert()->getPos();
    glm::vec4 otherEndPoint1 = cur_edge->getSym()->getVert()->getPos();
    glm::vec4 firstEdge = otherEndPoint1 - EndPoint1;

    glm::vec4 EndPoint2 = cur_edge->getNext()->getVert()->getPos();
    glm::vec4 secondEdge = EndPoint2 - EndPoint1;

    //calculate the direction in which we want p to go
    glm::vec4 face_norm = glm::vec4(glm::cross(glm::vec3(secondEdge), glm::vec3(firstEdge)), 0);
    face_norm /= glm::length(face_norm);

    //EXTRUDE MESH ALONG CURDGE AND FACE NORM
    selectedMesh->extrudeFace(cur_edge, face_norm);
    selectedFace->create();
    selectedMesh->create();

    //update list widget
    for (HalfEdge* e : allMeshes[allMeshes.size() - 1]->getMeshHalfEdges()) {

        emit sig_SendHalfEdge(e);
    }

    for (Vertex* v : allMeshes[allMeshes.size() - 1]->getMeshVertices()) {

        emit sig_SendVertex(v);
    }


    for (Face* f : allMeshes[allMeshes.size() - 1]->getMeshFaces()) {

        emit sig_SendFace(f);
    }

    update();


}
void MyGL::slot_extrudeEdge() {
    if (selectedMesh == NULL) {
        if (!allMeshes.size() == 1) {
            std::cout << "trying to extrude face buuuut mesh is null so yeah woops try importing lol " << std::endl;
            return;
        }

        selectedMesh = allMeshes.at(0);
        selectedMesh->create();
    }

    if (selectedHalfEdge == NULL)  {
        return;
    }

    selectedMesh->extrudeEdge(selectedHalfEdge);
    selectedHalfEdge = NULL;
    selectedMesh->create();

    //update list widget
    for (HalfEdge* e : allMeshes[allMeshes.size() - 1]->getMeshHalfEdges()) {

        emit sig_SendHalfEdge(e);
    }

    for (Vertex* v : allMeshes[allMeshes.size() - 1]->getMeshVertices()) {

        emit sig_SendVertex(v);
    }


    for (Face* f : allMeshes[allMeshes.size() - 1]->getMeshFaces()) {

        emit sig_SendFace(f);
    }

    update();


}




