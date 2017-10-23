#include "mesh.h"
#include <iostream>




Mesh::Mesh()
    : bufIdx(QOpenGLBuffer::IndexBuffer),
      bufPos(QOpenGLBuffer::VertexBuffer),
      bufNor(QOpenGLBuffer::VertexBuffer),
      bufCol(QOpenGLBuffer::VertexBuffer)
{


}

Mesh::Mesh(QList<Face*> faces,
           QList<Vertex*> vertexList,
           QList<HalfEdge*> halfEdgeList)
    : bufIdx(QOpenGLBuffer::IndexBuffer),
    bufPos(QOpenGLBuffer::VertexBuffer),
    bufNor(QOpenGLBuffer::VertexBuffer),
    bufCol(QOpenGLBuffer::VertexBuffer)

{

    this->faces = faces;
    this->vertexList = vertexList;
    this->halfEdgeList = halfEdgeList;

}

Mesh::Mesh(const Mesh &m) {
    for(Face* f : m.faces) {
        this->faces.append(new Face(f));
    }
    for(Vertex* v : m.vertexList) {
        this->vertexList.append(new Vertex(v));
    }
    for(HalfEdge* h : m.halfEdgeList) {
        this->halfEdgeList.append(new HalfEdge(h));
    }
//    this->faces = m.faces;
//    this->vertexList = m.vertexList;
//    this->halfEdgeList = m.halfEdgeList;
}

void Mesh::setBoundTrue() {
    isBound = true;
}


void Mesh::removeFaceFromList(Face* f) {
    // std::cout << "removed face " << f->getid() << " from list " << std::endl;
    faces.erase(std::remove(faces.begin(), faces.end(), f), faces.end());

}
void Mesh::removeVertexFromList(Vertex* v) {
    //s std::cout << "removed vertex " << v->getid() << " from list " << std::endl;
    vertexList.erase(std::remove(vertexList.begin(), vertexList.end(), v), vertexList.end());
}

void Mesh::removeHalfEdgeFromList(HalfEdge* e) {
    //std::cout << "removed edge " << e->getid() << " from list " << std::endl;
    halfEdgeList.erase(std::remove(halfEdgeList.begin(), halfEdgeList.end(), e), halfEdgeList.end());

}

void Mesh::setName(int i) {
    this->setText(QString::fromStdString(std::to_string(i)));
}

void createEverything(QList<Face*> &faces, std::vector<glm::vec4> &vertices,
                      std::vector<glm::vec4> &norms, std::vector<glm::vec4> &colors,
                      std::vector<GLuint> (&indices), QList<HalfEdge*> &halfEdgeList,
                      QList<Vertex*> &vertexList, bool isBound,  std::vector<glm::ivec2> &allJointIDsForBuffer,
                      std::vector<glm::vec2> &allJointWeightsForBuffer) {

    int randGen = 0;

    allJointIDsForBuffer.clear();
    allJointWeightsForBuffer.clear();

    vertexList.clear();
    halfEdgeList.clear();

    int lastVertexIndex = 0;
    int faceCount = 0;

    for (Face* f : faces) {
        faceCount++;

        int numVertices = 1;
        int min_idx = lastVertexIndex;
        lastVertexIndex++;

        HalfEdge* start_edge = f->getStartEdge();

        HalfEdge* cur_edge = start_edge;
        //add to lists to sig out
        halfEdgeList.push_back(cur_edge);

        vertices.push_back(cur_edge->getVert()->getPos());

        if (isBound) {

            allJointIDsForBuffer.push_back(cur_edge->getVert()->getJointIDsForBuffer());

            //make a vector and push it back
            allJointWeightsForBuffer.push_back(cur_edge->getVert()->getJointWeightsForBuffer());

        }

        if (!vertexList.contains(cur_edge->getVert())) {
            vertexList.push_back(cur_edge->getVert());
        }


        glm::vec4 EndPoint1 = cur_edge->getVert()->getPos();
        glm::vec4 otherEndPoint1 = cur_edge->getSym()->getVert()->getPos();
        glm::vec4 firstEdge = otherEndPoint1 - EndPoint1;

        glm::vec4 EndPoint2 = cur_edge->getNext()->getVert()->getPos();
        glm::vec4 secondEdge = EndPoint2 - EndPoint1;



        glm::vec4 face_norm = glm::vec4(glm::cross(glm::vec3(firstEdge), glm::vec3(secondEdge)), 0);

        norms.push_back(face_norm);

        colors.push_back(f->getColor());

        //move on cur_edge
        cur_edge = cur_edge->getNext();

        //ADD VERTICES
        while(cur_edge != start_edge) {
            numVertices++;
            lastVertexIndex++;
            halfEdgeList.push_back(cur_edge);

            vertices.push_back(cur_edge->getVert()->getPos());

            if (isBound) {
             allJointIDsForBuffer.push_back(cur_edge->getVert()->getJointIDsForBuffer());
             allJointWeightsForBuffer.push_back(cur_edge->getVert()->getJointWeightsForBuffer());
            }

            if (!vertexList.contains(cur_edge->getVert())) {
                vertexList.push_back(cur_edge->getVert());
            }

            glm::vec4 EndPoint1 = cur_edge->getVert()->getPos();
            glm::vec4 otherEndPoint1 = cur_edge->getSym()->getVert()->getPos();
            glm::vec4 firstEdge = otherEndPoint1 - EndPoint1;

            glm::vec4 EndPoint2 = cur_edge->getNext()->getVert()->getPos();
            glm::vec4 secondEdge = EndPoint2 - EndPoint1;



            glm::vec4 face_norm = glm::vec4(glm::cross(glm::vec3(firstEdge), glm::vec3(secondEdge)), 0);


            norms.push_back(face_norm);

            //CREATE COLORS

            srand (randGen++);


            float tint = rand() % 100;


           // f->setColor(0, 1, 1, tint/100);

            colors.push_back(f->getColor());


            cur_edge = cur_edge->getNext();



        }

        //CREATE INDICES
        for (int i = 0; i < (numVertices - 2); i++) {
            indices.push_back(min_idx);
            indices.push_back(min_idx + i + 1);
            indices.push_back(min_idx + i + 2);
        }
    }
}




