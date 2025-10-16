/****************************************************************************
** Meta object code from reading C++ file 'qlabstatusencodingtablewgt.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.12)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../qlabstatusencodingtablewgt.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qlabstatusencodingtablewgt.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.12. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QTruthTableHeaderWgt_t {
    QByteArrayData data[4];
    char stringdata0[41];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QTruthTableHeaderWgt_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QTruthTableHeaderWgt_t qt_meta_stringdata_QTruthTableHeaderWgt = {
    {
QT_MOC_LITERAL(0, 0, 20), // "QTruthTableHeaderWgt"
QT_MOC_LITERAL(1, 21, 13), // "setHeaderText"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 4) // "text"

    },
    "QTruthTableHeaderWgt\0setHeaderText\0\0"
    "text"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QTruthTableHeaderWgt[] = {

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

void QTruthTableHeaderWgt::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QTruthTableHeaderWgt *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setHeaderText((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject QTruthTableHeaderWgt::staticMetaObject = { {
    &QTextBrowser::staticMetaObject,
    qt_meta_stringdata_QTruthTableHeaderWgt.data,
    qt_meta_data_QTruthTableHeaderWgt,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QTruthTableHeaderWgt::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QTruthTableHeaderWgt::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QTruthTableHeaderWgt.stringdata0))
        return static_cast<void*>(this);
    return QTextBrowser::qt_metacast(_clname);
}

int QTruthTableHeaderWgt::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
struct qt_meta_stringdata_QTruthTableWgt_t {
    QByteArrayData data[22];
    char stringdata0[241];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QTruthTableWgt_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QTruthTableWgt_t qt_meta_stringdata_QTruthTableWgt = {
    {
QT_MOC_LITERAL(0, 0, 14), // "QTruthTableWgt"
QT_MOC_LITERAL(1, 15, 13), // "symbolChanged"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 11), // "funcChanged"
QT_MOC_LITERAL(4, 42, 12), // "funcsIsValid"
QT_MOC_LITERAL(5, 55, 10), // "dataEdited"
QT_MOC_LITERAL(6, 66, 17), // "sendCurrentSymbol"
QT_MOC_LITERAL(7, 84, 8), // "sendFunc"
QT_MOC_LITERAL(8, 93, 3), // "num"
QT_MOC_LITERAL(9, 97, 14), // "itemKeyPressed"
QT_MOC_LITERAL(10, 112, 10), // "QKeyEvent*"
QT_MOC_LITERAL(11, 123, 5), // "event"
QT_MOC_LITERAL(12, 129, 16), // "clickedTableItem"
QT_MOC_LITERAL(13, 146, 17), // "QTableWidgetItem*"
QT_MOC_LITERAL(14, 164, 4), // "item"
QT_MOC_LITERAL(15, 169, 18), // "adoptOptionToggled"
QT_MOC_LITERAL(16, 188, 5), // "state"
QT_MOC_LITERAL(17, 194, 6), // "setVar"
QT_MOC_LITERAL(18, 201, 3), // "var"
QT_MOC_LITERAL(19, 205, 10), // "setSymbols"
QT_MOC_LITERAL(20, 216, 16), // "QVector<QString>"
QT_MOC_LITERAL(21, 233, 7) // "symbols"

    },
    "QTruthTableWgt\0symbolChanged\0\0funcChanged\0"
    "funcsIsValid\0dataEdited\0sendCurrentSymbol\0"
    "sendFunc\0num\0itemKeyPressed\0QKeyEvent*\0"
    "event\0clickedTableItem\0QTableWidgetItem*\0"
    "item\0adoptOptionToggled\0state\0setVar\0"
    "var\0setSymbols\0QVector<QString>\0symbols"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QTruthTableWgt[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   69,    2, 0x06 /* Public */,
       3,    2,   72,    2, 0x06 /* Public */,
       4,    0,   77,    2, 0x06 /* Public */,
       5,    0,   78,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   79,    2, 0x09 /* Protected */,
       7,    1,   80,    2, 0x09 /* Protected */,
       9,    1,   83,    2, 0x09 /* Protected */,
      12,    1,   86,    2, 0x09 /* Protected */,
      15,    1,   89,    2, 0x0a /* Public */,
      17,    1,   92,    2, 0x0a /* Public */,
      19,    1,   95,    2, 0x0a /* Public */,

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
    QMetaType::Void, QMetaType::Bool,   16,
    QMetaType::Void, QMetaType::QString,   18,
    QMetaType::Void, 0x80000000 | 20,   21,

       0        // eod
};

