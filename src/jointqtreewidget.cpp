#include "jointqtreewidget.h"

jointQTreeWidget::jointQTreeWidget(QWidget* parent) : QTreeWidget(parent)
{

    rootJoint = NULL;

}


jointQTreeWidget::~jointQTreeWidget() {

     rootJoint = NULL;
}

void jointQTreeWidget::slot_addRootJoint(QTreeWidgetItem* root) {
    clear();
    addTopLevelItem(root);
    expandItem(root);
    rootJoint = root;

}


void jointQTreeWidget::slot_bindJoints() {


    if (rootJoint == NULL) {

        return;
    }

    QBrush red = QBrush(QColor(180, 215, 0));
    changeAllColors(rootJoint, red);

}


void jointQTreeWidget::changeAllColors(QTreeWidgetItem* p, QBrush color) {
    p->setForeground(0, color);

    for (int i = 0; i < p->childCount(); ++i) {
          changeAllColors(p->child(i), color);
    }

}
