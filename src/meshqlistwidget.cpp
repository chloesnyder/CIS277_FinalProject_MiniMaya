#include "meshqlistwidget.h"

MeshQListWidget::MeshQListWidget(QWidget* parent) : QListWidget(parent)
{

}

MeshQListWidget::~MeshQListWidget()
{

}

void MeshQListWidget::slot_addHalfEdge(QListWidgetItem* half_edge) {
    QListWidget::addItem(half_edge);
}

void MeshQListWidget::slot_addVertex(QListWidgetItem* vertex) {
    QListWidget::addItem(vertex);
    QListWidget::setCurrentItem(vertex);
}

void MeshQListWidget::slot_addFace(QListWidgetItem* face) {
    QListWidget::addItem(face);
}

void MeshQListWidget::slot_selectFace(QListWidgetItem* face) {
    QListWidget::setCurrentItem(face);
}

void MeshQListWidget::slot_restartFaces() {
     QListWidget::clear();

}

void MeshQListWidget::slot_selectHalfEdge(QListWidgetItem* halfedge){
    QListWidget::setCurrentItem(halfedge);

}

void MeshQListWidget::slot_addListOfFaces(QList<QListWidgetItem*> facesList) {
    for (QListWidgetItem* face : facesList) {
        QListWidget::addItem(face);
    }
}

 void MeshQListWidget::slot_addMesh(QListWidgetItem* mesh) {
      QListWidget::addItem(mesh);
 }

 void MeshQListWidget::slot_selectMesh(QListWidgetItem* mesh) {
     QListWidget::setCurrentItem(mesh);
 }