void Mesh::makeCube() {

    //i can't believe i'm about to hardcode all this
    faceID = 0;
    float coord = 0.5;

    //front face vertices
    glm::vec4 p0 = glm::vec4(-coord, coord, coord, 1);
    Vertex* v0 = new Vertex(p0, 0);
    glm::vec4 p1 = glm::vec4(-coord, -coord, coord, 1);
    Vertex* v1 = new Vertex(p1, 1);
    glm::vec4 p2 = glm::vec4(coord, -coord, coord, 1);
    Vertex* v2 = new Vertex(p2, 2);
    glm::vec4 p3 = glm::vec4(coord, coord, coord, 1);
    Vertex* v3 = new Vertex(p3, 3);

    //hind face vertices
    glm::vec4 p4 = glm::vec4(coord, coord, -coord, 1);
    Vertex* v4 = new Vertex(p4, 4);
    glm::vec4 p5 = glm::vec4(coord, -coord, -coord, 1);
    Vertex* v5 = new Vertex(p5, 5);
    glm::vec4 p6 = glm::vec4(-coord, -coord, -coord, 1);
    Vertex* v6 = new Vertex(p6, 6);
    glm::vec4 p7 = glm::vec4(-coord, coord, -coord, 1);
    Vertex* v7 = new Vertex(p7, 7);


    //+z face
    Face* f0 = new Face(faceID++);
    HalfEdge* e23 = new HalfEdge(f0, v3, NULL, NULL,23);
    HalfEdge* e12 = new HalfEdge(f0, v2, e23, NULL, 12);
    HalfEdge* e01 = new HalfEdge(f0, v1, e12, NULL, 01);
    HalfEdge* e30 = new HalfEdge(f0, v0, e01, NULL, 30);
    e23->setNext(e30);

    //+x face   //f1
    Face* f1 = new Face(faceID++);
    HalfEdge* e43 = new HalfEdge(f1, v3, NULL, NULL, 43);
    HalfEdge* e54 = new HalfEdge(f1, v4, e43, NULL, 54);
    HalfEdge* e25 = new HalfEdge(f1, v5, e54, NULL, 25);
    HalfEdge* e32 = new HalfEdge(f1, v2, e25, e23, 32);
    e43->setNext(e32);
    e23->setSym(e32);

    //-z face //f5
    Face* f2 = new Face(faceID++);
    HalfEdge* e45 = new HalfEdge(f2, v5, NULL, e54, 45);
    HalfEdge* e74 = new HalfEdge(f2, v4, e45, NULL, 74);
    HalfEdge* e67 = new HalfEdge(f2, v7, e74, NULL, 67);
    HalfEdge* e56 = new HalfEdge(f2, v6, e67, NULL, 56);
    e45->setNext(e56);
    e54->setSym(e45);



    //-x face //f2
    Face* f3 = new Face(faceID++);
    HalfEdge* e10 = new HalfEdge(f3, v0, NULL, e01, 10);
    HalfEdge* e61 = new HalfEdge(f3, v1, e10, NULL, 61); //
    HalfEdge* e76 = new HalfEdge(f3, v6, e61, e67, 76);
    HalfEdge* e07 = new HalfEdge(f3, v7, e76, NULL, 07);//
    e10->setNext(e07);
    e67->setSym(e76);
    e01->setSym(e10);



    //+y face
    Face* f4 = new Face(faceID++);
    HalfEdge* e34 = new HalfEdge(f4, v4, NULL, e43, 34);
    HalfEdge* e03 = new HalfEdge(f4, v3, e34, e30, 03);
    HalfEdge* e70 = new HalfEdge(f4, v0, e03, e07, 70);
    HalfEdge* e47 = new HalfEdge(f4, v7, e70, e74, 47);
    e34->setNext(e47);
    e07->setSym(e70);
    e74->setSym(e47);
    e30->setSym(e03);
    e43->setSym(e34);

    //-y face //f4
    Face* f5 = new Face(faceID++);
    HalfEdge* e21 = new HalfEdge(f5, v1, NULL, e12, 21);
    HalfEdge* e52 = new HalfEdge(f5, v2, e21, e25, 52);
    HalfEdge* e65 = new HalfEdge(f5, v5, e52, e56, 65);
    HalfEdge* e16 = new HalfEdge(f5, v6, e65, e61, 16);
    e61->setSym(e16);
    e56->setSym(e65);
    e25->setSym(e52);
    e12->setSym(e21);
    e21->setNext(e16);




    //vertices of start edges will tell us where theo start triangulation
    f0->setStartEdge(e30);
    f1->setStartEdge(e54);
    f2->setStartEdge(e74);
    f3->setStartEdge(e10);
    f4->setStartEdge(e03);
    f5->setStartEdge(e21);

    faces.push_back(f0);
    faces.push_back(f1);
    faces.push_back(f2);
    faces.push_back(f3);
    faces.push_back(f4);
    faces.push_back(f5);

}



