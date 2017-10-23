/****************************************************************************
** Meta object code from reading C++ file 'jointqtreewidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "src/jointqtreewidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'jointqtreewidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_jointQTreeWidget_t {
    QByteArrayData data[9];
    char stringdata[98];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_jointQTreeWidget_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_jointQTreeWidget_t qt_meta_stringdata_jointQTreeWidget = {
    {
QT_MOC_LITERAL(0, 0, 16), // "jointQTreeWidget"
QT_MOC_LITERAL(1, 17, 17), // "slot_addRootJoint"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 16), // "QTreeWidgetItem*"
QT_MOC_LITERAL(4, 53, 4), // "root"
QT_MOC_LITERAL(5, 58, 15), // "slot_bindJoints"
QT_MOC_LITERAL(6, 74, 15), // "changeAllColors"
QT_MOC_LITERAL(7, 90, 1), // "p"
QT_MOC_LITERAL(8, 92, 5) // "color"

    },
    "jointQTreeWidget\0slot_addRootJoint\0\0"
    "QTreeWidgetItem*\0root\0slot_bindJoints\0"
    "changeAllColors\0p\0color"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_jointQTreeWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x0a /* Public */,
       5,    0,   32,    2, 0x0a /* Public */,
       6,    2,   33,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3, QMetaType::QBrush,    7,    8,

       0        // eod
};

void jointQTreeWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        jointQTreeWidget *_t = static_cast<jointQTreeWidget *>(_o);
        switch (_id) {
        case 0: _t->slot_addRootJoint((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1]))); break;
        case 1: _t->slot_bindJoints(); break;
        case 2: _t->changeAllColors((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1])),(*reinterpret_cast< QBrush(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObject jointQTreeWidget::staticMetaObject = {
    { &QTreeWidget::staticMetaObject, qt_meta_stringdata_jointQTreeWidget.data,
      qt_meta_data_jointQTreeWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *jointQTreeWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *jointQTreeWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_jointQTreeWidget.stringdata))
        return static_cast<void*>(const_cast< jointQTreeWidget*>(this));
    return QTreeWidget::qt_metacast(_clname);
}

int jointQTreeWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTreeWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
