/****************************************************************************
** Meta object code from reading C++ file 'console.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "console.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'console.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Console_t {
    QByteArrayData data[19];
    char stringdata0[160];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Console_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Console_t qt_meta_stringdata_Console = {
    {
QT_MOC_LITERAL(0, 0, 7), // "Console"
QT_MOC_LITERAL(1, 8, 4), // "quit"
QT_MOC_LITERAL(2, 13, 0), // ""
QT_MOC_LITERAL(3, 14, 5), // "Start"
QT_MOC_LITERAL(4, 20, 4), // "Stop"
QT_MOC_LITERAL(5, 25, 4), // "Exit"
QT_MOC_LITERAL(6, 30, 11), // "TimerChange"
QT_MOC_LITERAL(7, 42, 8), // "uint64_t"
QT_MOC_LITERAL(8, 51, 4), // "time"
QT_MOC_LITERAL(9, 56, 7), // "Restart"
QT_MOC_LITERAL(10, 64, 11), // "readCommand"
QT_MOC_LITERAL(11, 76, 10), // "SLOT_Start"
QT_MOC_LITERAL(12, 87, 9), // "SLOT_Stop"
QT_MOC_LITERAL(13, 97, 9), // "SLOT_Exit"
QT_MOC_LITERAL(14, 107, 12), // "SLOT_Restart"
QT_MOC_LITERAL(15, 120, 10), // "restartApp"
QT_MOC_LITERAL(16, 131, 12), // "SLOT_Timeout"
QT_MOC_LITERAL(17, 144, 1), // "t"
QT_MOC_LITERAL(18, 146, 13) // "SLOT_WhatToDo"

    },
    "Console\0quit\0\0Start\0Stop\0Exit\0TimerChange\0"
    "uint64_t\0time\0Restart\0readCommand\0"
    "SLOT_Start\0SLOT_Stop\0SLOT_Exit\0"
    "SLOT_Restart\0restartApp\0SLOT_Timeout\0"
    "t\0SLOT_WhatToDo"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Console[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x06 /* Public */,
       3,    0,   85,    2, 0x06 /* Public */,
       4,    0,   86,    2, 0x06 /* Public */,
       5,    0,   87,    2, 0x06 /* Public */,
       6,    1,   88,    2, 0x06 /* Public */,
       9,    0,   91,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    0,   92,    2, 0x08 /* Private */,
      11,    0,   93,    2, 0x0a /* Public */,
      12,    0,   94,    2, 0x0a /* Public */,
      13,    0,   95,    2, 0x0a /* Public */,
      14,    0,   96,    2, 0x0a /* Public */,
      15,    0,   97,    2, 0x0a /* Public */,
      16,    1,   98,    2, 0x0a /* Public */,
      18,    0,  101,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,   17,
    QMetaType::Void,

       0        // eod
};

void Console::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Console *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->quit(); break;
        case 1: _t->Start(); break;
        case 2: _t->Stop(); break;
        case 3: _t->Exit(); break;
        case 4: _t->TimerChange((*reinterpret_cast< uint64_t(*)>(_a[1]))); break;
        case 5: _t->Restart(); break;
        case 6: _t->readCommand(); break;
        case 7: _t->SLOT_Start(); break;
        case 8: _t->SLOT_Stop(); break;
        case 9: _t->SLOT_Exit(); break;
        case 10: _t->SLOT_Restart(); break;
        case 11: _t->restartApp(); break;
        case 12: _t->SLOT_Timeout((*reinterpret_cast< uint64_t(*)>(_a[1]))); break;
        case 13: _t->SLOT_WhatToDo(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Console::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Console::quit)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Console::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Console::Start)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Console::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Console::Stop)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Console::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Console::Exit)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Console::*)(uint64_t );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Console::TimerChange)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (Console::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Console::Restart)) {
                *result = 5;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Console::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_Console.data,
    qt_meta_data_Console,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Console::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Console::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Console.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Console::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void Console::quit()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Console::Start()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Console::Stop()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void Console::Exit()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void Console::TimerChange(uint64_t _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void Console::Restart()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
