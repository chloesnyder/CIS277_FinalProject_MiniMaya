#include "keyframeslistwidget.h"

KeyFramesListWidget::KeyFramesListWidget()
{
}


KeyFramesListWidget::KeyFramesListWidget(QWidget* parent) : QListWidget(parent) {

}

KeyFramesListWidget::~KeyFramesListWidget() {

}

void KeyFramesListWidget::slot_createNewTimeline() {

    clear();
}

void KeyFramesListWidget::slot_receiveFrame(QListWidgetItem* frame) {
    addItem(frame);
}


void KeyFramesListWidget::slot_receiveSelectedJoint(QTreeWidgetItem* joint) {


    QBrush highlightColor = QBrush(QColor(100, 175, 0));
    selectedJoint = (Joint*) joint;



    for(int i = 0; i < count(); i++){

        if (selectedJoint->hasKeyframe((Frame*) item(i))){
           item(i)->setForeground(highlightColor);

        }

        else {
            item(i)->setForeground(Qt::black);
        }

    }

}

void KeyFramesListWidget::slot_updateColors(QListWidgetItem*) {

    QBrush highlightColor = QBrush(QColor(100, 175, 0));

    if (selectedJoint == NULL) {
        return;
    }

    for(int i = 0; i < count(); i++){

        if (selectedJoint->hasKeyframe((Frame*) item(i))){
           item(i)->setForeground(highlightColor);

        }

        else {
            item(i)->setForeground(Qt::black);
        }

    }

}


void KeyFramesListWidget::slot_loopThroughFrames() {

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateFrame()));
    timer->start(1000/24);

}


void KeyFramesListWidget::updateFrame() {

    selectedFrameIndex++;

    if (selectedFrameIndex >= count()) {
        selectedFrameIndex = 0;
    }

    setCurrentItem(item(selectedFrameIndex));

    emit itemClicked(item(selectedFrameIndex));

}

