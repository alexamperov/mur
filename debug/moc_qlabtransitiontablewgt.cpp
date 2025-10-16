/****************************************************************************
** Meta object code from reading C++ file 'qlabtransitiontablewgt.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.12)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../qlabtransitiontablewgt.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qlabtransitiontablewgt.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.12. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QTransitionTableHeaderWgt_t {
    QByteArrayData data[4];
    char stringdata0[46];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QTransitionTableHeaderWgt_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QTransitionTableHeaderWgt_t qt_meta_stringdata_QTransitionTableHeaderWgt = {
    {
QT_MOC_LITERAL(0, 0, 25), // "QTransitionTableHeaderWgt"
QT_MOC_LITERAL(1, 26, 13), // "setHeaderText"
QT_MOC_LITERAL(2, 40, 0), // ""
QT_MOC_LITERAL(3, 41, 4) // "text"

    },
    "QTransitionTableHeaderWgt\0setHeaderText\0"
    "\0text"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QTransitionTableHeaderWgt[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   19,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,

       0        // eod
};

void QTransitionTableHeaderWgt::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QTransitionTableHeaderWgt *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setHeaderText((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject QTransitionTableHeaderWgt::staticMetaObject = { {
    &QTextBrowser::staticMetaObject,
    qt_meta_stringdata_QTransitionTableHeaderWgt.data,
    qt_meta_data_QTransitionTableHeaderWgt,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QTransitionTableHeaderWgt::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QTransitionTableHeaderWgt::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QTransitionTableHeaderWgt.stringdata0))
        return static_cast<void*>(this);
    return QTextBrowser::qt_metacast(_clname);
}

int QTransitionTableHeaderWgt::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTextBrowser::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}
struct qt_meta_stringdata_QTransitionTableWgt_t {
    QByteArrayData data[5];
    char stringdata0[57];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QTransitionTableWgt_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QTransitionTableWgt_t qt_meta_stringdata_QTransitionTableWgt = {
    {
QT_MOC_LITERAL(0, 0, 19), // "QTransitionTableWgt"
QT_MOC_LITERAL(1, 20, 11), // "funcChanged"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 12), // "funcsIsValid"
QT_MOC_LITERAL(4, 46, 10) // "dataEdited"

    },
    "QTransitionTableWgt\0funcChanged\0\0"
    "funcsIsValid\0dataEdited"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QTransitionTableWgt[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   29,    2, 0x06 /* Public */,
       3,    0,   34,    2, 0x06 /* Public */,
       4,    0,   35,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    2,    2,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void QTransitionTableWgt::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QTransitionTableWgt *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->funcChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: _t->funcsIsValid(); break;
        case 2: _t->dataEdited(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (QTransitionTableWgt::*)(int , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QTransitionTableWgt::funcChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (QTransitionTableWgt::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QTransitionTableWgt::funcsIsValid)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (QTransitionTableWgt::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QTransitionTableWgt::dataEdited)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject QTransitionTableWgt::staticMetaObject = { {
    &QTableWidget::staticMetaObject,
    qt_meta_stringdata_QTransitionTableWgt.data,
    qt_meta_data_QTransitionTableWgt,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QTransitionTableWgt::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QTransitionTableWgt::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QTransitionTableWgt.stringdata0))
        return static_cast<void*>(this);
    return QTableWidget::qt_metacast(_clname);
}

int QTransitionTableWgt::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTableWidget::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void QTransitionTableWgt::funcChanged(int _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QTransitionTableWgt::funcsIsValid()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void QTransitionTableWgt::dataEdited()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
struct qt_meta_stringdata_QLabTransitionTableWgt_t {
    QByteArrayData data[9];
    char stringdata0[113];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QLabTransitionTableWgt_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QLabTransitionTableWgt_t qt_meta_stringdata_QLabTransitionTableWgt = {
    {
QT_MOC_LITERAL(0, 0, 22), // "QLabTransitionTableWgt"
QT_MOC_LITERAL(1, 23, 6), // "setVar"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 11), // "funcChanged"
QT_MOC_LITERAL(4, 43, 12), // "funcsIsValid"
QT_MOC_LITERAL(5, 56, 10), // "dataEdited"
QT_MOC_LITERAL(6, 67, 26), // "on_pushButtonCheck_clicked"
QT_MOC_LITERAL(7, 94, 10), // "showErrMsg"
QT_MOC_LITERAL(8, 105, 7) // "errCode"

    },
    "QLabTransitionTableWgt\0setVar\0\0"
    "funcChanged\0funcsIsValid\0dataEdited\0"
    "on_pushButtonCheck_clicked\0showErrMsg\0"
    "errCode"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QLabTransitionTableWgt[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,
       3,    2,   52,    2, 0x06 /* Public */,
       4,    0,   57,    2, 0x06 /* Public */,
       5,    0,   58,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   59,    2, 0x08 /* Private */,
       7,    1,   60,    2, 0x09 /* Protected */,
       7,    0,   63,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    2,    2,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void,

       0        // eod
};

void QLabTransitionTableWgt::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QLabTransitionTableWgt *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setVar((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->funcChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 2: _t->funcsIsValid(); break;
        case 3: _t->dataEdited(); break;
        case 4: _t->on_pushButtonCheck_clicked(); break;
        case 5: _t->showErrMsg((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->showErrMsg(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (QLabTransitionTableWgt::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QLabTransitionTableWgt::setVar)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (QLabTransitionTableWgt::*)(int , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QLabTransitionTableWgt::funcChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (QLabTransitionTableWgt::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QLabTransitionTableWgt::funcsIsValid)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (QLabTransitionTableWgt::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QLabTransitionTableWgt::dataEdited)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject QLabTransitionTableWgt::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_QLabTransitionTableWgt.data,
    qt_meta_data_QLabTransitionTableWgt,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QLabTransitionTableWgt::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QLabTransitionTableWgt::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QLabTransitionTableWgt.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int QLabTransitionTableWgt::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void QLabTransitionTableWgt::setVar(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QLabTransitionTableWgt::funcChanged(int _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void QLabTransitionTableWgt::funcsIsValid()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void QLabTransitionTableWgt::dataEdited()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