void Mesh::makeSquarePlane() {
    faceID = 0;

    float sideSize = 1;
    float coord = sideSize/2;

    //initialize a face
    Face* f = new Face(faceID++);

    //upper left vertex
    glm::vec4 p1 = glm::vec4(-coord, coord, 0, 1);
    Vertex* v1 = new Vertex(p1, 0);

    //bottom left vertex
    glm::vec4 p2 = glm::vec4(-coord, -coord, 0, 1);
    Vertex* v2 = new Vertex(p2, 1);

    //bottom right vertex
    glm::vec4 p3 = glm::vec4(coord, -coord, 0, 1);
    Vertex* v3 = new Vertex(p3, 2);

    //upper right vertex
    glm::vec4 p4 = glm::vec4(coord, coord, 0, 1);
    Vertex* v4 = new Vertex(p4, 3);

    //half edge pointing to upper left vertex
    HalfEdge* start_edge = new HalfEdge(f, v1, NULL, NULL, 0);
    start_edge->setSym(NULL, v4, start_edge, NULL, 4);

    //half edge pointing to bottom left vertex
    HalfEdge* edge2 = new HalfEdge(f, v2, NULL, NULL, 1);
    edge2->setSym(NULL, v1, NULL, edge2, 5);
    start_edge->next = edge2;

    //half edge pointing to bottom right vertex
    HalfEdge* edge3 = new HalfEdge(f, v3, NULL, NULL, 2);
    edge3->setSym(NULL, v2, NULL, edge3, 6);
    start_edge->next->next = edge3;

    //half edge pointing to upper right vertex
    HalfEdge* edge4 = new HalfEdge(f, v4, NULL, NULL, 3);
    edge4->setSym(NULL, v3, NULL, edge3, 7);
    start_edge->next->next->next = edge4;

    //set next of last half edge to starting halfedge
    start_edge->next->next->next->next = start_edge;


    f->setStartEdge(start_edge);

    faces.push_back(f);

}


