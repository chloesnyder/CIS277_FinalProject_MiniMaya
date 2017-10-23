/****************************************************************************
** Meta object code from reading C++ file 'mygl.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "src/mygl.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mygl.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MyGL_t {
    QByteArrayData data[120];
    char stringdata[1648];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MyGL_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MyGL_t qt_meta_stringdata_MyGL = {
    {
QT_MOC_LITERAL(0, 0, 4), // "MyGL"
QT_MOC_LITERAL(1, 5, 16), // "sig_SendHalfEdge"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(4, 40, 9), // "half_edge"
QT_MOC_LITERAL(5, 50, 14), // "sig_SendVertex"
QT_MOC_LITERAL(6, 65, 6), // "vertex"
QT_MOC_LITERAL(7, 72, 12), // "sig_SendFace"
QT_MOC_LITERAL(8, 85, 4), // "face"
QT_MOC_LITERAL(9, 90, 17), // "sig_ResetSpinBoxX"
QT_MOC_LITERAL(10, 108, 4), // "curX"
QT_MOC_LITERAL(11, 113, 17), // "sig_ResetSpinBoxY"
QT_MOC_LITERAL(12, 131, 4), // "curY"
QT_MOC_LITERAL(13, 136, 17), // "sig_ResetSpinBoxZ"
QT_MOC_LITERAL(14, 154, 4), // "curZ"
QT_MOC_LITERAL(15, 159, 10), // "sig_ResetR"
QT_MOC_LITERAL(16, 170, 1), // "R"
QT_MOC_LITERAL(17, 172, 10), // "sig_ResetG"
QT_MOC_LITERAL(18, 183, 1), // "G"
QT_MOC_LITERAL(19, 185, 10), // "sig_ResetB"
QT_MOC_LITERAL(20, 196, 1), // "B"
QT_MOC_LITERAL(21, 198, 25), // "sig_sendNewlySelectedFace"
QT_MOC_LITERAL(22, 224, 16), // "sig_restartFaces"
QT_MOC_LITERAL(23, 241, 29), // "sig_sendNewlySelectedHalfEdge"
QT_MOC_LITERAL(24, 271, 8), // "halfedge"
QT_MOC_LITERAL(25, 280, 19), // "sig_sendListOfFaces"
QT_MOC_LITERAL(26, 300, 23), // "QList<QListWidgetItem*>"
QT_MOC_LITERAL(27, 324, 9), // "facesList"
QT_MOC_LITERAL(28, 334, 17), // "sig_sendRootJoint"
QT_MOC_LITERAL(29, 352, 16), // "QTreeWidgetItem*"
QT_MOC_LITERAL(30, 369, 4), // "root"
QT_MOC_LITERAL(31, 374, 14), // "sig_sendJointX"
QT_MOC_LITERAL(32, 389, 2), // "jx"
QT_MOC_LITERAL(33, 392, 14), // "sig_sendJointY"
QT_MOC_LITERAL(34, 407, 2), // "jy"
QT_MOC_LITERAL(35, 410, 14), // "sig_sendJointZ"
QT_MOC_LITERAL(36, 425, 2), // "jz"
QT_MOC_LITERAL(37, 428, 16), // "sig_sendJointRoX"
QT_MOC_LITERAL(38, 445, 3), // "roX"
QT_MOC_LITERAL(39, 449, 16), // "sig_sendJointRoY"
QT_MOC_LITERAL(40, 466, 3), // "roY"
QT_MOC_LITERAL(41, 470, 16), // "sig_sendJointRoZ"
QT_MOC_LITERAL(42, 487, 3), // "roZ"
QT_MOC_LITERAL(43, 491, 19), // "sig_makeNewTimeline"
QT_MOC_LITERAL(44, 511, 13), // "sig_sendFrame"
QT_MOC_LITERAL(45, 525, 5), // "frame"
QT_MOC_LITERAL(46, 531, 12), // "sig_sendMesh"
QT_MOC_LITERAL(47, 544, 1), // "m"
QT_MOC_LITERAL(48, 546, 28), // "slot_ReceiveSelectedHalfEdge"
QT_MOC_LITERAL(49, 575, 26), // "slot_ReceiveSelectedVertex"
QT_MOC_LITERAL(50, 602, 24), // "slot_ReceiveSelectedFace"
QT_MOC_LITERAL(51, 627, 14), // "slot_AddVertex"
QT_MOC_LITERAL(52, 642, 16), // "slot_updateVertX"
QT_MOC_LITERAL(53, 659, 2), // "dx"
QT_MOC_LITERAL(54, 662, 16), // "slot_updateVertY"
QT_MOC_LITERAL(55, 679, 2), // "dy"
QT_MOC_LITERAL(56, 682, 16), // "slot_updateVertZ"
QT_MOC_LITERAL(57, 699, 2), // "dz"
QT_MOC_LITERAL(58, 702, 20), // "slot_triangulateFace"
QT_MOC_LITERAL(59, 723, 17), // "slot_deleteVertex"
QT_MOC_LITERAL(60, 741, 12), // "slot_updateR"
QT_MOC_LITERAL(61, 754, 12), // "slot_updateG"
QT_MOC_LITERAL(62, 767, 12), // "slot_updateB"
QT_MOC_LITERAL(63, 780, 22), // "slot_shiftToBarycenter"
QT_MOC_LITERAL(64, 803, 18), // "slot_quadrangulate"
QT_MOC_LITERAL(65, 822, 12), // "slot_showSym"
QT_MOC_LITERAL(66, 835, 13), // "slot_showNext"
QT_MOC_LITERAL(67, 849, 29), // "slot_showSelectedHalfEdgeFace"
QT_MOC_LITERAL(68, 879, 15), // "slot_smoothMesh"
QT_MOC_LITERAL(69, 895, 14), // "slot_discoTime"
QT_MOC_LITERAL(70, 910, 13), // "slot_showEdge"
QT_MOC_LITERAL(71, 924, 18), // "slot_showStartEdge"
QT_MOC_LITERAL(72, 943, 19), // "slot_showVertexFace"
QT_MOC_LITERAL(73, 963, 18), // "slot_importObjFile"
QT_MOC_LITERAL(74, 982, 18), // "slot_exportObjFile"
QT_MOC_LITERAL(75, 1001, 26), // "slot_setDisplayCowVertices"
QT_MOC_LITERAL(76, 1028, 21), // "slot_receiveNumFrames"
QT_MOC_LITERAL(77, 1050, 1), // "i"
QT_MOC_LITERAL(78, 1052, 24), // "slot_createFrameTimeline"
QT_MOC_LITERAL(79, 1077, 19), // "slot_importJSONFile"
QT_MOC_LITERAL(80, 1097, 14), // "traverseJoints"
QT_MOC_LITERAL(81, 1112, 6), // "Joint*"
QT_MOC_LITERAL(82, 1119, 5), // "joint"
QT_MOC_LITERAL(83, 1125, 9), // "glm::mat4"
QT_MOC_LITERAL(84, 1135, 1), // "T"
QT_MOC_LITERAL(85, 1137, 26), // "slot_calculateBindMatrices"
QT_MOC_LITERAL(86, 1164, 25), // "slot_receiveSelectedJoint"
QT_MOC_LITERAL(87, 1190, 17), // "slot_updateJointX"
QT_MOC_LITERAL(88, 1208, 17), // "slot_updateJointY"
QT_MOC_LITERAL(89, 1226, 17), // "slot_updateJointZ"
QT_MOC_LITERAL(90, 1244, 19), // "slot_updateJointRoX"
QT_MOC_LITERAL(91, 1264, 2), // "rx"
QT_MOC_LITERAL(92, 1267, 19), // "slot_updateJointRoY"
QT_MOC_LITERAL(93, 1287, 2), // "ry"
QT_MOC_LITERAL(94, 1290, 19), // "slot_updateJointRoZ"
QT_MOC_LITERAL(95, 1310, 2), // "rz"
QT_MOC_LITERAL(96, 1313, 7), // "Raycast"
QT_MOC_LITERAL(97, 1321, 3), // "Ray"
QT_MOC_LITERAL(98, 1325, 1), // "x"
QT_MOC_LITERAL(99, 1327, 1), // "y"
QT_MOC_LITERAL(100, 1329, 14), // "slot_exportBMP"
QT_MOC_LITERAL(101, 1344, 22), // "slot_createNewKeyFrame"
QT_MOC_LITERAL(102, 1367, 25), // "slot_receiveSelectedFrame"
QT_MOC_LITERAL(103, 1393, 8), // "curFrame"
QT_MOC_LITERAL(104, 1402, 21), // "slot_updateRefraction"
QT_MOC_LITERAL(105, 1424, 1), // "r"
QT_MOC_LITERAL(106, 1426, 21), // "slot_updateReflection"
QT_MOC_LITERAL(107, 1448, 15), // "slot_selectMesh"
QT_MOC_LITERAL(108, 1464, 4), // "mesh"
QT_MOC_LITERAL(109, 1469, 19), // "slot_insertEdgeLoop"
QT_MOC_LITERAL(110, 1489, 19), // "slot_meshTranslateX"
QT_MOC_LITERAL(111, 1509, 19), // "slot_meshTranslateY"
QT_MOC_LITERAL(112, 1529, 19), // "slot_meshTranslateZ"
QT_MOC_LITERAL(113, 1549, 1), // "z"
QT_MOC_LITERAL(114, 1551, 15), // "slot_meshScaleX"
QT_MOC_LITERAL(115, 1567, 15), // "slot_meshScaleY"
QT_MOC_LITERAL(116, 1583, 15), // "slot_meshScaleZ"
QT_MOC_LITERAL(117, 1599, 16), // "slot_extrudeFace"
QT_MOC_LITERAL(118, 1616, 16), // "slot_extrudeEdge"
QT_MOC_LITERAL(119, 1633, 14) // "slot_bevelEdge"

    },
    "MyGL\0sig_SendHalfEdge\0\0QListWidgetItem*\0"
    "half_edge\0sig_SendVertex\0vertex\0"
    "sig_SendFace\0face\0sig_ResetSpinBoxX\0"
    "curX\0sig_ResetSpinBoxY\0curY\0"
    "sig_ResetSpinBoxZ\0curZ\0sig_ResetR\0R\0"
    "sig_ResetG\0G\0sig_ResetB\0B\0"
    "sig_sendNewlySelectedFace\0sig_restartFaces\0"
    "sig_sendNewlySelectedHalfEdge\0halfedge\0"
    "sig_sendListOfFaces\0QList<QListWidgetItem*>\0"
    "facesList\0sig_sendRootJoint\0"
    "QTreeWidgetItem*\0root\0sig_sendJointX\0"
    "jx\0sig_sendJointY\0jy\0sig_sendJointZ\0"
    "jz\0sig_sendJointRoX\0roX\0sig_sendJointRoY\0"
    "roY\0sig_sendJointRoZ\0roZ\0sig_makeNewTimeline\0"
    "sig_sendFrame\0frame\0sig_sendMesh\0m\0"
    "slot_ReceiveSelectedHalfEdge\0"
    "slot_ReceiveSelectedVertex\0"
    "slot_ReceiveSelectedFace\0slot_AddVertex\0"
    "slot_updateVertX\0dx\0slot_updateVertY\0"
    "dy\0slot_updateVertZ\0dz\0slot_triangulateFace\0"
    "slot_deleteVertex\0slot_updateR\0"
    "slot_updateG\0slot_updateB\0"
    "slot_shiftToBarycenter\0slot_quadrangulate\0"
    "slot_showSym\0slot_showNext\0"
    "slot_showSelectedHalfEdgeFace\0"
    "slot_smoothMesh\0slot_discoTime\0"
    "slot_showEdge\0slot_showStartEdge\0"
    "slot_showVertexFace\0slot_importObjFile\0"
    "slot_exportObjFile\0slot_setDisplayCowVertices\0"
    "slot_receiveNumFrames\0i\0"
    "slot_createFrameTimeline\0slot_importJSONFile\0"
    "traverseJoints\0Joint*\0joint\0glm::mat4\0"
    "T\0slot_calculateBindMatrices\0"
    "slot_receiveSelectedJoint\0slot_updateJointX\0"
    "slot_updateJointY\0slot_updateJointZ\0"
    "slot_updateJointRoX\0rx\0slot_updateJointRoY\0"
    "ry\0slot_updateJointRoZ\0rz\0Raycast\0Ray\0"
    "x\0y\0slot_exportBMP\0slot_createNewKeyFrame\0"
    "slot_receiveSelectedFrame\0curFrame\0"
    "slot_updateRefraction\0r\0slot_updateReflection\0"
    "slot_selectMesh\0mesh\0slot_insertEdgeLoop\0"
    "slot_meshTranslateX\0slot_meshTranslateY\0"
    "slot_meshTranslateZ\0z\0slot_meshScaleX\0"
    "slot_meshScaleY\0slot_meshScaleZ\0"
    "slot_extrudeFace\0slot_extrudeEdge\0"
    "slot_bevelEdge"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MyGL[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      77,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      23,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  399,    2, 0x06 /* Public */,
       5,    1,  402,    2, 0x06 /* Public */,
       7,    1,  405,    2, 0x06 /* Public */,
       9,    1,  408,    2, 0x06 /* Public */,
      11,    1,  411,    2, 0x06 /* Public */,
      13,    1,  414,    2, 0x06 /* Public */,
      15,    1,  417,    2, 0x06 /* Public */,
      17,    1,  420,    2, 0x06 /* Public */,
      19,    1,  423,    2, 0x06 /* Public */,
      21,    1,  426,    2, 0x06 /* Public */,
      22,    0,  429,    2, 0x06 /* Public */,
      23,    1,  430,    2, 0x06 /* Public */,
      25,    1,  433,    2, 0x06 /* Public */,
      28,    1,  436,    2, 0x06 /* Public */,
      31,    1,  439,    2, 0x06 /* Public */,
      33,    1,  442,    2, 0x06 /* Public */,
      35,    1,  445,    2, 0x06 /* Public */,
      37,    1,  448,    2, 0x06 /* Public */,
      39,    1,  451,    2, 0x06 /* Public */,
      41,    1,  454,    2, 0x06 /* Public */,
      43,    0,  457,    2, 0x06 /* Public */,
      44,    1,  458,    2, 0x06 /* Public */,
      46,    1,  461,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      48,    1,  464,    2, 0x0a /* Public */,
      49,    1,  467,    2, 0x0a /* Public */,
      50,    1,  470,    2, 0x0a /* Public */,
      51,    0,  473,    2, 0x0a /* Public */,
      52,    1,  474,    2, 0x0a /* Public */,
      54,    1,  477,    2, 0x0a /* Public */,
      56,    1,  480,    2, 0x0a /* Public */,
      58,    0,  483,    2, 0x0a /* Public */,
      59,    0,  484,    2, 0x0a /* Public */,
      60,    1,  485,    2, 0x0a /* Public */,
      61,    1,  488,    2, 0x0a /* Public */,
      62,    1,  491,    2, 0x0a /* Public */,
      63,    0,  494,    2, 0x0a /* Public */,
      64,    0,  495,    2, 0x0a /* Public */,
      65,    0,  496,    2, 0x0a /* Public */,
      66,    0,  497,    2, 0x0a /* Public */,
      67,    0,  498,    2, 0x0a /* Public */,
      68,    0,  499,    2, 0x0a /* Public */,
      69,    0,  500,    2, 0x0a /* Public */,
      70,    0,  501,    2, 0x0a /* Public */,
      71,    0,  502,    2, 0x0a /* Public */,
      72,    0,  503,    2, 0x0a /* Public */,
      73,    0,  504,    2, 0x0a /* Public */,
      74,    0,  505,    2, 0x0a /* Public */,
      75,    0,  506,    2, 0x0a /* Public */,
      76,    1,  507,    2, 0x0a /* Public */,
      78,    0,  510,    2, 0x0a /* Public */,
      79,    0,  511,    2, 0x0a /* Public */,
      80,    2,  512,    2, 0x0a /* Public */,
      85,    0,  517,    2, 0x0a /* Public */,
      86,    2,  518,    2, 0x0a /* Public */,
      87,    1,  523,    2, 0x0a /* Public */,
      88,    1,  526,    2, 0x0a /* Public */,
      89,    1,  529,    2, 0x0a /* Public */,
      90,    1,  532,    2, 0x0a /* Public */,
      92,    1,  535,    2, 0x0a /* Public */,
      94,    1,  538,    2, 0x0a /* Public */,
      96,    2,  541,    2, 0x0a /* Public */,
     100,    0,  546,    2, 0x0a /* Public */,
     101,    0,  547,    2, 0x0a /* Public */,
     102,    1,  548,    2, 0x0a /* Public */,
     104,    1,  551,    2, 0x0a /* Public */,
     106,    1,  554,    2, 0x0a /* Public */,
     107,    1,  557,    2, 0x0a /* Public */,
     109,    0,  560,    2, 0x0a /* Public */,
     110,    1,  561,    2, 0x0a /* Public */,
     111,    1,  564,    2, 0x0a /* Public */,
     112,    1,  567,    2, 0x0a /* Public */,
     114,    1,  570,    2, 0x0a /* Public */,
     115,    1,  573,    2, 0x0a /* Public */,
     116,    1,  576,    2, 0x0a /* Public */,
     117,    0,  579,    2, 0x0a /* Public */,
     118,    0,  580,    2, 0x0a /* Public */,
     119,    0,  581,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    6,
    QMetaType::Void, 0x80000000 | 3,    8,
    QMetaType::Void, QMetaType::Double,   10,
    QMetaType::Void, QMetaType::Double,   12,
    QMetaType::Void, QMetaType::Double,   14,
    QMetaType::Void, QMetaType::Int,   16,
    QMetaType::Void, QMetaType::Int,   18,
    QMetaType::Void, QMetaType::Int,   20,
    QMetaType::Void, 0x80000000 | 3,    8,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3,   24,
    QMetaType::Void, 0x80000000 | 26,   27,
    QMetaType::Void, 0x80000000 | 29,   30,
    QMetaType::Void, QMetaType::Double,   32,
    QMetaType::Void, QMetaType::Double,   34,
    QMetaType::Void, QMetaType::Double,   36,
    QMetaType::Void, QMetaType::Double,   38,
    QMetaType::Void, QMetaType::Double,   40,
    QMetaType::Void, QMetaType::Double,   42,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3,   45,
    QMetaType::Void, 0x80000000 | 3,   47,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    6,
    QMetaType::Void, 0x80000000 | 3,    8,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,   53,
    QMetaType::Void, QMetaType::Double,   55,
    QMetaType::Void, QMetaType::Double,   57,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   16,
    QMetaType::Void, QMetaType::Int,   18,
    QMetaType::Void, QMetaType::Int,   20,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   77,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 81, 0x80000000 | 83,   82,   84,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 29, QMetaType::Int,   82,    2,
    QMetaType::Void, QMetaType::Double,   32,
    QMetaType::Void, QMetaType::Double,   34,
    QMetaType::Void, QMetaType::Double,   36,
    QMetaType::Void, QMetaType::Double,   91,
    QMetaType::Void, QMetaType::Double,   93,
    QMetaType::Void, QMetaType::Double,   95,
    0x80000000 | 97, QMetaType::Float, QMetaType::Float,   98,   99,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3,  103,
    QMetaType::Void, QMetaType::Double,  105,
    QMetaType::Void, QMetaType::Double,  105,
    QMetaType::Void, 0x80000000 | 3,  108,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,   98,
    QMetaType::Void, QMetaType::Double,   99,
    QMetaType::Void, QMetaType::Double,  113,
    QMetaType::Void, QMetaType::Double,   98,
    QMetaType::Void, QMetaType::Double,   99,
    QMetaType::Void, QMetaType::Double,  113,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MyGL::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MyGL *_t = static_cast<MyGL *>(_o);
        switch (_id) {
        case 0: _t->sig_SendHalfEdge((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 1: _t->sig_SendVertex((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 2: _t->sig_SendFace((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 3: _t->sig_ResetSpinBoxX((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 4: _t->sig_ResetSpinBoxY((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 5: _t->sig_ResetSpinBoxZ((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 6: _t->sig_ResetR((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->sig_ResetG((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->sig_ResetB((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->sig_sendNewlySelectedFace((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 10: _t->sig_restartFaces(); break;
        case 11: _t->sig_sendNewlySelectedHalfEdge((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 12: _t->sig_sendListOfFaces((*reinterpret_cast< QList<QListWidgetItem*>(*)>(_a[1]))); break;
        case 13: _t->sig_sendRootJoint((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1]))); break;
        case 14: _t->sig_sendJointX((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 15: _t->sig_sendJointY((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 16: _t->sig_sendJointZ((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 17: _t->sig_sendJointRoX((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 18: _t->sig_sendJointRoY((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 19: _t->sig_sendJointRoZ((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 20: _t->sig_makeNewTimeline(); break;
        case 21: _t->sig_sendFrame((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 22: _t->sig_sendMesh((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 23: _t->slot_ReceiveSelectedHalfEdge((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 24: _t->slot_ReceiveSelectedVertex((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 25: _t->slot_ReceiveSelectedFace((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 26: _t->slot_AddVertex(); break;
        case 27: _t->slot_updateVertX((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 28: _t->slot_updateVertY((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 29: _t->slot_updateVertZ((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 30: _t->slot_triangulateFace(); break;
        case 31: _t->slot_deleteVertex(); break;
        case 32: _t->slot_updateR((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 33: _t->slot_updateG((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 34: _t->slot_updateB((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 35: _t->slot_shiftToBarycenter(); break;
        case 36: _t->slot_quadrangulate(); break;
        case 37: _t->slot_showSym(); break;
        case 38: _t->slot_showNext(); break;
        case 39: _t->slot_showSelectedHalfEdgeFace(); break;
        case 40: _t->slot_smoothMesh(); break;
        case 41: _t->slot_discoTime(); break;
        case 42: _t->slot_showEdge(); break;
        case 43: _t->slot_showStartEdge(); break;
        case 44: _t->slot_showVertexFace(); break;
        case 45: _t->slot_importObjFile(); break;
        case 46: _t->slot_exportObjFile(); break;
        case 47: _t->slot_setDisplayCowVertices(); break;
        case 48: _t->slot_receiveNumFrames((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 49: _t->slot_createFrameTimeline(); break;
        case 50: _t->slot_importJSONFile(); break;
        case 51: _t->traverseJoints((*reinterpret_cast< Joint*(*)>(_a[1])),(*reinterpret_cast< glm::mat4(*)>(_a[2]))); break;
        case 52: _t->slot_calculateBindMatrices(); break;
        case 53: _t->slot_receiveSelectedJoint((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 54: _t->slot_updateJointX((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 55: _t->slot_updateJointY((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 56: _t->slot_updateJointZ((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 57: _t->slot_updateJointRoX((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 58: _t->slot_updateJointRoY((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 59: _t->slot_updateJointRoZ((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 60: { Ray _r = _t->Raycast((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< Ray*>(_a[0]) = _r; }  break;
        case 61: _t->slot_exportBMP(); break;
        case 62: _t->slot_createNewKeyFrame(); break;
        case 63: _t->slot_receiveSelectedFrame((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 64: _t->slot_updateRefraction((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 65: _t->slot_updateReflection((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 66: _t->slot_selectMesh((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 67: _t->slot_insertEdgeLoop(); break;
        case 68: _t->slot_meshTranslateX((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 69: _t->slot_meshTranslateY((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 70: _t->slot_meshTranslateZ((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 71: _t->slot_meshScaleX((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 72: _t->slot_meshScaleY((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 73: _t->slot_meshScaleZ((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 74: _t->slot_extrudeFace(); break;
        case 75: _t->slot_extrudeEdge(); break;
        case 76: _t->slot_bevelEdge(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MyGL::*_t)(QListWidgetItem * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyGL::sig_SendHalfEdge)) {
                *result = 0;
            }
        }
        {
            typedef void (MyGL::*_t)(QListWidgetItem * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyGL::sig_SendVertex)) {
                *result = 1;
            }
        }
        {
            typedef void (MyGL::*_t)(QListWidgetItem * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyGL::sig_SendFace)) {
                *result = 2;
            }
        }
        {
            typedef void (MyGL::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyGL::sig_ResetSpinBoxX)) {
                *result = 3;
            }
        }
        {
            typedef void (MyGL::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyGL::sig_ResetSpinBoxY)) {
                *result = 4;
            }
        }
        {
            typedef void (MyGL::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyGL::sig_ResetSpinBoxZ)) {
                *result = 5;
            }
        }
        {
            typedef void (MyGL::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyGL::sig_ResetR)) {
                *result = 6;
            }
        }
        {
            typedef void (MyGL::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyGL::sig_ResetG)) {
                *result = 7;
            }
        }
        {
            typedef void (MyGL::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyGL::sig_ResetB)) {
                *result = 8;
            }
        }
        {
            typedef void (MyGL::*_t)(QListWidgetItem * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyGL::sig_sendNewlySelectedFace)) {
                *result = 9;
            }
        }
        {
            typedef void (MyGL::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyGL::sig_restartFaces)) {
                *result = 10;
            }
        }
        {
            typedef void (MyGL::*_t)(QListWidgetItem * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyGL::sig_sendNewlySelectedHalfEdge)) {
                *result = 11;
            }
        }
        {
            typedef void (MyGL::*_t)(QList<QListWidgetItem*> );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyGL::sig_sendListOfFaces)) {
                *result = 12;
            }
        }
        {
            typedef void (MyGL::*_t)(QTreeWidgetItem * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyGL::sig_sendRootJoint)) {
                *result = 13;
            }
        }
        {
            typedef void (MyGL::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyGL::sig_sendJointX)) {
                *result = 14;
            }
        }
        {
            typedef void (MyGL::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyGL::sig_sendJointY)) {
                *result = 15;
            }
        }
        {
            typedef void (MyGL::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyGL::sig_sendJointZ)) {
                *result = 16;
            }
        }
        {
            typedef void (MyGL::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyGL::sig_sendJointRoX)) {
                *result = 17;
            }
        }
        {
            typedef void (MyGL::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyGL::sig_sendJointRoY)) {
                *result = 18;
            }
        }
        {
            typedef void (MyGL::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyGL::sig_sendJointRoZ)) {
                *result = 19;
            }
        }
        {
            typedef void (MyGL::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyGL::sig_makeNewTimeline)) {
                *result = 20;
            }
        }
        {
            typedef void (MyGL::*_t)(QListWidgetItem * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyGL::sig_sendFrame)) {
                *result = 21;
            }
        }
        {
            typedef void (MyGL::*_t)(QListWidgetItem * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyGL::sig_sendMesh)) {
                *result = 22;
            }
        }
    }
}

const QMetaObject MyGL::staticMetaObject = {
    { &GLWidget277::staticMetaObject, qt_meta_stringdata_MyGL.data,
      qt_meta_data_MyGL,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MyGL::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MyGL::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MyGL.stringdata))
        return static_cast<void*>(const_cast< MyGL*>(this));
    return GLWidget277::qt_metacast(_clname);
}

int MyGL::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = GLWidget277::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 77)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 77;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 77)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 77;
    }
    return _id;
}

// SIGNAL 0
void MyGL::sig_SendHalfEdge(QListWidgetItem * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MyGL::sig_SendVertex(QListWidgetItem * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MyGL::sig_SendFace(QListWidgetItem * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MyGL::sig_ResetSpinBoxX(double _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void MyGL::sig_ResetSpinBoxY(double _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void MyGL::sig_ResetSpinBoxZ(double _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void MyGL::sig_ResetR(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void MyGL::sig_ResetG(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void MyGL::sig_ResetB(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void MyGL::sig_sendNewlySelectedFace(QListWidgetItem * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void MyGL::sig_restartFaces()
{
    QMetaObject::activate(this, &staticMetaObject, 10, Q_NULLPTR);
}

// SIGNAL 11
void MyGL::sig_sendNewlySelectedHalfEdge(QListWidgetItem * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void MyGL::sig_sendListOfFaces(QList<QListWidgetItem*> _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}

// SIGNAL 13
void MyGL::sig_sendRootJoint(QTreeWidgetItem * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 13, _a);
}

// SIGNAL 14
void MyGL::sig_sendJointX(double _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 14, _a);
}

// SIGNAL 15
void MyGL::sig_sendJointY(double _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 15, _a);
}

// SIGNAL 16
void MyGL::sig_sendJointZ(double _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 16, _a);
}

// SIGNAL 17
void MyGL::sig_sendJointRoX(double _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 17, _a);
}

// SIGNAL 18
void MyGL::sig_sendJointRoY(double _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 18, _a);
}

// SIGNAL 19
void MyGL::sig_sendJointRoZ(double _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 19, _a);
}

// SIGNAL 20
void MyGL::sig_makeNewTimeline()
{
    QMetaObject::activate(this, &staticMetaObject, 20, Q_NULLPTR);
}

// SIGNAL 21
void MyGL::sig_sendFrame(QListWidgetItem * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 21, _a);
}

// SIGNAL 22
void MyGL::sig_sendMesh(QListWidgetItem * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 22, _a);
}
QT_END_MOC_NAMESPACE
