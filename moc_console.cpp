/****************************************************************************
** Meta object code from reading C++ file 'console.hpp'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "console.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'console.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Console[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: signature, parameters, type, tag, flags
       9,    8,    8,    8, 0x05,
      16,    8,    8,    8, 0x05,
      24,    8,    8,    8, 0x05,
      31,    8,    8,    8, 0x05,
      43,   38,    8,    8, 0x05,
      65,    8,    8,    8, 0x05,

 // slots: signature, parameters, type, tag, flags
      75,    8,    8,    8, 0x08,
      89,    8,    8,    8, 0x08,
     102,    8,    8,    8, 0x08,
     114,    8,    8,    8, 0x08,
     128,  126,    8,    8, 0x08,
     151,    8,    8,    8, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Console[] = {
    "Console\0\0quit()\0Start()\0Stop()\0Exit()\0"
    "time\0TimerChange(uint64_t)\0Restart()\0"
    "readCommand()\0SLOT_Start()\0SLOT_Stop()\0"
    "SLOT_Exit()\0t\0SLOT_Timeout(uint64_t)\0"
    "SLOT_WhatToDo()\0"
};

void Console::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Console *_t = static_cast<Console *>(_o);
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
        case 10: _t->SLOT_Timeout((*reinterpret_cast< uint64_t(*)>(_a[1]))); break;
        case 11: _t->SLOT_WhatToDo(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Console::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Console::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Console,
      qt_meta_data_Console, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Console::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Console::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Console::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Console))
        return static_cast<void*>(const_cast< Console*>(this));
    return QObject::qt_metacast(_clname);
}

int Console::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void Console::quit()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void Console::Start()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void Console::Stop()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void Console::Exit()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void Console::TimerChange(uint64_t _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void Console::Restart()
{
    QMetaObject::activate(this, &staticMetaObject, 5, 0);
}
QT_END_MOC_NAMESPACE
