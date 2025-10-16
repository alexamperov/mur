/****************************************************************************
** Meta object code from reading C++ file 'qlabstatustablewgt.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.12)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../qlabstatustablewgt.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qlabstatustablewgt.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.12. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QStatusTableHeaderWgt_t {
    QByteArrayData data[4];
    char stringdata0[42];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QStatusTableHeaderWgt_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QStatusTableHeaderWgt_t qt_meta_stringdata_QStatusTableHeaderWgt = {
    {
QT_MOC_LITERAL(0, 0, 21), // "QStatusTableHeaderWgt"
QT_MOC_LITERAL(1, 22, 13), // "setHeaderText"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 4) // "text"

    },
    "QStatusTableHeaderWgt\0setHeaderText\0"
    "\0text"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QStatusTableHeaderWgt[] = {

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

void QStatusTableHeaderWgt::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QStatusTableHeaderWgt *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setHeaderText((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject QStatusTableHeaderWgt::staticMetaObject = { {
    &QTextBrowser::staticMetaObject,
    qt_meta_stringdata_QStatusTableHeaderWgt.data,
    qt_meta_data_QStatusTableHeaderWgt,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QStatusTableHeaderWgt::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QStatusTableHeaderWgt::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QStatusTableHeaderWgt.stringdata0))
        return static_cast<void*>(this);
    return QTextBrowser::qt_metacast(_clname);
}

int QStatusTableHeaderWgt::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
struct qt_meta_stringdata_QStatusTableWgt_t {
    QByteArrayData data[20];
    char stringdata0[217];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QStatusTableWgt_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QStatusTableWgt_t qt_meta_stringdata_QStatusTableWgt = {
    {
QT_MOC_LITERAL(0, 0, 15), // "QStatusTableWgt"
QT_MOC_LITERAL(1, 16, 13), // "symbolChanged"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 11), // "funcChanged"
QT_MOC_LITERAL(4, 43, 12), // "funcsIsValid"
QT_MOC_LITERAL(5, 56, 10), // "dataEdited"
QT_MOC_LITERAL(6, 67, 17), // "sendCurrentSymbol"
QT_MOC_LITERAL(7, 85, 8), // "sendFunc"
QT_MOC_LITERAL(8, 94, 3), // "num"
QT_MOC_LITERAL(9, 98, 14), // "itemKeyPressed"
QT_MOC_LITERAL(10, 113, 10), // "QKeyEvent*"
QT_MOC_LITERAL(11, 124, 5), // "event"
QT_MOC_LITERAL(12, 130, 16), // "clickedTableItem"
QT_MOC_LITERAL(13, 147, 17), // "QTableWidgetItem*"
QT_MOC_LITERAL(14, 165, 4), // "item"
QT_MOC_LITERAL(15, 170, 6), // "setVar"
QT_MOC_LITERAL(16, 177, 3), // "obj"
QT_MOC_LITERAL(17, 181, 10), // "setSymbols"
QT_MOC_LITERAL(18, 192, 16), // "QVector<QString>"
QT_MOC_LITERAL(19, 209, 7) // "symbols"

    },
    "QStatusTableWgt\0symbolChanged\0\0"
    "funcChanged\0funcsIsValid\0dataEdited\0"
    "sendCurrentSymbol\0sendFunc\0num\0"
    "itemKeyPressed\0QKeyEvent*\0event\0"
    "clickedTableItem\0QTableWidgetItem*\0"
    "item\0setVar\0obj\0setSymbols\0QVector<QString>\0"
    "symbols"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QStatusTableWgt[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x06 /* Public */,
       3,    2,   67,    2, 0x06 /* Public */,
       4,    0,   72,    2, 0x06 /* Public */,
       5,    0,   73,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   74,    2, 0x09 /* Protected */,
       7,    1,   75,    2, 0x09 /* Protected */,
       9,    1,   78,    2, 0x09 /* Protected */,
      12,    1,   81,    2, 0x09 /* Protected */,
      15,    1,   84,    2, 0x0a /* Public */,
      17,    1,   87,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    2,    2,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void, 0x80000000 | 13,   14,
    QMetaType::Void, QMetaType::QObjectStar,   16,
    QMetaType::Void, 0x80000000 | 18,   19,

       0        // eod
};

