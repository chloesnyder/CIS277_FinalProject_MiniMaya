#ifndef KEYFRAMESLISTWIDGET_H
#define KEYFRAMESLISTWIDGET_H

#include <QListWidget>
#include <QListWidgetItem>

#include <QBrush>
#include <QColor>

#include "mygl.h"
#include <QAbstractItemView>
#include <iostream>

#include <QTimer>


#include "frame.h"
#include "joint.h"

class KeyFramesListWidget : public QListWidget
{
  Q_OBJECT
private:
    Joint* selectedJoint;
    int selectedFrameIndex = 0;

public:
    KeyFramesListWidget();

    KeyFramesListWidget(QWidget* parent = NULL);
    ~KeyFramesListWidget();

public slots:
    void slot_receiveFrame(QListWidgetItem* frame);
    void slot_receiveSelectedJoint(QTreeWidgetItem* joint);
    void slot_updateColors(QListWidgetItem*);

    void slot_createNewTimeline();
    void slot_loopThroughFrames();
    void updateFrame();

};

#endif // KEYFRAMESLISTWIDGET_H