void Mesh::create(){

    std::vector<glm::vec4> vertices;

    std::vector<glm::vec4> norms;
    std::vector<glm::vec4>colors;
    std::vector<GLuint> indices;

    //this->halfEdgeList.clear();
    //this->vertexList.clear();
    //this->faces.clear();


    createEverything(faces, vertices, norms, colors, indices, halfEdgeList, vertexList, isBound, allJointIDsForBuffer, allJointWeightsForBuffer);

    int MESH_VERT_COUNT = vertices.size();
    int MESH_IDX_COUNT = indices.size();
    count = MESH_IDX_COUNT;


    bufIdx.create();
    bufIdx.bind();
    bufIdx.setUsagePattern(QOpenGLBuffer::StaticDraw);
    bufIdx.allocate(indices.data(), MESH_IDX_COUNT * sizeof(GLuint));

    bufPos.create();
    bufPos.bind();
    bufPos.setUsagePattern(QOpenGLBuffer::StaticDraw);
    bufPos.allocate(vertices.data(),MESH_VERT_COUNT * sizeof(glm::vec4));

    bufCol.create();
    bufCol.bind();
    bufCol.setUsagePattern(QOpenGLBuffer::StaticDraw);
    bufCol.allocate(colors.data(), MESH_VERT_COUNT * sizeof(glm::vec4));

    bufNor.create();
    bufNor.bind();
    bufNor.setUsagePattern(QOpenGLBuffer::StaticDraw);
    bufNor.allocate(norms.data(), MESH_VERT_COUNT * sizeof(glm::vec4));

    if (isBound) {

        bufJointIDs.create();
        bufJointIDs.bind();
        bufJointIDs.setUsagePattern(QOpenGLBuffer::StaticDraw);
        bufJointIDs.allocate(allJointIDsForBuffer.data(), MESH_VERT_COUNT * sizeof(glm::ivec2));

        bufWeights.create();
        bufWeights.bind();
        bufWeights.setUsagePattern(QOpenGLBuffer::StaticDraw);
        bufWeights.allocate(allJointWeightsForBuffer.data(), MESH_VERT_COUNT *sizeof(glm::vec2));
    }



}

void Mesh::destroy()
{
    bufIdx.destroy();
    bufPos.destroy();
    bufNor.destroy();
    bufCol.destroy();

    if (isBound) {
        bufJointIDs.destroy();
        bufWeights.destroy();
    }
}

GLenum Mesh::drawMode()
{
    return GL_TRIANGLES;
}

int Mesh::elemCount()
{
    return count;
}

bool Mesh::bindIdx()
{
    return bufIdx.bind();
}

bool Mesh::bindPos()
{
    return bufPos.bind();
}

bool Mesh::bindNor()
{
    return bufNor.bind();
}

bool Mesh::bindCol()
{
    return bufCol.bind();
}


glm::vec4 cross(glm::vec4 v1, glm::vec4 v2){

    glm::vec3 vec1 = glm::vec3(v1[0], v1[1], v1[2]);
    glm::vec3 vec2 = glm::vec3(v2[0], v2[1], v2[2]);
    glm::vec3 res = glm::cross(vec1, vec2);
    return glm::vec4(res[0], res[1], res[2], 1);

}


QList<HalfEdge *> &Mesh::getMeshHalfEdges() {


    return halfEdgeList;
}

QList<Vertex *> &Mesh::getMeshVertices() {



    return vertexList;
}


QList<Face *> &Mesh::getMeshFaces() {
    return faces;

}

void Mesh::addHalfEdge(HalfEdge* e){
    halfEdgeList.append(e);
}



//add a vertex at the midpoint of the halfedge
Vertex* Mesh::addVertex(HalfEdge* selected) {

    HalfEdge* BA = selected;
    HalfEdge* AB = selected->getSym();


    // int newID = std::stof(std::to_string(BA->getVert()->getid()) + std::to_string(AB->getVert()->getid()));

    glm::vec4 newPos = BA->getVert()->getPos() + AB->getVert()->getPos();
    newPos = glm::vec4(newPos[0]/2, newPos[1]/2, newPos[2]/2, 1);

    int newID = BA->getid() + 1000;
    Vertex* E = new Vertex(newPos, BA->getid());

    HalfEdge* EA = new HalfEdge(BA->getFace(), BA->getVert(), BA->getNext(), AB, newID);

    newID = AB->getid() + 1000;
    HalfEdge* EB = new HalfEdge(AB->getFace(), AB->getVert(), AB->getNext(), BA, newID);




    AB->setVert(E); //AB now AE
    BA->setVert(E); //BA now BE
    E->setEdge(AB);

    AB->setNext(EB);
    AB->setSym(EA);

    BA->setNext(EA);
    BA->setSym(EB);


    destroy();
    create();

    AB->create();
    EA->create();
    EB->create();
    BA->create();

    return E;



}

void Mesh::triangulate(Face* f, HalfEdge* startEdge) {

    int numVerticesOnFace = 1;

    HalfEdge* e = startEdge;

    //count number of vertices
    while (e->getNext() != startEdge) {
        e = e->getNext();
        numVerticesOnFace++;
    }

    if (numVerticesOnFace < 4) {
        return;
    }


    HalfEdge* AB = startEdge;
    HalfEdge* BC = AB->getNext();
    HalfEdge* CD = BC->getNext();


    HalfEdge* DB = new HalfEdge(f, AB->getVert(), AB->getNext(), NULL, 4000);
    HalfEdge* BD = new HalfEdge(f, CD->getVert(), CD->getNext(), DB, 4001);
    DB->setSym(BD);


    DB->create();
    BD->create();

    AB->setNext(BD);
    CD->setNext(DB);

    Face* f2 = new Face(faceID++);
    BC->setFace(f2);
    CD->setFace(f2);
    DB->setFace(f2);
    f2->setStartEdge(BC);
    f->setStartEdge(AB);

    faces.push_back(f2);

    f2->create();
    f->create();

    triangulate(f, f->getStartEdge());


}