void QStatusTableWgt::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QStatusTableWgt *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->symbolChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->funcChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 2: _t->funcsIsValid(); break;
        case 3: _t->dataEdited(); break;
        case 4: _t->sendCurrentSymbol(); break;
        case 5: _t->sendFunc((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->itemKeyPressed((*reinterpret_cast< QKeyEvent*(*)>(_a[1]))); break;
        case 7: _t->clickedTableItem((*reinterpret_cast< QTableWidgetItem*(*)>(_a[1]))); break;
        case 8: _t->setVar((*reinterpret_cast< QObject*(*)>(_a[1]))); break;
        case 9: _t->setSymbols((*reinterpret_cast< QVector<QString>(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 9:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<QString> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (QStatusTableWgt::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QStatusTableWgt::symbolChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (QStatusTableWgt::*)(int , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QStatusTableWgt::funcChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (QStatusTableWgt::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QStatusTableWgt::funcsIsValid)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (QStatusTableWgt::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QStatusTableWgt::dataEdited)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject QStatusTableWgt::staticMetaObject = { {
    &QTableWidget::staticMetaObject,
    qt_meta_stringdata_QStatusTableWgt.data,
    qt_meta_data_QStatusTableWgt,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QStatusTableWgt::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QStatusTableWgt::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QStatusTableWgt.stringdata0))
        return static_cast<void*>(this);
    return QTableWidget::qt_metacast(_clname);
}

int QStatusTableWgt::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTableWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void QStatusTableWgt::symbolChanged(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QStatusTableWgt::funcChanged(int _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void QStatusTableWgt::funcsIsValid()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void QStatusTableWgt::dataEdited()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
struct qt_meta_stringdata_QLabStatusTableWgt_t {
    QByteArrayData data[13];
    char stringdata0[179];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QLabStatusTableWgt_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QLabStatusTableWgt_t qt_meta_stringdata_QLabStatusTableWgt = {
    {
QT_MOC_LITERAL(0, 0, 18), // "QLabStatusTableWgt"
QT_MOC_LITERAL(1, 19, 6), // "setVar"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 11), // "funcChanged"
QT_MOC_LITERAL(4, 39, 12), // "funcsIsValid"
QT_MOC_LITERAL(5, 52, 10), // "dataEdited"
QT_MOC_LITERAL(6, 63, 26), // "on_pushButtonCheck_clicked"
QT_MOC_LITERAL(7, 90, 28), // "on_pushButtonCheck_3_clicked"
QT_MOC_LITERAL(8, 119, 10), // "showErrMsg"
QT_MOC_LITERAL(9, 130, 7), // "errCode"
QT_MOC_LITERAL(10, 138, 26), // "showErrMsgStatusAndTrigger"
QT_MOC_LITERAL(11, 165, 9), // "setLabels"
QT_MOC_LITERAL(12, 175, 3) // "obj"

    },
    "QLabStatusTableWgt\0setVar\0\0funcChanged\0"
    "funcsIsValid\0dataEdited\0"
    "on_pushButtonCheck_clicked\0"
    "on_pushButtonCheck_3_clicked\0showErrMsg\0"
    "errCode\0showErrMsgStatusAndTrigger\0"
    "setLabels\0obj"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QLabStatusTableWgt[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x06 /* Public */,
       3,    2,   67,    2, 0x06 /* Public */,
       4,    0,   72,    2, 0x06 /* Public */,
       5,    0,   73,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   74,    2, 0x08 /* Private */,
       7,    0,   75,    2, 0x08 /* Private */,
       8,    1,   76,    2, 0x09 /* Protected */,
      10,    1,   79,    2, 0x09 /* Protected */,
       8,    0,   82,    2, 0x0a /* Public */,
      11,    1,   83,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QObjectStar,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    2,    2,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QObjectStar,   12,

       0        // eod
};

void QLabStatusTableWgt::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QLabStatusTableWgt *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setVar((*reinterpret_cast< QObject*(*)>(_a[1]))); break;
        case 1: _t->funcChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 2: _t->funcsIsValid(); break;
        case 3: _t->dataEdited(); break;
        case 4: _t->on_pushButtonCheck_clicked(); break;
        case 5: _t->on_pushButtonCheck_3_clicked(); break;
        case 6: _t->showErrMsg((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->showErrMsgStatusAndTrigger((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->showErrMsg(); break;
        case 9: _t->setLabels((*reinterpret_cast< QObject*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (QLabStatusTableWgt::*)(QObject * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QLabStatusTableWgt::setVar)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (QLabStatusTableWgt::*)(int , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QLabStatusTableWgt::funcChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (QLabStatusTableWgt::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QLabStatusTableWgt::funcsIsValid)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (QLabStatusTableWgt::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QLabStatusTableWgt::dataEdited)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject QLabStatusTableWgt::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_QLabStatusTableWgt.data,
    qt_meta_data_QLabStatusTableWgt,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QLabStatusTableWgt::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QLabStatusTableWgt::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QLabStatusTableWgt.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int QLabStatusTableWgt::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void QLabStatusTableWgt::setVar(QObject * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QLabStatusTableWgt::funcChanged(int _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void QLabStatusTableWgt::funcsIsValid()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void QLabStatusTableWgt::dataEdited()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
