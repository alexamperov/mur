/****************************************************************************
** Meta object code from reading C++ file 'qtermedit.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.12)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../qtermedit.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qtermedit.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.12. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QTermItmWgt_t {
    QByteArrayData data[17];
    char stringdata0[120];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QTermItmWgt_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QTermItmWgt_t qt_meta_stringdata_QTermItmWgt = {
    {
QT_MOC_LITERAL(0, 0, 11), // "QTermItmWgt"
QT_MOC_LITERAL(1, 12, 9), // "toggledOn"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 10), // "setTermItm"
QT_MOC_LITERAL(4, 34, 3), // "var"
QT_MOC_LITERAL(5, 38, 3), // "num"
QT_MOC_LITERAL(6, 42, 4), // "sign"
QT_MOC_LITERAL(7, 47, 10), // "setTermFrm"
QT_MOC_LITERAL(8, 58, 4), // "form"
QT_MOC_LITERAL(9, 63, 5), // "setOn"
QT_MOC_LITERAL(10, 69, 6), // "setOff"
QT_MOC_LITERAL(11, 76, 6), // "setBlk"
QT_MOC_LITERAL(12, 83, 8), // "clearBlk"
QT_MOC_LITERAL(13, 92, 8), // "blkState"
QT_MOC_LITERAL(14, 101, 5), // "state"
QT_MOC_LITERAL(15, 107, 7), // "setHtml"
QT_MOC_LITERAL(16, 115, 4) // "text"

    },
    "QTermItmWgt\0toggledOn\0\0setTermItm\0var\0"
    "num\0sign\0setTermFrm\0form\0setOn\0setOff\0"
    "setBlk\0clearBlk\0blkState\0state\0setHtml\0"
    "text"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QTermItmWgt[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    3,   60,    2, 0x0a /* Public */,
       7,    1,   67,    2, 0x0a /* Public */,
       9,    0,   70,    2, 0x0a /* Public */,
      10,    0,   71,    2, 0x0a /* Public */,
      11,    0,   72,    2, 0x0a /* Public */,
      12,    0,   73,    2, 0x0a /* Public */,
      13,    1,   74,    2, 0x0a /* Public */,
      15,    1,   77,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::Bool,    4,    5,    6,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   14,
    QMetaType::Void, QMetaType::QString,   16,

       0        // eod
};

void QTermItmWgt::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QTermItmWgt *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->toggledOn(); break;
        case 1: _t->setTermItm((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 2: _t->setTermFrm((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->setOn(); break;
        case 4: _t->setOff(); break;
        case 5: _t->setBlk(); break;
        case 6: _t->clearBlk(); break;
        case 7: _t->blkState((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->setHtml((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (QTermItmWgt::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QTermItmWgt::toggledOn)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject QTermItmWgt::staticMetaObject = { {
    &QTextBrowser::staticMetaObject,
    qt_meta_stringdata_QTermItmWgt.data,
    qt_meta_data_QTermItmWgt,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QTermItmWgt::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QTermItmWgt::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QTermItmWgt.stringdata0))
        return static_cast<void*>(this);
    return QTextBrowser::qt_metacast(_clname);
}

int QTermItmWgt::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTextBrowser::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void QTermItmWgt::toggledOn()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
struct qt_meta_stringdata_QTermEdit_t {
    QByteArrayData data[8];
    char stringdata0[48];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QTermEdit_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QTermEdit_t qt_meta_stringdata_QTermEdit = {
    {
QT_MOC_LITERAL(0, 0, 9), // "QTermEdit"
QT_MOC_LITERAL(1, 10, 7), // "unblock"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 5), // "block"
QT_MOC_LITERAL(4, 25, 4), // "form"
QT_MOC_LITERAL(5, 30, 5), // "clear"
QT_MOC_LITERAL(6, 36, 5), // "setKF"
QT_MOC_LITERAL(7, 42, 5) // "setDF"

    },
    "QTermEdit\0unblock\0\0block\0form\0clear\0"
    "setKF\0setDF"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QTermEdit[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x0a /* Public */,
       3,    0,   45,    2, 0x0a /* Public */,
       3,    1,   46,    2, 0x0a /* Public */,
       5,    0,   49,    2, 0x0a /* Public */,
       6,    0,   50,    2, 0x09 /* Protected */,
       7,    0,   51,    2, 0x09 /* Protected */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void QTermEdit::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QTermEdit *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->unblock(); break;
        case 1: _t->block(); break;
        case 2: _t->block((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->clear(); break;
        case 4: _t->setKF(); break;
        case 5: _t->setDF(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject QTermEdit::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_QTermEdit.data,
    qt_meta_data_QTermEdit,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QTermEdit::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QTermEdit::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QTermEdit.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int QTermEdit::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