//return a list of the centroids
QMap<Face*, glm::vec4> Mesh::getMeshCentroids() {

    centroidFaces.clear();
    centroidFaces.begin();
    for (Face* f : faces) {
        centroidFaces.insert(f, f->calculateCentroid());
    }
    return centroidFaces;
}




Vertex* Mesh::addMidPoint(HalfEdge* selected, glm::vec4 midPos, QList<HalfEdge*> &allEdgesWithMidPoints) {


    HalfEdge* BA = selected;
    HalfEdge* AB = selected->getSym();


    int newID = BA->getid() + 100;
    Vertex* E = new Vertex(midPos, newID);
    E->setText(QString::fromStdString("M" + std::to_string(newID)));




    HalfEdge* EA = new HalfEdge(BA->getFace(), BA->getVert(), BA->getNext(), AB, newID);
    EA->setText(QString::fromStdString("M" + std::to_string(newID)));

    newID++;

    HalfEdge* EB = new HalfEdge(AB->getFace(), AB->getVert(), AB->getNext(), BA, newID);
    EB->setText(QString::fromStdString("M" + std::to_string(newID)));



    AB->setVert(E); //AB now AE
    BA->setVert(E); //BA now BE


    allEdgesWithMidPoints.push_back(AB);
    allEdgesWithMidPoints.push_back(BA);
    E->setEdge(BA);

    AB->setNext(EB);
    AB->setSym(EA);

    BA->setNext(EA);
    BA->setSym(EB);





    AB->create();
    EA->create();
    EB->create();
    BA->create();


    halfEdgeList.push_back(EA);
    halfEdgeList.push_back(EB);




    return E;
}

void Mesh::quadrangulateFaces(QMap<Face*, glm::vec4> centroidsOfFaces, QList<HalfEdge*> midpointEdges) {
    std::cout << "mesh:: EY NICE QUADS " << std::endl;



    QList<HalfEdge*> newStartEdges;
    QMap<HalfEdge*, HalfEdge*> oldPrevs;
    for (HalfEdge* originalEdge : halfEdgeList) {
        oldPrevs.insert(originalEdge, originalEdge->getPrev());

    }


    QList<HalfEdge*> quadEdges;
    QList<Face*> newFaces;
    QList<Face*> oldFaces;

    //later will loop
    for (Face* curFace : faces) {
        oldFaces.push_back(curFace);
       // std::cout << "test face id" << curFace->getid() << std::endl;
       // std::cout << "my start edge " << curFace->getStartEdge()->getid() << std::endl;

        //create an actual vertex out of the centroid
        Vertex* centroidVert = new Vertex(centroidsOfFaces[curFace], curFace->getid());
        vertexList.push_back(centroidVert);
        centroidVert->setText(QString::fromStdString("C" + std::to_string(curFace->getid())));
        centroidVert->create();

        //start at a halfedge pointing to a midpoint
        HalfEdge* s = curFace->getStartEdge();

        if (!midpointEdges.contains(s)){
            s = s->getNext();

        }



        //keep a record of all the midpoints, which will serve as our new start edges

        HalfEdge* curEdge = s->getNext()->getNext();

        while (curEdge != s) {

            newStartEdges.push_back(curEdge);
            curEdge = curEdge->getNext()->getNext();
        }

        newStartEdges.push_back(curEdge);


        //keep track of the toCentroid edge of the previous face
        HalfEdge* lastToCentroidEdge = NULL;
        HalfEdge* firstFromCentroidEdge = NULL;

        //make new faces in counterclockwise order


        QMap<HalfEdge*, HalfEdge*> startEdgesToCentroidEdges;
        int newFaceID = curFace->getid() * 1000;


        for (HalfEdge* s : newStartEdges) {



            //make a new face
            Face* newFace = new Face(newFaceID + s->getFace()->getid());
            newFace->setText(QString::fromStdString("Q" + std::to_string(newFace->getid())));

            newFace->setStartEdge(s);

            oldPrevs.value(s)->setFace(newFace);



            newFaces.push_back(newFace);
            newFaceID++;

            if (newFaceID < 0) {
                std::cout << "WHY IS THIS HAPPENINGGGG" << std::endl;
            }

            //make a new halfedge leading out of the centroid
            //can use startedge's prev() function because nexts are not updated until the end
            HalfEdge* prev1 = oldPrevs.value(s);
            HalfEdge* prev2 = oldPrevs.value(prev1);
            HalfEdge* fromCentroid = new HalfEdge(newFace, prev2->getVert(),
                                                  oldPrevs.value(s), NULL, s->getid() * 110000);
            fromCentroid->setText(QString::fromStdString("fC" + std::to_string(fromCentroid->getid())));
            quadEdges.push_back(fromCentroid);
            //make a new halfedge leading into the centroid
            HalfEdge* toCentroid = new HalfEdge(newFace, centroidVert, fromCentroid, NULL, s->getid() + 210000);
            quadEdges.push_back(toCentroid);
            toCentroid->setText(QString::fromStdString("tC" + std::to_string(toCentroid->getid())));
            startEdgesToCentroidEdges.insert(s, toCentroid);

            //set syms of new edges
            if (lastToCentroidEdge != NULL) {
                if (lastToCentroidEdge->getFace() != fromCentroid->getFace()) {
                   // std::cout << " set the sym of fromCentroid to " << lastToCentroidEdge->getid() << std::endl;
                    fromCentroid->setSym(lastToCentroidEdge);
                }
            }

            lastToCentroidEdge = toCentroid;

            if (firstFromCentroidEdge == NULL) {
                firstFromCentroidEdge = fromCentroid;
            }



        }


        //special treatment for last case to finish loop
        lastToCentroidEdge->setSym(firstFromCentroidEdge);



        //may as well do this here
        centroidVert->setEdge(lastToCentroidEdge);



        //update next pointers of the new start edges
        for (HalfEdge* startEdge : startEdgesToCentroidEdges.keys())  {

            startEdge->setNext(startEdgesToCentroidEdges[startEdge]);
        }



        newStartEdges.clear();


    }





    for (Face* oldFace : oldFaces) {
        removeFaceFromList(oldFace);
        oldFace->destroy();
        delete oldFace;

    }



    for (Face* newFace : newFaces) {

        newFace->create();
        faces.push_back(newFace);
    }

    destroy();
    create();


    //create all the new edges yay
    for (HalfEdge* v : halfEdgeList) {
        v->create();

    }


}

