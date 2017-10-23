/****************************************************************************
** Meta object code from reading C++ file 'meshqlistwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "src/meshqlistwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'meshqlistwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MeshQListWidget_t {
    QByteArrayData data[19];
    char stringdata[252];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MeshQListWidget_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MeshQListWidget_t qt_meta_stringdata_MeshQListWidget = {
    {
QT_MOC_LITERAL(0, 0, 15), // "MeshQListWidget"
QT_MOC_LITERAL(1, 16, 16), // "slot_addHalfEdge"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(4, 51, 9), // "half_edge"
QT_MOC_LITERAL(5, 61, 14), // "slot_addVertex"
QT_MOC_LITERAL(6, 76, 6), // "vertex"
QT_MOC_LITERAL(7, 83, 12), // "slot_addFace"
QT_MOC_LITERAL(8, 96, 4), // "face"
QT_MOC_LITERAL(9, 101, 15), // "slot_selectFace"
QT_MOC_LITERAL(10, 117, 19), // "slot_selectHalfEdge"
QT_MOC_LITERAL(11, 137, 8), // "halfedge"
QT_MOC_LITERAL(12, 146, 17), // "slot_restartFaces"
QT_MOC_LITERAL(13, 164, 19), // "slot_addListOfFaces"
QT_MOC_LITERAL(14, 184, 23), // "QList<QListWidgetItem*>"
QT_MOC_LITERAL(15, 208, 9), // "facesList"
QT_MOC_LITERAL(16, 218, 12), // "slot_addMesh"
QT_MOC_LITERAL(17, 231, 4), // "mesh"
QT_MOC_LITERAL(18, 236, 15) // "slot_selectMesh"

    },
    "MeshQListWidget\0slot_addHalfEdge\0\0"
    "QListWidgetItem*\0half_edge\0slot_addVertex\0"
    "vertex\0slot_addFace\0face\0slot_selectFace\0"
    "slot_selectHalfEdge\0halfedge\0"
    "slot_restartFaces\0slot_addListOfFaces\0"
    "QList<QListWidgetItem*>\0facesList\0"
    "slot_addMesh\0mesh\0slot_selectMesh"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MeshQListWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x0a /* Public */,
       5,    1,   62,    2, 0x0a /* Public */,
       7,    1,   65,    2, 0x0a /* Public */,
       9,    1,   68,    2, 0x0a /* Public */,
      10,    1,   71,    2, 0x0a /* Public */,
      12,    0,   74,    2, 0x0a /* Public */,
      13,    1,   75,    2, 0x0a /* Public */,
      16,    1,   78,    2, 0x0a /* Public */,
      18,    1,   81,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    6,
    QMetaType::Void, 0x80000000 | 3,    8,
    QMetaType::Void, 0x80000000 | 3,    8,
    QMetaType::Void, 0x80000000 | 3,   11,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 14,   15,
    QMetaType::Void, 0x80000000 | 3,   17,
    QMetaType::Void, 0x80000000 | 3,   17,

       0        // eod
};

void MeshQListWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MeshQListWidget *_t = static_cast<MeshQListWidget *>(_o);
        switch (_id) {
        case 0: _t->slot_addHalfEdge((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 1: _t->slot_addVertex((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 2: _t->slot_addFace((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 3: _t->slot_selectFace((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 4: _t->slot_selectHalfEdge((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 5: _t->slot_restartFaces(); break;
        case 6: _t->slot_addListOfFaces((*reinterpret_cast< QList<QListWidgetItem*>(*)>(_a[1]))); break;
        case 7: _t->slot_addMesh((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 8: _t->slot_selectMesh((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject MeshQListWidget::staticMetaObject = {
    { &QListWidget::staticMetaObject, qt_meta_stringdata_MeshQListWidget.data,
      qt_meta_data_MeshQListWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MeshQListWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MeshQListWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MeshQListWidget.stringdata))
        return static_cast<void*>(const_cast< MeshQListWidget*>(this));
    return QListWidget::qt_metacast(_clname);
}

int MeshQListWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QListWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
