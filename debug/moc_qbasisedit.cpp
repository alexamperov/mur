/****************************************************************************
** Meta object code from reading C++ file 'qbasisedit.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.12)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../qbasisedit.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qbasisedit.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.12. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QBasisTextWgt_t {
    QByteArrayData data[17];
    char stringdata0[190];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QBasisTextWgt_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QBasisTextWgt_t qt_meta_stringdata_QBasisTextWgt = {
    {
QT_MOC_LITERAL(0, 0, 13), // "QBasisTextWgt"
QT_MOC_LITERAL(1, 14, 10), // "iAmPressed"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 14), // "QBasisTextWgt*"
QT_MOC_LITERAL(4, 41, 18), // "iAmPressedWithCtrl"
QT_MOC_LITERAL(5, 60, 19), // "iAmPressedWithShift"
QT_MOC_LITERAL(6, 80, 17), // "setTermTextSignal"
QT_MOC_LITERAL(7, 98, 7), // "clicked"
QT_MOC_LITERAL(8, 106, 11), // "setTermText"
QT_MOC_LITERAL(9, 118, 4), // "text"
QT_MOC_LITERAL(10, 123, 11), // "setBttnText"
QT_MOC_LITERAL(11, 135, 12), // "setTermIndex"
QT_MOC_LITERAL(12, 148, 5), // "index"
QT_MOC_LITERAL(13, 154, 11), // "setBttnWdth"
QT_MOC_LITERAL(14, 166, 4), // "wdth"
QT_MOC_LITERAL(15, 171, 8), // "toggleOn"
QT_MOC_LITERAL(16, 180, 9) // "toggleOff"

    },
    "QBasisTextWgt\0iAmPressed\0\0QBasisTextWgt*\0"
    "iAmPressedWithCtrl\0iAmPressedWithShift\0"
    "setTermTextSignal\0clicked\0setTermText\0"
    "text\0setBttnText\0setTermIndex\0index\0"
    "setBttnWdth\0wdth\0toggleOn\0toggleOff"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QBasisTextWgt[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   74,    2, 0x06 /* Public */,
       4,    1,   77,    2, 0x06 /* Public */,
       5,    1,   80,    2, 0x06 /* Public */,
       6,    2,   83,    2, 0x06 /* Public */,
       7,    0,   88,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    1,   89,    2, 0x0a /* Public */,
      10,    1,   92,    2, 0x0a /* Public */,
      11,    1,   95,    2, 0x0a /* Public */,
      13,    1,   98,    2, 0x0a /* Public */,
      15,    0,  101,    2, 0x09 /* Protected */,
      16,    0,  102,    2, 0x09 /* Protected */,
       8,    2,  103,    2, 0x09 /* Protected */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    2,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void, QMetaType::Int,   14,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,   12,    9,

       0        // eod
};

