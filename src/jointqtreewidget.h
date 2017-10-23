#ifndef JOINTQTREEWIDGET_H
#define JOINTQTREEWIDGET_H

#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <iostream>
#include "joint.h"
#include <QBrush>
#include <QColor>

class jointQTreeWidget : public QTreeWidget
{
    Q_OBJECT

private:
    QTreeWidgetItem* rootJoint;

public:
    jointQTreeWidget(QWidget* parent = NULL);
    ~jointQTreeWidget();

public slots:
    void slot_addRootJoint(QTreeWidgetItem* root);
    void slot_bindJoints();
    void changeAllColors(QTreeWidgetItem* p, QBrush color);
};

#endif // JOINTQTREEWIDGET_H