//this function had funky normals that i thought looked amaaazing
void Mesh::discoMesh(QMap<Face*, glm::vec4> centroidsOfFaces, QList<HalfEdge*> midpointEdges) {
    std::cout << "mesh:: EY NICE QUADS " << std::endl;



    QList<HalfEdge*> newStartEdges;
    QList<HalfEdge*> quadEdges;
    QList<Face*> newFaces;
    QList<Face*> oldFaces;

    //later will loop
    for (Face* curFace : faces) {
        oldFaces.push_back(curFace);


        //create an actual vertex out of the centroid
        Vertex* centroidVert = new Vertex(centroidsOfFaces[curFace], 000);
        centroidVert->create();

        //start at a halfedge pointing to a midpoint
        HalfEdge* s = curFace->getStartEdge();

        if (!midpointEdges.contains(s)){
            s = s->getNext();

        }



        //keep a record of all the midpoints, which will serve as our new start edges

        HalfEdge* curEdge = s->getNext()->getNext();

        while (curEdge != s) {

            newStartEdges.push_back(curEdge);
            curEdge = curEdge->getNext()->getNext();
        }

        newStartEdges.push_back(curEdge);


        //keep track of the toCentroid edge of the previous face
        HalfEdge* lastToCentroidEdge = NULL;
        HalfEdge* firstFromCentroidEdge = NULL;

        //make new faces in counterclockwise order


        QMap<HalfEdge*, HalfEdge*> startEdgesToCentroidEdges;
        int newFaceID = curFace->getid() * 1000;

        for (HalfEdge* s : newStartEdges) {


            //make a new face
            Face* newFace = new Face(newFaceID + s->getFace()->getid());

            newFace->setStartEdge(s);

            newFaces.push_back(newFace);
            newFaceID++;

            //make a new halfedge leading out of the centroid
            //can use startedge's prev() function because nexts are not updated until the end
            HalfEdge* fromCentroid = new HalfEdge(newFace, s->getPrev()->getPrev()->getVert(),
                                                  s->getPrev(), NULL, s->getid() + 110000);

            quadEdges.push_back(fromCentroid);

            //make a new halfedge leading into the centroid
            HalfEdge* toCentroid = new HalfEdge(newFace, centroidVert, fromCentroid, NULL, s->getid() + 210000);
            quadEdges.push_back(toCentroid);

            startEdgesToCentroidEdges.insert(s, toCentroid);

            //set syms of new edges
            if (lastToCentroidEdge != NULL) {
                if (lastToCentroidEdge->getFace() != fromCentroid->getFace()) {
                   // std::cout << " set the sym of fromCentroid to " << lastToCentroidEdge->getid() << std::endl;
                    fromCentroid->setSym(lastToCentroidEdge);
                }
            }

            lastToCentroidEdge = toCentroid;

            if (firstFromCentroidEdge == NULL) {
                firstFromCentroidEdge = fromCentroid;
            }

        }


        //special treatment for last case to finish loop
        lastToCentroidEdge->setSym(firstFromCentroidEdge);

        //may as well do this here
        centroidVert->setEdge(lastToCentroidEdge);



        //update next pointers of the new start edges
        for (HalfEdge* startEdge : startEdgesToCentroidEdges.keys())  {

            startEdge->setNext(startEdgesToCentroidEdges[startEdge]);
        }



        newStartEdges.clear();


    }


    //create all the new edges yay
    for (HalfEdge* quadEdge : quadEdges) {



        quadEdge->create();
    }


   /* for (Face* oldFace : oldFaces) {
        faces.removeOne(oldFace);
        oldFace->destroy();

    }*/

    faces.clear();

    for (Face* newFace : newFaces) {
        newFace->create();
        faces.push_back(newFace);
    }

    destroy();
    create();


}