void QTruthTableWgt::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QTruthTableWgt *>(_o);
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
        case 8: _t->adoptOptionToggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->setVar((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 10: _t->setSymbols((*reinterpret_cast< QVector<QString>(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 10:
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
            using _t = void (QTruthTableWgt::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QTruthTableWgt::symbolChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (QTruthTableWgt::*)(int , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QTruthTableWgt::funcChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (QTruthTableWgt::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QTruthTableWgt::funcsIsValid)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (QTruthTableWgt::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QTruthTableWgt::dataEdited)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject QTruthTableWgt::staticMetaObject = { {
    &QTableWidget::staticMetaObject,
    qt_meta_stringdata_QTruthTableWgt.data,
    qt_meta_data_QTruthTableWgt,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QTruthTableWgt::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QTruthTableWgt::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QTruthTableWgt.stringdata0))
        return static_cast<void*>(this);
    return QTableWidget::qt_metacast(_clname);
}

int QTruthTableWgt::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTableWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void QTruthTableWgt::symbolChanged(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QTruthTableWgt::funcChanged(int _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void QTruthTableWgt::funcsIsValid()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void QTruthTableWgt::dataEdited()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
struct qt_meta_stringdata_QLabStatusEncodingTableWgt_t {
    QByteArrayData data[9];
    char stringdata0[117];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QLabStatusEncodingTableWgt_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QLabStatusEncodingTableWgt_t qt_meta_stringdata_QLabStatusEncodingTableWgt = {
    {
QT_MOC_LITERAL(0, 0, 26), // "QLabStatusEncodingTableWgt"
QT_MOC_LITERAL(1, 27, 6), // "setVar"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 11), // "funcChanged"
QT_MOC_LITERAL(4, 47, 12), // "funcsIsValid"
QT_MOC_LITERAL(5, 60, 10), // "dataEdited"
QT_MOC_LITERAL(6, 71, 26), // "on_pushButtonCheck_clicked"
QT_MOC_LITERAL(7, 98, 10), // "showErrMsg"
QT_MOC_LITERAL(8, 109, 7) // "errCode"

    },
    "QLabStatusEncodingTableWgt\0setVar\0\0"
    "funcChanged\0funcsIsValid\0dataEdited\0"
    "on_pushButtonCheck_clicked\0showErrMsg\0"
    "errCode"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QLabStatusEncodingTableWgt[] = {

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

void QLabStatusEncodingTableWgt::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QLabStatusEncodingTableWgt *>(_o);
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
            using _t = void (QLabStatusEncodingTableWgt::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QLabStatusEncodingTableWgt::setVar)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (QLabStatusEncodingTableWgt::*)(int , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QLabStatusEncodingTableWgt::funcChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (QLabStatusEncodingTableWgt::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QLabStatusEncodingTableWgt::funcsIsValid)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (QLabStatusEncodingTableWgt::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QLabStatusEncodingTableWgt::dataEdited)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject QLabStatusEncodingTableWgt::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_QLabStatusEncodingTableWgt.data,
    qt_meta_data_QLabStatusEncodingTableWgt,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QLabStatusEncodingTableWgt::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QLabStatusEncodingTableWgt::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QLabStatusEncodingTableWgt.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int QLabStatusEncodingTableWgt::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void QLabStatusEncodingTableWgt::setVar(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QLabStatusEncodingTableWgt::funcChanged(int _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void QLabStatusEncodingTableWgt::funcsIsValid()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void QLabStatusEncodingTableWgt::dataEdited()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