void QBasisTextWgt::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QBasisTextWgt *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->iAmPressed((*reinterpret_cast< QBasisTextWgt*(*)>(_a[1]))); break;
        case 1: _t->iAmPressedWithCtrl((*reinterpret_cast< QBasisTextWgt*(*)>(_a[1]))); break;
        case 2: _t->iAmPressedWithShift((*reinterpret_cast< QBasisTextWgt*(*)>(_a[1]))); break;
        case 3: _t->setTermTextSignal((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 4: _t->clicked(); break;
        case 5: _t->setTermText((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->setBttnText((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->setTermIndex((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->setBttnWdth((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->toggleOn(); break;
        case 10: _t->toggleOff(); break;
        case 11: _t->setTermText((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QBasisTextWgt* >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QBasisTextWgt* >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QBasisTextWgt* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (QBasisTextWgt::*)(QBasisTextWgt * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QBasisTextWgt::iAmPressed)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (QBasisTextWgt::*)(QBasisTextWgt * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QBasisTextWgt::iAmPressedWithCtrl)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (QBasisTextWgt::*)(QBasisTextWgt * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QBasisTextWgt::iAmPressedWithShift)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (QBasisTextWgt::*)(int , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QBasisTextWgt::setTermTextSignal)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (QBasisTextWgt::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QBasisTextWgt::clicked)) {
                *result = 4;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject QBasisTextWgt::staticMetaObject = { {
    &QTextBrowser::staticMetaObject,
    qt_meta_stringdata_QBasisTextWgt.data,
    qt_meta_data_QBasisTextWgt,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QBasisTextWgt::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QBasisTextWgt::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QBasisTextWgt.stringdata0))
        return static_cast<void*>(this);
    return QTextBrowser::qt_metacast(_clname);
}

int QBasisTextWgt::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTextBrowser::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void QBasisTextWgt::iAmPressed(QBasisTextWgt * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QBasisTextWgt::iAmPressedWithCtrl(QBasisTextWgt * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void QBasisTextWgt::iAmPressedWithShift(QBasisTextWgt * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void QBasisTextWgt::setTermTextSignal(int _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void QBasisTextWgt::clicked()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}
struct qt_meta_stringdata_QBasisEdit_t {
    QByteArrayData data[20];
    char stringdata0[223];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QBasisEdit_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QBasisEdit_t qt_meta_stringdata_QBasisEdit = {
    {
QT_MOC_LITERAL(0, 0, 10), // "QBasisEdit"
QT_MOC_LITERAL(1, 11, 16), // "readyForInitData"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 17), // "setTermTextSignal"
QT_MOC_LITERAL(4, 47, 10), // "showErrMsg"
QT_MOC_LITERAL(5, 58, 6), // "edited"
QT_MOC_LITERAL(6, 65, 6), // "setExp"
QT_MOC_LITERAL(7, 72, 4), // "func"
QT_MOC_LITERAL(8, 77, 8), // "saveData"
QT_MOC_LITERAL(9, 86, 12), // "QFileWorker*"
QT_MOC_LITERAL(10, 99, 6), // "stream"
QT_MOC_LITERAL(11, 106, 8), // "openData"
QT_MOC_LITERAL(12, 115, 12), // "setSelection"
QT_MOC_LITERAL(13, 128, 14), // "QBasisTextWgt*"
QT_MOC_LITERAL(14, 143, 3), // "wgt"
QT_MOC_LITERAL(15, 147, 20), // "setSelectionWithCtrl"
QT_MOC_LITERAL(16, 168, 21), // "setSelectionWithShift"
QT_MOC_LITERAL(17, 190, 10), // "clickedNot"
QT_MOC_LITERAL(18, 201, 10), // "clickedMul"
QT_MOC_LITERAL(19, 212, 10) // "clickedAdd"

    },
    "QBasisEdit\0readyForInitData\0\0"
    "setTermTextSignal\0showErrMsg\0edited\0"
    "setExp\0func\0saveData\0QFileWorker*\0"
    "stream\0openData\0setSelection\0"
    "QBasisTextWgt*\0wgt\0setSelectionWithCtrl\0"
    "setSelectionWithShift\0clickedNot\0"
    "clickedMul\0clickedAdd"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QBasisEdit[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x06 /* Public */,
       3,    2,   80,    2, 0x06 /* Public */,
       4,    1,   85,    2, 0x06 /* Public */,
       5,    0,   88,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,   89,    2, 0x0a /* Public */,
       8,    1,   92,    2, 0x0a /* Public */,
      11,    1,   95,    2, 0x0a /* Public */,
      12,    1,   98,    2, 0x09 /* Protected */,
      15,    1,  101,    2, 0x09 /* Protected */,
      16,    1,  104,    2, 0x09 /* Protected */,
      17,    0,  107,    2, 0x09 /* Protected */,
      18,    0,  108,    2, 0x09 /* Protected */,
      19,    0,  109,    2, 0x09 /* Protected */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    2,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, 0x80000000 | 13,   14,
    QMetaType::Void, 0x80000000 | 13,   14,
    QMetaType::Void, 0x80000000 | 13,   14,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void QBasisEdit::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QBasisEdit *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->readyForInitData(); break;
        case 1: _t->setTermTextSignal((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 2: _t->showErrMsg((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->edited(); break;
        case 4: _t->setExp((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->saveData((*reinterpret_cast< QFileWorker*(*)>(_a[1]))); break;
        case 6: _t->openData((*reinterpret_cast< QFileWorker*(*)>(_a[1]))); break;
        case 7: _t->setSelection((*reinterpret_cast< QBasisTextWgt*(*)>(_a[1]))); break;
        case 8: _t->setSelectionWithCtrl((*reinterpret_cast< QBasisTextWgt*(*)>(_a[1]))); break;
        case 9: _t->setSelectionWithShift((*reinterpret_cast< QBasisTextWgt*(*)>(_a[1]))); break;
        case 10: _t->clickedNot(); break;
        case 11: _t->clickedMul(); break;
        case 12: _t->clickedAdd(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QFileWorker* >(); break;
            }
            break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QFileWorker* >(); break;
            }
            break;
        case 7:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QBasisTextWgt* >(); break;
            }
            break;
        case 8:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QBasisTextWgt* >(); break;
            }
            break;
        case 9:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QBasisTextWgt* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (QBasisEdit::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QBasisEdit::readyForInitData)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (QBasisEdit::*)(int , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QBasisEdit::setTermTextSignal)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (QBasisEdit::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QBasisEdit::showErrMsg)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (QBasisEdit::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QBasisEdit::edited)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject QBasisEdit::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_QBasisEdit.data,
    qt_meta_data_QBasisEdit,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QBasisEdit::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QBasisEdit::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QBasisEdit.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int QBasisEdit::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void QBasisEdit::readyForInitData()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void QBasisEdit::setTermTextSignal(int _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void QBasisEdit::showErrMsg(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void QBasisEdit::edited()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