bool Mesh::bindWeights() {
    return bufWeights.bind();

}
bool Mesh::bindJointIDs() {

    //if a buffer has been created, it can be bound
    return bufJointIDs.bind();
}

bool Mesh::hasBeenBound() {
    return isBound;
}

void Mesh::extrudeFace(HalfEdge* start, glm::vec4 direction) {

    int faceID = 1000;
    int edgeID = 71;

    QList<HalfEdge*> newEdges;
    HalfEdge* cur = start;

    HalfEdge* firstNeedSym = NULL;
    HalfEdge* needSym = NULL;



    // --CALCULATE POSITIONS FOR NEW PREVS-- //

    //maps halfedges the new vertices their syms should point to
    QMap<HalfEdge*, Vertex*> newSymVerts;
    //maps halfedges to their new vertices
    QMap<HalfEdge*, Vertex*> newVerts;
    while (cur->getNext() != start) {

        Vertex* newVert = new Vertex(cur->getVert()->getPos() + direction, cur->getVert()->getid() + 1);
        newSymVerts.insert(cur->getNext(), newVert);
        newVerts.insert(cur, newVert);

        newVert->setEdge(cur);
        newVert->create();
         cur = cur->getNext();

    }

    Vertex* newVert = new Vertex(cur->getVert()->getPos() + direction, cur->getVert()->getid() + 1);
    newSymVerts.insert(cur->getNext(), newVert);
    newVert->setEdge(cur);
    newVerts.insert(cur, newVert);
    newVert->create();



    // -- CREATE NEW FACES -- //
    cur = start;

    while (cur->getNext() != start) {



        Vertex* origVert = cur->getVert();
        HalfEdge* oldSym = cur->getSym();
        Vertex* origSymVert = oldSym->getVert();

        //move cur out to a new vertex
        cur->setVert(newVerts.value(cur));

        //create new face per halfedge visited
        Face* newFace = new Face(faceID++);
        faces.push_back(newFace);


        //create new sym
        HalfEdge* newSym = new HalfEdge(newFace, newSymVerts.value(cur), NULL, cur, edgeID + 3);
        cur->setSym(newSym);
        newEdges.push_back(newSym);

        //give cur's old sym to a new halfedge on the new face
        oldSym->setSym(new HalfEdge(newFace, origVert, NULL, oldSym, oldSym->getid()+ 1000));
        newEdges.push_back(oldSym->getSym());

        HalfEdge* newSymNext = new HalfEdge(newFace, origSymVert, oldSym->getSym(), NULL, oldSym->getid()+ 1001);
        newEdges.push_back(newSymNext);
        newSym->setNext(newSymNext);

        HalfEdge* newSymPrev = new HalfEdge(newFace, cur->getVert(), newSym, NULL, oldSym->getid() + 59);
        newEdges.push_back(newSymPrev);
        oldSym->getSym()->setNext(newSymPrev);

        if (firstNeedSym == NULL) {
            firstNeedSym = newSymNext;
        }
        newSymNext->setSym(needSym);

        needSym = newSymPrev;
        //set the edge of the old vertex
        origSymVert->setEdge(oldSym);

        //set edge of new Face
        newFace->setStartEdge(newSym);


        newFace->create();

        cur = cur->getNext();
    }

    // do everything one last time outside the edge loop //



    Vertex* origVert = cur->getVert();
    HalfEdge* oldSym = cur->getSym();
    Vertex* origSymVert = oldSym->getVert();



    //move cur out to a new vertex
    cur->setVert(newVerts.value(cur));

    //create new face per halfedge visited
    Face* newFace = new Face(faceID++);
    faces.push_back(newFace);


    //create new sym
    HalfEdge* newSym = new HalfEdge(newFace, newSymVerts.value(cur), NULL, cur, cur->getid() + 10000);
    cur->setSym(newSym);
    newEdges.push_back(newSym);

    //give cur's old sym to a new halfedge on the new face
    oldSym->setSym(new HalfEdge(newFace, origVert, NULL, oldSym, oldSym->getid()+ 1000));
    newEdges.push_back(oldSym->getSym());

    HalfEdge* newSymNext = new HalfEdge(newFace, origSymVert, oldSym->getSym(), needSym, oldSym->getid()+ 1001);
    newEdges.push_back(newSymNext);
    newSym->setNext(newSymNext);

    HalfEdge* newSymPrev = new HalfEdge(newFace, cur->getVert(), newSym, firstNeedSym, oldSym->getid() + 59);
    newEdges.push_back(newSymPrev);
    oldSym->getSym()->setNext(newSymPrev);



    needSym = newSymPrev;

    //set the edge of the old vertex
    origSymVert->setEdge(oldSym);

    //set edge of new Face
    newFace->setStartEdge(newSym);

    //create() new Face
    newFace->create();





    for (HalfEdge* newEdge : newEdges) {
        newEdge->create();
    }

}


