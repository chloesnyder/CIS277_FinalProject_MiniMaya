/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <jointqtreewidget.h>
#include <timelineslider.h>
#include "keyframeslistwidget.h"
#include "meshqlistwidget.h"
#include "mygl.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionQuit;
    QWidget *centralWidget;
    QPushButton *pushButton_13;
    timelineSlider *horizontalSlider;
    KeyFramesListWidget *listWidget;
    QLabel *label_25;
    QSpinBox *TimelineKeyFrameCount;
    QPushButton *pushButton_14;
    QLabel *label_26;
    MeshQListWidget *edgeList;
    QLabel *label_3;
    QPushButton *showSym;
    QPushButton *showNext;
    QPushButton *pushButton_6;
    QPushButton *pushButton;
    MyGL *mygl;
    MeshQListWidget *vertexList;
    QLabel *label_2;
    QPushButton *pushButton_9;
    QPushButton *shift_to_barycenter;
    QPushButton *pushButton_7;
    QPushButton *pushButton_3;
    QLabel *label;
    QLabel *label_9;
    QSlider *verticalSlider;
    QLabel *label_8;
    QSlider *verticalSlider_2;
    QLabel *label_7;
    QSlider *verticalSlider_3;
    MeshQListWidget *faceList;
    QPushButton *pushButton_5;
    QPushButton *pushButton_8;
    QPushButton *pushButton_2;
    QLabel *label_4;
    QLabel *label_15;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_19;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_16;
    QDoubleSpinBox *jointX;
    QLabel *label_17;
    QDoubleSpinBox *doubleSpinBox_4;
    QLabel *label_18;
    QDoubleSpinBox *doubleSpinBox_6;
    QLabel *label_23;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_20;
    QDoubleSpinBox *doubleSpinBox_7;
    QLabel *label_21;
    QDoubleSpinBox *doubleSpinBox_5;
    QLabel *label_22;
    QDoubleSpinBox *doubleSpinBox_8;
    jointQTreeWidget *treeWidget;
    QPushButton *pushButton_11;
    QPushButton *pushButton_10;
    QPushButton *pushButton_4;
    QCheckBox *checkBox;
    QPushButton *importJoints;
    QPushButton *bindButton;
    QPushButton *pushButton_12;
    QLabel *label_5;
    QPushButton *pushButton_15;
    QDoubleSpinBox *refractiveindex;
    QLabel *label_6;
    QDoubleSpinBox *doubleSpinBox;
    QLabel *label_10;
    MeshQListWidget *MeshList;
    QLabel *label_11;
    QPushButton *pushButton_16;
    QTabWidget *meshTab;
    QWidget *tab;
    QDoubleSpinBox *meshMoveX;
    QDoubleSpinBox *meshMoveY;
    QDoubleSpinBox *meshMoveZ;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QWidget *tab_2;
    QDoubleSpinBox *rotateX;
    QDoubleSpinBox *rotateY;
    QDoubleSpinBox *rotateZ;
    QLabel *label_24;
    QLabel *label_27;
    QLabel *label_28;
    QWidget *tab_3;
    QDoubleSpinBox *scaleMeshX;
    QDoubleSpinBox *scaleMeshY;
    QDoubleSpinBox *scaleMeshZ;
    QLabel *label_29;
    QLabel *label_30;
    QLabel *label_31;
    QPushButton *pushButton_17;
    QPushButton *pushButton_18;
    QPushButton *pushButton_19;
    QMenuBar *menuBar;
    QMenu *menuFile;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1348, 962);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QStringLiteral("actionQuit"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButton_13 = new QPushButton(centralWidget);
        pushButton_13->setObjectName(QStringLiteral("pushButton_13"));
        pushButton_13->setGeometry(QRect(910, 50, 81, 41));
        horizontalSlider = new timelineSlider(centralWidget);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(780, 410, 301, 31));
        horizontalSlider->setOrientation(Qt::Horizontal);
        horizontalSlider->setTickPosition(QSlider::TicksBelow);
        horizontalSlider->setTickInterval(4);
        listWidget = new KeyFramesListWidget(centralWidget);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(790, 100, 291, 311));
        label_25 = new QLabel(centralWidget);
        label_25->setObjectName(QStringLiteral("label_25"));
        label_25->setGeometry(QRect(900, 30, 91, 16));
        TimelineKeyFrameCount = new QSpinBox(centralWidget);
        TimelineKeyFrameCount->setObjectName(QStringLiteral("TimelineKeyFrameCount"));
        TimelineKeyFrameCount->setGeometry(QRect(790, 70, 47, 24));
        TimelineKeyFrameCount->setMaximum(360);
        TimelineKeyFrameCount->setValue(100);
        pushButton_14 = new QPushButton(centralWidget);
        pushButton_14->setObjectName(QStringLiteral("pushButton_14"));
        pushButton_14->setGeometry(QRect(940, 440, 131, 41));
        label_26 = new QLabel(centralWidget);
        label_26->setObjectName(QStringLiteral("label_26"));
        label_26->setGeometry(QRect(810, 450, 59, 16));
        edgeList = new MeshQListWidget(centralWidget);
        edgeList->setObjectName(QStringLiteral("edgeList"));
        edgeList->setGeometry(QRect(40, 560, 151, 151));
        sizePolicy.setHeightForWidth(edgeList->sizePolicy().hasHeightForWidth());
        edgeList->setSizePolicy(sizePolicy);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(90, 540, 51, 16));
        QFont font;
        font.setFamily(QStringLiteral("Century Gothic"));
        label_3->setFont(font);
        showSym = new QPushButton(centralWidget);
        showSym->setObjectName(QStringLiteral("showSym"));
        showSym->setGeometry(QRect(30, 730, 71, 32));
        showNext = new QPushButton(centralWidget);
        showNext->setObjectName(QStringLiteral("showNext"));
        showNext->setGeometry(QRect(30, 790, 71, 32));
        pushButton_6 = new QPushButton(centralWidget);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(30, 760, 71, 32));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(100, 730, 91, 91));
        mygl = new MyGL(centralWidget);
        mygl->setObjectName(QStringLiteral("mygl"));
        mygl->setGeometry(QRect(-10, 20, 761, 491));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(1);
        sizePolicy1.setVerticalStretch(1);
        sizePolicy1.setHeightForWidth(mygl->sizePolicy().hasHeightForWidth());
        mygl->setSizePolicy(sizePolicy1);
        mygl->setMinimumSize(QSize(618, 432));
        vertexList = new MeshQListWidget(centralWidget);
        vertexList->setObjectName(QStringLiteral("vertexList"));
        vertexList->setGeometry(QRect(220, 560, 151, 151));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(260, 540, 101, 21));
        label_2->setFont(font);
        pushButton_9 = new QPushButton(centralWidget);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));
        pushButton_9->setGeometry(QRect(240, 720, 101, 32));
        shift_to_barycenter = new QPushButton(centralWidget);
        shift_to_barycenter->setObjectName(QStringLiteral("shift_to_barycenter"));
        shift_to_barycenter->setGeometry(QRect(220, 810, 141, 32));
        pushButton_7 = new QPushButton(centralWidget);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setGeometry(QRect(240, 750, 101, 32));
        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(240, 780, 101, 32));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(450, 540, 51, 16));
        QFont font1;
        font1.setFamily(QStringLiteral("Apple Braille"));
        label->setFont(font1);
        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(400, 710, 21, 101));
        label_9->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        verticalSlider = new QSlider(centralWidget);
        verticalSlider->setObjectName(QStringLiteral("verticalSlider"));
        verticalSlider->setGeometry(QRect(420, 720, 22, 91));
        verticalSlider->setMaximum(255);
        verticalSlider->setSingleStep(5);
        verticalSlider->setValue(255);
        verticalSlider->setOrientation(Qt::Vertical);
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(450, 720, 20, 81));
        label_8->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        verticalSlider_2 = new QSlider(centralWidget);
        verticalSlider_2->setObjectName(QStringLiteral("verticalSlider_2"));
        verticalSlider_2->setGeometry(QRect(470, 720, 22, 91));
        verticalSlider_2->setMaximum(255);
        verticalSlider_2->setSingleStep(5);
        verticalSlider_2->setValue(255);
        verticalSlider_2->setOrientation(Qt::Vertical);
        verticalSlider_2->setInvertedControls(false);
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(500, 710, 20, 101));
        label_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        verticalSlider_3 = new QSlider(centralWidget);
        verticalSlider_3->setObjectName(QStringLiteral("verticalSlider_3"));
        verticalSlider_3->setGeometry(QRect(520, 720, 22, 91));
        verticalSlider_3->setMaximum(255);
        verticalSlider_3->setSingleStep(5);
        verticalSlider_3->setValue(255);
        verticalSlider_3->setOrientation(Qt::Vertical);
        faceList = new MeshQListWidget(centralWidget);
        faceList->setObjectName(QStringLiteral("faceList"));
        faceList->setGeometry(QRect(400, 560, 151, 151));
        pushButton_5 = new QPushButton(centralWidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(590, 730, 131, 51));
        pushButton_5->setFont(font1);
        pushButton_8 = new QPushButton(centralWidget);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setGeometry(QRect(380, 810, 101, 32));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(470, 810, 101, 32));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(790, 50, 121, 16));
        label_15 = new QLabel(centralWidget);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(860, 450, 51, 16));
        label_15->setFont(font1);
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(800, 480, 314, 361));
        verticalLayout_4 = new QVBoxLayout(layoutWidget);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        label_19 = new QLabel(layoutWidget);
        label_19->setObjectName(QStringLiteral("label_19"));

        verticalLayout_6->addWidget(label_19);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_16 = new QLabel(layoutWidget);
        label_16->setObjectName(QStringLiteral("label_16"));

        horizontalLayout_5->addWidget(label_16);

        jointX = new QDoubleSpinBox(layoutWidget);
        jointX->setObjectName(QStringLiteral("jointX"));
        jointX->setDecimals(3);
        jointX->setMinimum(-99);
        jointX->setSingleStep(0.1);

        horizontalLayout_5->addWidget(jointX);

        label_17 = new QLabel(layoutWidget);
        label_17->setObjectName(QStringLiteral("label_17"));

        horizontalLayout_5->addWidget(label_17);

        doubleSpinBox_4 = new QDoubleSpinBox(layoutWidget);
        doubleSpinBox_4->setObjectName(QStringLiteral("doubleSpinBox_4"));
        doubleSpinBox_4->setDecimals(3);
        doubleSpinBox_4->setMinimum(-99);
        doubleSpinBox_4->setSingleStep(0.1);

        horizontalLayout_5->addWidget(doubleSpinBox_4);

        label_18 = new QLabel(layoutWidget);
        label_18->setObjectName(QStringLiteral("label_18"));

        horizontalLayout_5->addWidget(label_18);

        doubleSpinBox_6 = new QDoubleSpinBox(layoutWidget);
        doubleSpinBox_6->setObjectName(QStringLiteral("doubleSpinBox_6"));
        doubleSpinBox_6->setDecimals(3);
        doubleSpinBox_6->setMinimum(-99);
        doubleSpinBox_6->setSingleStep(0.1);

        horizontalLayout_5->addWidget(doubleSpinBox_6);


        verticalLayout_6->addLayout(horizontalLayout_5);

        label_23 = new QLabel(layoutWidget);
        label_23->setObjectName(QStringLiteral("label_23"));

        verticalLayout_6->addWidget(label_23);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_20 = new QLabel(layoutWidget);
        label_20->setObjectName(QStringLiteral("label_20"));

        horizontalLayout_6->addWidget(label_20);

        doubleSpinBox_7 = new QDoubleSpinBox(layoutWidget);
        doubleSpinBox_7->setObjectName(QStringLiteral("doubleSpinBox_7"));
        doubleSpinBox_7->setMinimum(0);
        doubleSpinBox_7->setMaximum(180);
        doubleSpinBox_7->setSingleStep(0.1);

        horizontalLayout_6->addWidget(doubleSpinBox_7);

        label_21 = new QLabel(layoutWidget);
        label_21->setObjectName(QStringLiteral("label_21"));

        horizontalLayout_6->addWidget(label_21);

        doubleSpinBox_5 = new QDoubleSpinBox(layoutWidget);
        doubleSpinBox_5->setObjectName(QStringLiteral("doubleSpinBox_5"));
        doubleSpinBox_5->setMinimum(0);
        doubleSpinBox_5->setMaximum(180);
        doubleSpinBox_5->setSingleStep(0.1);

        horizontalLayout_6->addWidget(doubleSpinBox_5);

        label_22 = new QLabel(layoutWidget);
        label_22->setObjectName(QStringLiteral("label_22"));

        horizontalLayout_6->addWidget(label_22);

        doubleSpinBox_8 = new QDoubleSpinBox(layoutWidget);
        doubleSpinBox_8->setObjectName(QStringLiteral("doubleSpinBox_8"));
        doubleSpinBox_8->setMinimum(0);
        doubleSpinBox_8->setMaximum(180);
        doubleSpinBox_8->setSingleStep(0.1);

        horizontalLayout_6->addWidget(doubleSpinBox_8);


        verticalLayout_6->addLayout(horizontalLayout_6);


        verticalLayout_4->addLayout(verticalLayout_6);

        treeWidget = new jointQTreeWidget(layoutWidget);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QStringLiteral("1"));
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName(QStringLiteral("treeWidget"));

        verticalLayout_4->addWidget(treeWidget);

        pushButton_11 = new QPushButton(centralWidget);
        pushButton_11->setObjectName(QStringLiteral("pushButton_11"));
        pushButton_11->setGeometry(QRect(590, 610, 141, 32));
        pushButton_10 = new QPushButton(centralWidget);
        pushButton_10->setObjectName(QStringLiteral("pushButton_10"));
        pushButton_10->setGeometry(QRect(580, 550, 161, 32));
        pushButton_4 = new QPushButton(centralWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(590, 780, 131, 51));
        checkBox = new QCheckBox(centralWidget);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setGeometry(QRect(580, 580, 161, 20));
        QFont font2;
        font2.setPointSize(9);
        checkBox->setFont(font2);
        importJoints = new QPushButton(centralWidget);
        importJoints->setObjectName(QStringLiteral("importJoints"));
        importJoints->setGeometry(QRect(590, 640, 141, 32));
        bindButton = new QPushButton(centralWidget);
        bindButton->setObjectName(QStringLiteral("bindButton"));
        bindButton->setGeometry(QRect(590, 670, 141, 32));
        pushButton_12 = new QPushButton(centralWidget);
        pushButton_12->setObjectName(QStringLiteral("pushButton_12"));
        pushButton_12->setGeometry(QRect(1000, 20, 91, 71));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(840, 70, 41, 16));
        pushButton_15 = new QPushButton(centralWidget);
        pushButton_15->setObjectName(QStringLiteral("pushButton_15"));
        pushButton_15->setGeometry(QRect(590, 700, 141, 32));
        refractiveindex = new QDoubleSpinBox(centralWidget);
        refractiveindex->setObjectName(QStringLiteral("refractiveindex"));
        refractiveindex->setGeometry(QRect(730, 640, 66, 24));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(730, 620, 59, 16));
        doubleSpinBox = new QDoubleSpinBox(centralWidget);
        doubleSpinBox->setObjectName(QStringLiteral("doubleSpinBox"));
        doubleSpinBox->setGeometry(QRect(730, 690, 66, 24));
        label_10 = new QLabel(centralWidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(730, 670, 59, 16));
        MeshList = new MeshQListWidget(centralWidget);
        MeshList->setObjectName(QStringLiteral("MeshList"));
        MeshList->setGeometry(QRect(1100, 30, 151, 391));
        label_11 = new QLabel(centralWidget);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(1100, 10, 59, 16));
        pushButton_16 = new QPushButton(centralWidget);
        pushButton_16->setObjectName(QStringLiteral("pushButton_16"));
        pushButton_16->setGeometry(QRect(20, 510, 211, 32));
        meshTab = new QTabWidget(centralWidget);
        meshTab->setObjectName(QStringLiteral("meshTab"));
        meshTab->setGeometry(QRect(1110, 430, 221, 131));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        meshMoveX = new QDoubleSpinBox(tab);
        meshMoveX->setObjectName(QStringLiteral("meshMoveX"));
        meshMoveX->setGeometry(QRect(60, 10, 66, 24));
        meshMoveY = new QDoubleSpinBox(tab);
        meshMoveY->setObjectName(QStringLiteral("meshMoveY"));
        meshMoveY->setGeometry(QRect(60, 40, 66, 24));
        meshMoveZ = new QDoubleSpinBox(tab);
        meshMoveZ->setObjectName(QStringLiteral("meshMoveZ"));
        meshMoveZ->setGeometry(QRect(60, 70, 66, 24));
        label_12 = new QLabel(tab);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(10, 10, 31, 16));
        label_13 = new QLabel(tab);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(10, 40, 59, 16));
        label_14 = new QLabel(tab);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(10, 70, 59, 16));
        meshTab->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        rotateX = new QDoubleSpinBox(tab_2);
        rotateX->setObjectName(QStringLiteral("rotateX"));
        rotateX->setGeometry(QRect(80, 10, 66, 24));
        rotateY = new QDoubleSpinBox(tab_2);
        rotateY->setObjectName(QStringLiteral("rotateY"));
        rotateY->setGeometry(QRect(80, 40, 66, 24));
        rotateZ = new QDoubleSpinBox(tab_2);
        rotateZ->setObjectName(QStringLiteral("rotateZ"));
        rotateZ->setGeometry(QRect(80, 70, 66, 24));
        label_24 = new QLabel(tab_2);
        label_24->setObjectName(QStringLiteral("label_24"));
        label_24->setGeometry(QRect(30, 10, 31, 16));
        label_27 = new QLabel(tab_2);
        label_27->setObjectName(QStringLiteral("label_27"));
        label_27->setGeometry(QRect(30, 40, 51, 20));
        label_28 = new QLabel(tab_2);
        label_28->setObjectName(QStringLiteral("label_28"));
        label_28->setGeometry(QRect(30, 80, 59, 16));
        meshTab->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        scaleMeshX = new QDoubleSpinBox(tab_3);
        scaleMeshX->setObjectName(QStringLiteral("scaleMeshX"));
        scaleMeshX->setGeometry(QRect(110, 10, 66, 24));
        scaleMeshY = new QDoubleSpinBox(tab_3);
        scaleMeshY->setObjectName(QStringLiteral("scaleMeshY"));
        scaleMeshY->setGeometry(QRect(110, 40, 66, 24));
        scaleMeshZ = new QDoubleSpinBox(tab_3);
        scaleMeshZ->setObjectName(QStringLiteral("scaleMeshZ"));
        scaleMeshZ->setGeometry(QRect(110, 70, 66, 24));
        label_29 = new QLabel(tab_3);
        label_29->setObjectName(QStringLiteral("label_29"));
        label_29->setGeometry(QRect(40, 70, 59, 16));
        label_30 = new QLabel(tab_3);
        label_30->setObjectName(QStringLiteral("label_30"));
        label_30->setGeometry(QRect(40, 50, 59, 16));
        label_31 = new QLabel(tab_3);
        label_31->setObjectName(QStringLiteral("label_31"));
        label_31->setGeometry(QRect(40, 20, 31, 16));
        meshTab->addTab(tab_3, QString());
        pushButton_17 = new QPushButton(centralWidget);
        pushButton_17->setObjectName(QStringLiteral("pushButton_17"));
        pushButton_17->setGeometry(QRect(250, 510, 115, 32));
        pushButton_18 = new QPushButton(centralWidget);
        pushButton_18->setObjectName(QStringLiteral("pushButton_18"));
        pushButton_18->setGeometry(QRect(380, 510, 115, 32));
        pushButton_19 = new QPushButton(centralWidget);
        pushButton_19->setObjectName(QStringLiteral("pushButton_19"));
        pushButton_19->setGeometry(QRect(500, 510, 115, 32));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1348, 22));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(actionQuit);

        retranslateUi(MainWindow);
        QObject::connect(mygl, SIGNAL(sig_SendFace(QListWidgetItem*)), faceList, SLOT(slot_addFace(QListWidgetItem*)));
        QObject::connect(mygl, SIGNAL(sig_SendVertex(QListWidgetItem*)), vertexList, SLOT(slot_addVertex(QListWidgetItem*)));
        QObject::connect(pushButton, SIGNAL(clicked()), mygl, SLOT(slot_AddVertex()));
        QObject::connect(faceList, SIGNAL(itemClicked(QListWidgetItem*)), mygl, SLOT(slot_ReceiveSelectedFace(QListWidgetItem*)));
        QObject::connect(vertexList, SIGNAL(itemClicked(QListWidgetItem*)), mygl, SLOT(slot_ReceiveSelectedVertex(QListWidgetItem*)));
        QObject::connect(showSym, SIGNAL(clicked()), mygl, SLOT(slot_showSym()));
        QObject::connect(showNext, SIGNAL(clicked()), mygl, SLOT(slot_showNext()));
        QObject::connect(pushButton_6, SIGNAL(clicked()), mygl, SLOT(slot_showSelectedHalfEdgeFace()));
        QObject::connect(mygl, SIGNAL(sig_sendNewlySelectedFace(QListWidgetItem*)), faceList, SLOT(slot_selectFace(QListWidgetItem*)));
        QObject::connect(mygl, SIGNAL(sig_restartFaces()), faceList, SLOT(slot_restartFaces()));
        QObject::connect(pushButton_5, SIGNAL(clicked()), mygl, SLOT(slot_quadrangulate()));
        QObject::connect(pushButton_4, SIGNAL(clicked()), mygl, SLOT(slot_smoothMesh()));
        QObject::connect(mygl, SIGNAL(sig_ResetB(int)), verticalSlider_3, SLOT(setValue(int)));
        QObject::connect(mygl, SIGNAL(sig_ResetR(int)), verticalSlider, SLOT(setValue(int)));
        QObject::connect(verticalSlider_3, SIGNAL(valueChanged(int)), mygl, SLOT(slot_updateB(int)));
        QObject::connect(verticalSlider_2, SIGNAL(valueChanged(int)), mygl, SLOT(slot_updateG(int)));
        QObject::connect(verticalSlider, SIGNAL(valueChanged(int)), mygl, SLOT(slot_updateR(int)));
        QObject::connect(pushButton_3, SIGNAL(clicked()), mygl, SLOT(slot_deleteVertex()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), mygl, SLOT(slot_triangulateFace()));
        QObject::connect(mygl, SIGNAL(sig_SendHalfEdge(QListWidgetItem*)), edgeList, SLOT(slot_addHalfEdge(QListWidgetItem*)));
        QObject::connect(edgeList, SIGNAL(itemClicked(QListWidgetItem*)), mygl, SLOT(slot_ReceiveSelectedHalfEdge(QListWidgetItem*)));
        QObject::connect(shift_to_barycenter, SIGNAL(clicked()), mygl, SLOT(slot_shiftToBarycenter()));
        QObject::connect(mygl, SIGNAL(sig_ResetG(int)), verticalSlider_2, SLOT(setValue(int)));
        QObject::connect(pushButton_8, SIGNAL(clicked()), mygl, SLOT(slot_showStartEdge()));
        QObject::connect(pushButton_9, SIGNAL(clicked()), mygl, SLOT(slot_showVertexFace()));
        QObject::connect(pushButton_7, SIGNAL(clicked()), mygl, SLOT(slot_showEdge()));
        QObject::connect(mygl, SIGNAL(sig_sendNewlySelectedHalfEdge(QListWidgetItem*)), edgeList, SLOT(slot_selectHalfEdge(QListWidgetItem*)));
        QObject::connect(pushButton_10, SIGNAL(clicked()), mygl, SLOT(slot_importObjFile()));
        QObject::connect(pushButton_11, SIGNAL(clicked()), mygl, SLOT(slot_exportObjFile()));
        QObject::connect(importJoints, SIGNAL(clicked()), mygl, SLOT(slot_importJSONFile()));
        QObject::connect(bindButton, SIGNAL(clicked()), mygl, SLOT(slot_calculateBindMatrices()));
        QObject::connect(mygl, SIGNAL(sig_sendRootJoint(QTreeWidgetItem*)), treeWidget, SLOT(slot_addRootJoint(QTreeWidgetItem*)));
        QObject::connect(bindButton, SIGNAL(clicked()), treeWidget, SLOT(slot_bindJoints()));
        QObject::connect(treeWidget, SIGNAL(itemClicked(QTreeWidgetItem*,int)), mygl, SLOT(slot_receiveSelectedJoint(QTreeWidgetItem*,int)));
        QObject::connect(mygl, SIGNAL(sig_sendJointX(double)), jointX, SLOT(setValue(double)));
        QObject::connect(mygl, SIGNAL(sig_sendJointY(double)), doubleSpinBox_4, SLOT(setValue(double)));
        QObject::connect(mygl, SIGNAL(sig_sendJointZ(double)), doubleSpinBox_6, SLOT(setValue(double)));
        QObject::connect(jointX, SIGNAL(valueChanged(double)), mygl, SLOT(slot_updateJointX(double)));
        QObject::connect(doubleSpinBox_4, SIGNAL(valueChanged(double)), mygl, SLOT(slot_updateJointY(double)));
        QObject::connect(doubleSpinBox_6, SIGNAL(valueChanged(double)), mygl, SLOT(slot_updateJointZ(double)));
        QObject::connect(checkBox, SIGNAL(clicked()), mygl, SLOT(slot_setDisplayCowVertices()));
        QObject::connect(mygl, SIGNAL(sig_sendJointRoX(double)), doubleSpinBox_7, SLOT(setValue(double)));
        QObject::connect(mygl, SIGNAL(sig_sendJointRoY(double)), doubleSpinBox_5, SLOT(setValue(double)));
        QObject::connect(doubleSpinBox_7, SIGNAL(valueChanged(double)), mygl, SLOT(slot_updateJointRoX(double)));
        QObject::connect(doubleSpinBox_5, SIGNAL(valueChanged(double)), mygl, SLOT(slot_updateJointRoY(double)));
        QObject::connect(doubleSpinBox_8, SIGNAL(valueChanged(double)), mygl, SLOT(slot_updateJointRoZ(double)));
        QObject::connect(mygl, SIGNAL(sig_sendJointRoZ(double)), doubleSpinBox_8, SLOT(setValue(double)));
        QObject::connect(TimelineKeyFrameCount, SIGNAL(valueChanged(int)), mygl, SLOT(slot_receiveNumFrames(int)));
        QObject::connect(pushButton_13, SIGNAL(clicked()), mygl, SLOT(slot_createFrameTimeline()));
        QObject::connect(mygl, SIGNAL(sig_sendFrame(QListWidgetItem*)), listWidget, SLOT(slot_receiveFrame(QListWidgetItem*)));
        QObject::connect(pushButton_14, SIGNAL(clicked()), mygl, SLOT(slot_createNewKeyFrame()));
        QObject::connect(listWidget, SIGNAL(itemClicked(QListWidgetItem*)), mygl, SLOT(slot_receiveSelectedFrame(QListWidgetItem*)));
        QObject::connect(treeWidget, SIGNAL(itemClicked(QTreeWidgetItem*,int)), listWidget, SLOT(slot_receiveSelectedJoint(QTreeWidgetItem*)));
        QObject::connect(listWidget, SIGNAL(itemClicked(QListWidgetItem*)), listWidget, SLOT(slot_updateColors(QListWidgetItem*)));
        QObject::connect(mygl, SIGNAL(sig_makeNewTimeline()), listWidget, SLOT(slot_createNewTimeline()));
        QObject::connect(importJoints, SIGNAL(clicked()), listWidget, SLOT(reset()));
        QObject::connect(pushButton_12, SIGNAL(clicked()), listWidget, SLOT(slot_loopThroughFrames()));
        QObject::connect(pushButton_15, SIGNAL(clicked()), mygl, SLOT(slot_exportBMP()));
        QObject::connect(refractiveindex, SIGNAL(valueChanged(double)), mygl, SLOT(slot_updateRefraction(double)));
        QObject::connect(doubleSpinBox, SIGNAL(valueChanged(double)), mygl, SLOT(slot_updateReflection(double)));
        QObject::connect(mygl, SIGNAL(sig_sendMesh(QListWidgetItem*)), MeshList, SLOT(slot_addMesh(QListWidgetItem*)));
        QObject::connect(MeshList, SIGNAL(itemClicked(QListWidgetItem*)), mygl, SLOT(slot_selectMesh(QListWidgetItem*)));
        QObject::connect(pushButton_16, SIGNAL(clicked()), mygl, SLOT(slot_insertEdgeLoop()));
        QObject::connect(scaleMeshX, SIGNAL(valueChanged(double)), mygl, SLOT(slot_meshScaleX(double)));
        QObject::connect(scaleMeshY, SIGNAL(valueChanged(double)), mygl, SLOT(slot_meshScaleY(double)));
        QObject::connect(scaleMeshZ, SIGNAL(valueChanged(double)), mygl, SLOT(slot_meshScaleZ(double)));
        QObject::connect(pushButton_17, SIGNAL(clicked()), mygl, SLOT(slot_extrudeFace()));
        QObject::connect(pushButton_18, SIGNAL(clicked()), mygl, SLOT(slot_extrudeEdge()));
        QObject::connect(pushButton_19, SIGNAL(clicked()), mygl, SLOT(slot_bevelEdge()));

        meshTab->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "OpenGLDemo", 0));
        actionQuit->setText(QApplication::translate("MainWindow", "Quit", 0));
        actionQuit->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", 0));
        pushButton_13->setText(QApplication::translate("MainWindow", "boop.", 0));
        label_25->setText(QApplication::translate("MainWindow", "TIMELINE", 0));
        pushButton_14->setText(QApplication::translate("MainWindow", "Create Keyframe", 0));
        label_26->setText(QString());
        label_3->setText(QApplication::translate("MainWindow", "EDGES", 0));
        showSym->setText(QApplication::translate("MainWindow", "| | Sym", 0));
        showNext->setText(QApplication::translate("MainWindow", "-> Next", 0));
        pushButton_6->setText(QApplication::translate("MainWindow", "[ ] Face", 0));
        pushButton->setText(QApplication::translate("MainWindow", "Add \n"
"Vertex", 0));
        label_2->setText(QApplication::translate("MainWindow", "VERTICES", 0));
        pushButton_9->setText(QApplication::translate("MainWindow", "[ ] Face", 0));
        shift_to_barycenter->setText(QApplication::translate("MainWindow", "Shift to Barycenter", 0));
        pushButton_7->setText(QApplication::translate("MainWindow", "| Edge", 0));
        pushButton_3->setText(QApplication::translate("MainWindow", "Delete D:", 0));
        label->setText(QApplication::translate("MainWindow", "FACES", 0));
        label_9->setText(QApplication::translate("MainWindow", "R", 0));
        label_8->setText(QApplication::translate("MainWindow", "G", 0));
        label_7->setText(QApplication::translate("MainWindow", "B", 0));
        pushButton_5->setText(QApplication::translate("MainWindow", "Eventually \n"
"Quadrangulate", 0));
        pushButton_8->setText(QApplication::translate("MainWindow", "| Start Edge", 0));
        pushButton_2->setText(QApplication::translate("MainWindow", "Triangulate", 0));
        label_4->setText(QApplication::translate("MainWindow", "Make new timeline:", 0));
        label_15->setText(QApplication::translate("MainWindow", "JOINTS ", 0));
        label_19->setText(QApplication::translate("MainWindow", "I don't speak cow (translations)", 0));
        label_16->setText(QApplication::translate("MainWindow", "X", 0));
        label_17->setText(QApplication::translate("MainWindow", "Y", 0));
        label_18->setText(QApplication::translate("MainWindow", "Z", 0));
        label_23->setText(QApplication::translate("MainWindow", "Rotations", 0));
        label_20->setText(QApplication::translate("MainWindow", "X", 0));
        label_21->setText(QApplication::translate("MainWindow", "Y", 0));
        label_22->setText(QApplication::translate("MainWindow", "Z", 0));
        pushButton_11->setText(QApplication::translate("MainWindow", "EXPORT AS OBJ", 0));
        pushButton_10->setText(QApplication::translate("MainWindow", "MOO. (IMPORT OBJ)", 0));
        pushButton_4->setText(QApplication::translate("MainWindow", "MEOW.", 0));
        checkBox->setText(QApplication::translate("MainWindow", "Display vertices (be prepared)", 0));
        importJoints->setText(QApplication::translate("MainWindow", "IMPORT JOINTS", 0));
        bindButton->setText(QApplication::translate("MainWindow", "BIND", 0));
        pushButton_12->setText(QApplication::translate("MainWindow", "PLAY", 0));
        label_5->setText(QApplication::translate("MainWindow", "frames", 0));
        pushButton_15->setText(QApplication::translate("MainWindow", "Raytrace", 0));
        label_6->setText(QApplication::translate("MainWindow", "Refract", 0));
        label_10->setText(QApplication::translate("MainWindow", "Reflect", 0));
        label_11->setText(QApplication::translate("MainWindow", "Mesh", 0));
        pushButton_16->setText(QApplication::translate("MainWindow", "Insert Edge Loop", 0));
        label_12->setText(QApplication::translate("MainWindow", "x", 0));
        label_13->setText(QApplication::translate("MainWindow", "y", 0));
        label_14->setText(QApplication::translate("MainWindow", "z", 0));
        meshTab->setTabText(meshTab->indexOf(tab), QApplication::translate("MainWindow", "translate", 0));
        label_24->setText(QApplication::translate("MainWindow", "x", 0));
        label_27->setText(QApplication::translate("MainWindow", "y", 0));
        label_28->setText(QApplication::translate("MainWindow", "z", 0));
        meshTab->setTabText(meshTab->indexOf(tab_2), QApplication::translate("MainWindow", "rotate", 0));
        label_29->setText(QApplication::translate("MainWindow", "z", 0));
        label_30->setText(QApplication::translate("MainWindow", "y", 0));
        label_31->setText(QApplication::translate("MainWindow", "x", 0));
        meshTab->setTabText(meshTab->indexOf(tab_3), QApplication::translate("MainWindow", "scale", 0));
        pushButton_17->setText(QApplication::translate("MainWindow", "Extrude Face", 0));
        pushButton_18->setText(QApplication::translate("MainWindow", "Extrude Edge", 0));
        pushButton_19->setText(QApplication::translate("MainWindow", "Bevel Edge", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
