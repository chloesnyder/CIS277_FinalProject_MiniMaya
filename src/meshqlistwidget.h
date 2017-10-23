#ifndef MESHQLISTWIDGET_H
#define MESHQLISTWIDGET_H

#include <QListWidget>
#include <QListWidgetItem>
#include "halfedge.h"
#include "mesh.h"


class MeshQListWidget : public QListWidget
{
    Q_OBJECT
public:
    MeshQListWidget(QWidget* parent = NULL);
    ~MeshQListWidget();

public slots:
    void slot_addHalfEdge(QListWidgetItem* half_edge);
    void slot_addVertex(QListWidgetItem* vertex);
    void slot_addFace(QListWidgetItem* face);

    void slot_selectFace(QListWidgetItem* face);
    void slot_selectHalfEdge(QListWidgetItem* halfedge);
    void slot_restartFaces();

    void slot_addListOfFaces(QList<QListWidgetItem*> facesList);

    void slot_addMesh(QListWidgetItem* mesh);
    void slot_selectMesh(QListWidgetItem* mesh);



};

#endif // MESHQLISTWIDGET_H