void Mesh::extrudeEdge(HalfEdge* e) {
    QList<HalfEdge*> newHalfEdges;

    HalfEdge* oldSym = e->getSym();
    HalfEdge* prevEdge = e->getPrev();


    HalfEdge* adjacentEdge1 = e->getNext()->getSym();
    HalfEdge* adjacentEdge2 = oldSym->getNext()->getSym();




    Vertex* V1 = e->getVert();
    Vertex* V2 = oldSym->getVert();
    adjacentEdge2->setVert(V2);

    glm::vec4 f2direction = oldSym->getNext()->getVert()->getPos() - oldSym->getVert()->getPos();
    glm::vec4 f1direction = e->getNext()->getVert()->getPos() - e->getVert()->getPos() ;
    glm::vec4 newPos1 = glm::vec4(V1->getPos() + f2direction/3.f);
    glm::vec4 newPos2 = glm::vec4(V2->getPos() + f2direction/3.f);
    glm::vec4 newPos3 = glm::vec4(V1->getPos() + f1direction/3.f);
    glm::vec4 newPos4 = glm::vec4(V2->getPos() + f1direction/3.f);

    V1->setPos(newPos1);
    V2->setPos(newPos2);

    Vertex* V3 = new Vertex(newPos3, 3);
    V3->setEdge(e);
    e->setVert(V3);
    adjacentEdge1->setVert(V3);
    V3->create();


    Vertex* V4 = new Vertex(newPos4, 4);
    V4->setEdge(prevEdge);
    prevEdge->setVert(V4);
    V4->create();

    Face* newFace = new Face(3000);

    HalfEdge* newSym = new HalfEdge(newFace, V4, NULL, e, e->getid() + 2000);
    newHalfEdges.push_back(newSym);

    HalfEdge* oldSymsNewSym = new HalfEdge(newFace, V1, NULL, oldSym, e->getid() + 2010);
    oldSym->setSym(oldSymsNewSym);
    newHalfEdges.push_back(oldSymsNewSym);

    HalfEdge* newSymNext = new HalfEdge(newFace, V2, oldSymsNewSym, NULL, e->getid() + 2020);
    HalfEdge* newSymNextsSym = new HalfEdge(adjacentEdge2->getFace(), V4, adjacentEdge2->getNext(), newSymNext, e->getid() + 2030);
    newSym->setNext(newSymNext);
    newSymNext->setSym(newSymNextsSym);
    adjacentEdge2->setNext(newSymNextsSym);

    newHalfEdges.push_back(newSymNext);
    newHalfEdges.push_back(newSymNextsSym);

    HalfEdge* newSymPrev = new HalfEdge(newFace, V3, newSym, NULL, e->getid() + 2040);
    HalfEdge* newSymPrevsSym = new HalfEdge(adjacentEdge1->getFace(), V1, adjacentEdge1->getNext(), newSymPrev, e->getid() + 2040);
    oldSymsNewSym->setNext(newSymPrev);
    newSymPrev->setSym(newSymPrevsSym);
    adjacentEdge1->setNext(newSymPrevsSym);

    newHalfEdges.push_back(newSymPrevsSym);
    newHalfEdges.push_back(newSymPrev);


    for (HalfEdge* newEdge : newHalfEdges) {

        newEdge->create();
    }

    newFace->setStartEdge(newSym);
    newFace->create();
    faces.push_back(newFace);

    create();


}

void Mesh::bevelEdge(HalfEdge* e) {

}
