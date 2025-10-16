/****************************************************************************
** Meta object code from reading C++ file 'qlabcarnocardwgt.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.12)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../qlabcarnocardwgt.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qlabcarnocardwgt.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.12. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QCarnoTextWgt_t {
    QByteArrayData data[9];
    char stringdata0[88];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QCarnoTextWgt_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QCarnoTextWgt_t qt_meta_stringdata_QCarnoTextWgt = {
    {
QT_MOC_LITERAL(0, 0, 13), // "QCarnoTextWgt"
QT_MOC_LITERAL(1, 14, 16), // "iamSelectedInRow"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 13), // "setHeaderText"
QT_MOC_LITERAL(4, 46, 4), // "text"
QT_MOC_LITERAL(5, 51, 11), // "setTermText"
QT_MOC_LITERAL(6, 63, 13), // "setResultText"
QT_MOC_LITERAL(7, 77, 6), // "setRow"
QT_MOC_LITERAL(8, 84, 3) // "row"

    },
    "QCarnoTextWgt\0iamSelectedInRow\0\0"
    "setHeaderText\0text\0setTermText\0"
    "setResultText\0setRow\0row"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QCarnoTextWgt[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,   42,    2, 0x0a /* Public */,
       5,    1,   45,    2, 0x0a /* Public */,
       6,    1,   48,    2, 0x0a /* Public */,
       7,    1,   51,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::Int,    8,

       0        // eod
};

