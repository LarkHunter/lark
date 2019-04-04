/****************************************************************************
** Meta object code from reading C++ file 'monthplan.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../monthplan.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'monthplan.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_monthPlan_t {
    QByteArrayData data[16];
    char stringdata0[241];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_monthPlan_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_monthPlan_t qt_meta_stringdata_monthPlan = {
    {
QT_MOC_LITERAL(0, 0, 9), // "monthPlan"
QT_MOC_LITERAL(1, 10, 15), // "onJanBtnclicked"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 15), // "onFebBtnclicked"
QT_MOC_LITERAL(4, 43, 15), // "onMarBtnclicked"
QT_MOC_LITERAL(5, 59, 15), // "onAprBtnclicked"
QT_MOC_LITERAL(6, 75, 15), // "onMayBtnclicked"
QT_MOC_LITERAL(7, 91, 15), // "onJunBtnclicked"
QT_MOC_LITERAL(8, 107, 15), // "onJulBtnclicked"
QT_MOC_LITERAL(9, 123, 15), // "onAugBtnclicked"
QT_MOC_LITERAL(10, 139, 15), // "onSepBtnclicked"
QT_MOC_LITERAL(11, 155, 15), // "onOctBtnclicked"
QT_MOC_LITERAL(12, 171, 15), // "onNovBtnclicked"
QT_MOC_LITERAL(13, 187, 15), // "onDecBtnclicked"
QT_MOC_LITERAL(14, 203, 15), // "onAddBtnclicked"
QT_MOC_LITERAL(15, 219, 21) // "onDoubleClickedDelete"

    },
    "monthPlan\0onJanBtnclicked\0\0onFebBtnclicked\0"
    "onMarBtnclicked\0onAprBtnclicked\0"
    "onMayBtnclicked\0onJunBtnclicked\0"
    "onJulBtnclicked\0onAugBtnclicked\0"
    "onSepBtnclicked\0onOctBtnclicked\0"
    "onNovBtnclicked\0onDecBtnclicked\0"
    "onAddBtnclicked\0onDoubleClickedDelete"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_monthPlan[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x0a /* Public */,
       3,    0,   85,    2, 0x0a /* Public */,
       4,    0,   86,    2, 0x0a /* Public */,
       5,    0,   87,    2, 0x0a /* Public */,
       6,    0,   88,    2, 0x0a /* Public */,
       7,    0,   89,    2, 0x0a /* Public */,
       8,    0,   90,    2, 0x0a /* Public */,
       9,    0,   91,    2, 0x0a /* Public */,
      10,    0,   92,    2, 0x0a /* Public */,
      11,    0,   93,    2, 0x0a /* Public */,
      12,    0,   94,    2, 0x0a /* Public */,
      13,    0,   95,    2, 0x0a /* Public */,
      14,    0,   96,    2, 0x0a /* Public */,
      15,    0,   97,    2, 0x0a /* Public */,

 // slots: parameters
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
    QMetaType::Void,

       0        // eod
};

void monthPlan::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        monthPlan *_t = static_cast<monthPlan *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onJanBtnclicked(); break;
        case 1: _t->onFebBtnclicked(); break;
        case 2: _t->onMarBtnclicked(); break;
        case 3: _t->onAprBtnclicked(); break;
        case 4: _t->onMayBtnclicked(); break;
        case 5: _t->onJunBtnclicked(); break;
        case 6: _t->onJulBtnclicked(); break;
        case 7: _t->onAugBtnclicked(); break;
        case 8: _t->onSepBtnclicked(); break;
        case 9: _t->onOctBtnclicked(); break;
        case 10: _t->onNovBtnclicked(); break;
        case 11: _t->onDecBtnclicked(); break;
        case 12: _t->onAddBtnclicked(); break;
        case 13: _t->onDoubleClickedDelete(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject monthPlan::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_monthPlan.data,
      qt_meta_data_monthPlan,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *monthPlan::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *monthPlan::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_monthPlan.stringdata0))
        return static_cast<void*>(const_cast< monthPlan*>(this));
    return QWidget::qt_metacast(_clname);
}

int monthPlan::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
