/****************************************************************************
** Meta object code from reading C++ file 'clientnetwork.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../QtChess/clientnetwork.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'clientnetwork.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ClientNetwork_t {
    QByteArrayData data[13];
    char stringdata0[139];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ClientNetwork_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ClientNetwork_t qt_meta_stringdata_ClientNetwork = {
    {
QT_MOC_LITERAL(0, 0, 13), // "ClientNetwork"
QT_MOC_LITERAL(1, 14, 14), // "processMessage"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 5), // "char*"
QT_MOC_LITERAL(4, 36, 3), // "msg"
QT_MOC_LITERAL(5, 40, 3), // "len"
QT_MOC_LITERAL(6, 44, 16), // "connStateChanged"
QT_MOC_LITERAL(7, 61, 9), // "connected"
QT_MOC_LITERAL(8, 71, 12), // "disconnected"
QT_MOC_LITERAL(9, 84, 8), // "readData"
QT_MOC_LITERAL(10, 93, 12), // "displayError"
QT_MOC_LITERAL(11, 106, 28), // "QAbstractSocket::SocketError"
QT_MOC_LITERAL(12, 135, 3) // "err"

    },
    "ClientNetwork\0processMessage\0\0char*\0"
    "msg\0len\0connStateChanged\0connected\0"
    "disconnected\0readData\0displayError\0"
    "QAbstractSocket::SocketError\0err"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ClientNetwork[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   44,    2, 0x06 /* Public */,
       6,    1,   49,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   52,    2, 0x0a /* Public */,
       8,    0,   53,    2, 0x0a /* Public */,
       9,    0,   54,    2, 0x0a /* Public */,
      10,    1,   55,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int,    4,    5,
    QMetaType::Void, QMetaType::Bool,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 11,   12,

       0        // eod
};

void ClientNetwork::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ClientNetwork *_t = static_cast<ClientNetwork *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->processMessage((*reinterpret_cast< char*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->connStateChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->connected(); break;
        case 3: _t->disconnected(); break;
        case 4: _t->readData(); break;
        case 5: _t->displayError((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractSocket::SocketError >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ClientNetwork::*)(char * , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ClientNetwork::processMessage)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ClientNetwork::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ClientNetwork::connStateChanged)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ClientNetwork::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ClientNetwork.data,
      qt_meta_data_ClientNetwork,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ClientNetwork::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ClientNetwork::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ClientNetwork.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ClientNetwork::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void ClientNetwork::processMessage(char * _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ClientNetwork::connStateChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
