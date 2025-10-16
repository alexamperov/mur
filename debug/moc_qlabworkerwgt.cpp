/****************************************************************************
** Meta object code from reading C++ file 'qlabworkerwgt.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.12)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../qlabworkerwgt.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qlabworkerwgt.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.12. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QTabBarWgt_t {
    QByteArrayData data[3];
    char stringdata0[23];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QTabBarWgt_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QTabBarWgt_t qt_meta_stringdata_QTabBarWgt = {
    {
QT_MOC_LITERAL(0, 0, 10), // "QTabBarWgt"
QT_MOC_LITERAL(1, 11, 10), // "tabsChange"
QT_MOC_LITERAL(2, 22, 0) // ""

    },
    "QTabBarWgt\0tabsChange\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QTabBarWgt[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,

       0        // eod
};

void QTabBarWgt::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QTabBarWgt *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->tabsChange((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (QTabBarWgt::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QTabBarWgt::tabsChange)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject QTabBarWgt::staticMetaObject = { {
    &QTabBar::staticMetaObject,
    qt_meta_stringdata_QTabBarWgt.data,
    qt_meta_data_QTabBarWgt,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QTabBarWgt::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QTabBarWgt::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QTabBarWgt.stringdata0))
        return static_cast<void*>(this);
    return QTabBar::qt_metacast(_clname);
}

int QTabBarWgt::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTabBar::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void QTabBarWgt::tabsChange(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_QLabTabWgt_t {
    QByteArrayData data[3];
    char stringdata0[23];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QLabTabWgt_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QLabTabWgt_t qt_meta_stringdata_QLabTabWgt = {
    {
QT_MOC_LITERAL(0, 0, 10), // "QLabTabWgt"
QT_MOC_LITERAL(1, 11, 10), // "tabsChange"
QT_MOC_LITERAL(2, 22, 0) // ""

    },
    "QLabTabWgt\0tabsChange\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QLabTabWgt[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,

       0        // eod
};

void QLabTabWgt::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QLabTabWgt *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->tabsChange((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (QLabTabWgt::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QLabTabWgt::tabsChange)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject QLabTabWgt::staticMetaObject = { {
    &QTabWidget::staticMetaObject,
    qt_meta_stringdata_QLabTabWgt.data,
    qt_meta_data_QLabTabWgt,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QLabTabWgt::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QLabTabWgt::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QLabTabWgt.stringdata0))
        return static_cast<void*>(this);
    return QTabWidget::qt_metacast(_clname);
}

int QLabTabWgt::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTabWidget::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void QLabTabWgt::tabsChange(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_QLabWorkerWgt_t {
    QByteArrayData data[17];
    char stringdata0[206];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QLabWorkerWgt_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QLabWorkerWgt_t qt_meta_stringdata_QLabWorkerWgt = {
    {
QT_MOC_LITERAL(0, 0, 13), // "QLabWorkerWgt"
QT_MOC_LITERAL(1, 14, 14), // "showWelcomeWgt"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 8), // "saveData"
QT_MOC_LITERAL(4, 39, 12), // "QFileWorker*"
QT_MOC_LITERAL(5, 52, 6), // "stream"
QT_MOC_LITERAL(6, 59, 8), // "openData"
QT_MOC_LITERAL(7, 68, 9), // "checkTabs"
QT_MOC_LITERAL(8, 78, 9), // "changeTab"
QT_MOC_LITERAL(9, 88, 4), // "prev"
QT_MOC_LITERAL(10, 93, 4), // "next"
QT_MOC_LITERAL(11, 98, 10), // "showErrMsg"
QT_MOC_LITERAL(12, 109, 7), // "errCode"
QT_MOC_LITERAL(13, 117, 10), // "dataEdited"
QT_MOC_LITERAL(14, 128, 25), // "on_pushButtonBack_clicked"
QT_MOC_LITERAL(15, 154, 25), // "on_pushButtonNext_clicked"
QT_MOC_LITERAL(16, 180, 25) // "on_pushButtonSave_clicked"

    },
    "QLabWorkerWgt\0showWelcomeWgt\0\0saveData\0"
    "QFileWorker*\0stream\0openData\0checkTabs\0"
    "changeTab\0prev\0next\0showErrMsg\0errCode\0"
    "dataEdited\0on_pushButtonBack_clicked\0"
    "on_pushButtonNext_clicked\0"
    "on_pushButtonSave_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QLabWorkerWgt[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,   65,    2, 0x0a /* Public */,
       6,    1,   68,    2, 0x0a /* Public */,
       7,    0,   71,    2, 0x09 /* Protected */,
       8,    2,   72,    2, 0x09 /* Protected */,
      11,    1,   77,    2, 0x09 /* Protected */,
      13,    0,   80,    2, 0x09 /* Protected */,
      14,    0,   81,    2, 0x08 /* Private */,
      15,    0,   82,    2, 0x08 /* Private */,
      16,    0,   83,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    9,   10,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void QLabWorkerWgt::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QLabWorkerWgt *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->showWelcomeWgt(); break;
        case 1: _t->saveData((*reinterpret_cast< QFileWorker*(*)>(_a[1]))); break;
        case 2: _t->openData((*reinterpret_cast< QFileWorker*(*)>(_a[1]))); break;
        case 3: _t->checkTabs(); break;
        case 4: _t->changeTab((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 5: _t->showErrMsg((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->dataEdited(); break;
        case 7: _t->on_pushButtonBack_clicked(); break;
        case 8: _t->on_pushButtonNext_clicked(); break;
        case 9: _t->on_pushButtonSave_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QFileWorker* >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QFileWorker* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (QLabWorkerWgt::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QLabWorkerWgt::showWelcomeWgt)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject QLabWorkerWgt::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_QLabWorkerWgt.data,
    qt_meta_data_QLabWorkerWgt,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QLabWorkerWgt::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QLabWorkerWgt::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QLabWorkerWgt.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int QLabWorkerWgt::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void QLabWorkerWgt::showWelcomeWgt()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