void QCarnoTextWgt::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QCarnoTextWgt *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->iamSelectedInRow((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->setHeaderText((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->setTermText((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->setResultText((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->setRow((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (QCarnoTextWgt::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QCarnoTextWgt::iamSelectedInRow)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject QCarnoTextWgt::staticMetaObject = { {
    &QTextBrowser::staticMetaObject,
    qt_meta_stringdata_QCarnoTextWgt.data,
    qt_meta_data_QCarnoTextWgt,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QCarnoTextWgt::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QCarnoTextWgt::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QCarnoTextWgt.stringdata0))
        return static_cast<void*>(this);
    return QTextBrowser::qt_metacast(_clname);
}

int QCarnoTextWgt::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTextBrowser::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void QCarnoTextWgt::iamSelectedInRow(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_QTermsListWgt_t {
    QByteArrayData data[9];
    char stringdata0[89];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QTermsListWgt_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QTermsListWgt_t qt_meta_stringdata_QTermsListWgt = {
    {
QT_MOC_LITERAL(0, 0, 13), // "QTermsListWgt"
QT_MOC_LITERAL(1, 14, 12), // "termSelected"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 16), // "termsListIsEmpty"
QT_MOC_LITERAL(4, 45, 7), // "addTerm"
QT_MOC_LITERAL(5, 53, 4), // "text"
QT_MOC_LITERAL(6, 58, 15), // "delSelectedTerm"
QT_MOC_LITERAL(7, 74, 10), // "selectTerm"
QT_MOC_LITERAL(8, 85, 3) // "row"

    },
    "QTermsListWgt\0termSelected\0\0"
    "termsListIsEmpty\0addTerm\0text\0"
    "delSelectedTerm\0selectTerm\0row"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QTermsListWgt[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,
       3,    0,   42,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   43,    2, 0x0a /* Public */,
       6,    0,   46,    2, 0x0a /* Public */,
       7,    1,   47,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    8,

       0        // eod
};

void QTermsListWgt::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QTermsListWgt *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->termSelected((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->termsListIsEmpty(); break;
        case 2: _t->addTerm((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->delSelectedTerm(); break;
        case 4: _t->selectTerm((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (QTermsListWgt::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QTermsListWgt::termSelected)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (QTermsListWgt::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QTermsListWgt::termsListIsEmpty)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject QTermsListWgt::staticMetaObject = { {
    &QTableWidget::staticMetaObject,
    qt_meta_stringdata_QTermsListWgt.data,
    qt_meta_data_QTermsListWgt,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QTermsListWgt::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QTermsListWgt::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QTermsListWgt.stringdata0))
        return static_cast<void*>(this);
    return QTableWidget::qt_metacast(_clname);
}

int QTermsListWgt::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTableWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void QTermsListWgt::termSelected(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QTermsListWgt::termsListIsEmpty()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
struct qt_meta_stringdata_QCarnoCardWgt_t {
    QByteArrayData data[12];
    char stringdata0[112];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QCarnoCardWgt_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QCarnoCardWgt_t qt_meta_stringdata_QCarnoCardWgt = {
    {
QT_MOC_LITERAL(0, 0, 13), // "QCarnoCardWgt"
QT_MOC_LITERAL(1, 14, 10), // "dataEdited"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 7), // "setFunc"
QT_MOC_LITERAL(4, 34, 4), // "func"
QT_MOC_LITERAL(5, 39, 10), // "setExample"
QT_MOC_LITERAL(6, 50, 5), // "state"
QT_MOC_LITERAL(7, 56, 9), // "showCover"
QT_MOC_LITERAL(8, 66, 5), // "cover"
QT_MOC_LITERAL(9, 72, 16), // "clickedTableItem"
QT_MOC_LITERAL(10, 89, 17), // "QTableWidgetItem*"
QT_MOC_LITERAL(11, 107, 4) // "item"

    },
    "QCarnoCardWgt\0dataEdited\0\0setFunc\0"
    "func\0setExample\0state\0showCover\0cover\0"
    "clickedTableItem\0QTableWidgetItem*\0"
    "item"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QCarnoCardWgt[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,   40,    2, 0x0a /* Public */,
       5,    1,   43,    2, 0x0a /* Public */,
       7,    1,   46,    2, 0x0a /* Public */,
       9,    1,   49,    2, 0x09 /* Protected */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::Bool,    6,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, 0x80000000 | 10,   11,

       0        // eod
};

void QCarnoCardWgt::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QCarnoCardWgt *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->dataEdited(); break;
        case 1: _t->setFunc((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->setExample((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->showCover((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->clickedTableItem((*reinterpret_cast< QTableWidgetItem*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (QCarnoCardWgt::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QCarnoCardWgt::dataEdited)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject QCarnoCardWgt::staticMetaObject = { {
    &QTableWidget::staticMetaObject,
    qt_meta_stringdata_QCarnoCardWgt.data,
    qt_meta_data_QCarnoCardWgt,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QCarnoCardWgt::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QCarnoCardWgt::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QCarnoCardWgt.stringdata0))
        return static_cast<void*>(this);
    return QTableWidget::qt_metacast(_clname);
}

int QCarnoCardWgt::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTableWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void QCarnoCardWgt::dataEdited()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
struct qt_meta_stringdata_QLabCarnoCardWgt_t {
    QByteArrayData data[18];
    char stringdata0[271];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QLabCarnoCardWgt_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QLabCarnoCardWgt_t qt_meta_stringdata_QLabCarnoCardWgt = {
    {
QT_MOC_LITERAL(0, 0, 16), // "QLabCarnoCardWgt"
QT_MOC_LITERAL(1, 17, 10), // "dataEdited"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 9), // "showCover"
QT_MOC_LITERAL(4, 39, 3), // "row"
QT_MOC_LITERAL(5, 43, 12), // "updateResult"
QT_MOC_LITERAL(6, 56, 11), // "basisEdited"
QT_MOC_LITERAL(7, 68, 10), // "showErrMsg"
QT_MOC_LITERAL(8, 79, 7), // "errCode"
QT_MOC_LITERAL(9, 87, 28), // "on_pushButtonAddTerm_clicked"
QT_MOC_LITERAL(10, 116, 28), // "on_pushButtonDelTerm_clicked"
QT_MOC_LITERAL(11, 145, 30), // "on_pushButtonCardCheck_clicked"
QT_MOC_LITERAL(12, 176, 32), // "on_pushButtonCheckResult_clicked"
QT_MOC_LITERAL(13, 209, 31), // "on_pushButtonCheckBasis_clicked"
QT_MOC_LITERAL(14, 241, 12), // "minimizeFunc"
QT_MOC_LITERAL(15, 254, 7), // "setFunc"
QT_MOC_LITERAL(16, 262, 3), // "num"
QT_MOC_LITERAL(17, 266, 4) // "func"

    },
    "QLabCarnoCardWgt\0dataEdited\0\0showCover\0"
    "row\0updateResult\0basisEdited\0showErrMsg\0"
    "errCode\0on_pushButtonAddTerm_clicked\0"
    "on_pushButtonDelTerm_clicked\0"
    "on_pushButtonCardCheck_clicked\0"
    "on_pushButtonCheckResult_clicked\0"
    "on_pushButtonCheckBasis_clicked\0"
    "minimizeFunc\0setFunc\0num\0func"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QLabCarnoCardWgt[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,   75,    2, 0x09 /* Protected */,
       5,    0,   78,    2, 0x09 /* Protected */,
       6,    0,   79,    2, 0x09 /* Protected */,
       7,    1,   80,    2, 0x09 /* Protected */,
       9,    0,   83,    2, 0x08 /* Private */,
      10,    0,   84,    2, 0x08 /* Private */,
      11,    0,   85,    2, 0x08 /* Private */,
      12,    0,   86,    2, 0x08 /* Private */,
      13,    0,   87,    2, 0x08 /* Private */,
      14,    0,   88,    2, 0x0a /* Public */,
      15,    2,   89,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,   16,   17,

       0        // eod
};

void QLabCarnoCardWgt::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QLabCarnoCardWgt *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->dataEdited(); break;
        case 1: _t->showCover((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->updateResult(); break;
        case 3: _t->basisEdited(); break;
        case 4: _t->showErrMsg((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->on_pushButtonAddTerm_clicked(); break;
        case 6: _t->on_pushButtonDelTerm_clicked(); break;
        case 7: _t->on_pushButtonCardCheck_clicked(); break;
        case 8: _t->on_pushButtonCheckResult_clicked(); break;
        case 9: _t->on_pushButtonCheckBasis_clicked(); break;
        case 10: _t->minimizeFunc(); break;
        case 11: _t->setFunc((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (QLabCarnoCardWgt::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QLabCarnoCardWgt::dataEdited)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject QLabCarnoCardWgt::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_QLabCarnoCardWgt.data,
    qt_meta_data_QLabCarnoCardWgt,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QLabCarnoCardWgt::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QLabCarnoCardWgt::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QLabCarnoCardWgt.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int QLabCarnoCardWgt::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void QLabCarnoCardWgt::dataEdited()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
