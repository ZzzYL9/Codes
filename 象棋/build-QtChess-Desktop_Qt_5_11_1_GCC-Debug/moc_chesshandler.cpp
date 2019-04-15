/****************************************************************************
** Meta object code from reading C++ file 'chesshandler.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../QtChess/chesshandler.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'chesshandler.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ChessHandler_t {
    QByteArrayData data[10];
    char stringdata0[91];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ChessHandler_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ChessHandler_t qt_meta_stringdata_ChessHandler = {
    {
QT_MOC_LITERAL(0, 0, 12), // "ChessHandler"
QT_MOC_LITERAL(1, 13, 11), // "refreshGame"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 11), // "refreshType"
QT_MOC_LITERAL(4, 38, 14), // "processMessage"
QT_MOC_LITERAL(5, 53, 5), // "char*"
QT_MOC_LITERAL(6, 59, 3), // "msg"
QT_MOC_LITERAL(7, 63, 3), // "len"
QT_MOC_LITERAL(8, 67, 16), // "connStateChanged"
QT_MOC_LITERAL(9, 84, 6) // "status"

    },
    "ChessHandler\0refreshGame\0\0refreshType\0"
    "processMessage\0char*\0msg\0len\0"
    "connStateChanged\0status"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ChessHandler[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    2,   32,    2, 0x0a /* Public */,
       8,    1,   37,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 5, QMetaType::Int,    6,    7,
    QMetaType::Void, QMetaType::Bool,    9,

       0        // eod
};

void ChessHandler::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ChessHandler *_t = static_cast<ChessHandler *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->refreshGame((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->processMessage((*reinterpret_cast< char*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->connStateChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ChessHandler::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ChessHandler::refreshGame)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ChessHandler::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ChessHandler.data,
      qt_meta_data_ChessHandler,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ChessHandler::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ChessHandler::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ChessHandler.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ChessHandler::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
void ChessHandler::refreshGame(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
