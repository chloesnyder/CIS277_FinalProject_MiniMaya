/****************************************************************************
** Meta object code from reading C++ file 'keyframeslistwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "src/keyframeslistwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'keyframeslistwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_KeyFramesListWidget_t {
    QByteArrayData data[12];
    char stringdata[187];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_KeyFramesListWidget_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_KeyFramesListWidget_t qt_meta_stringdata_KeyFramesListWidget = {
    {
QT_MOC_LITERAL(0, 0, 19), // "KeyFramesListWidget"
QT_MOC_LITERAL(1, 20, 17), // "slot_receiveFrame"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(4, 56, 5), // "frame"
QT_MOC_LITERAL(5, 62, 25), // "slot_receiveSelectedJoint"
QT_MOC_LITERAL(6, 88, 16), // "QTreeWidgetItem*"
QT_MOC_LITERAL(7, 105, 5), // "joint"
QT_MOC_LITERAL(8, 111, 17), // "slot_updateColors"
QT_MOC_LITERAL(9, 129, 22), // "slot_createNewTimeline"
QT_MOC_LITERAL(10, 152, 22), // "slot_loopThroughFrames"
QT_MOC_LITERAL(11, 175, 11) // "updateFrame"

    },
    "KeyFramesListWidget\0slot_receiveFrame\0"
    "\0QListWidgetItem*\0frame\0"
    "slot_receiveSelectedJoint\0QTreeWidgetItem*\0"
    "joint\0slot_updateColors\0slot_createNewTimeline\0"
    "slot_loopThroughFrames\0updateFrame"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_KeyFramesListWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x0a /* Public */,
       5,    1,   47,    2, 0x0a /* Public */,
       8,    1,   50,    2, 0x0a /* Public */,
       9,    0,   53,    2, 0x0a /* Public */,
      10,    0,   54,    2, 0x0a /* Public */,
      11,    0,   55,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void KeyFramesListWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        KeyFramesListWidget *_t = static_cast<KeyFramesListWidget *>(_o);
        switch (_id) {
        case 0: _t->slot_receiveFrame((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 1: _t->slot_receiveSelectedJoint((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1]))); break;
        case 2: _t->slot_updateColors((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 3: _t->slot_createNewTimeline(); break;
        case 4: _t->slot_loopThroughFrames(); break;
        case 5: _t->updateFrame(); break;
        default: ;
        }
    }
}

const QMetaObject KeyFramesListWidget::staticMetaObject = {
    { &QListWidget::staticMetaObject, qt_meta_stringdata_KeyFramesListWidget.data,
      qt_meta_data_KeyFramesListWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *KeyFramesListWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *KeyFramesListWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_KeyFramesListWidget.stringdata))
        return static_cast<void*>(const_cast< KeyFramesListWidget*>(this));
    return QListWidget::qt_metacast(_clname);
}

int KeyFramesListWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QListWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
