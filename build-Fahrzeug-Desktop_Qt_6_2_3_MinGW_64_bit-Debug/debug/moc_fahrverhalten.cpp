/****************************************************************************
** Meta object code from reading C++ file 'fahrverhalten.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../Fahrzeug_GUI/fahrverhalten.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'fahrverhalten.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Fahrverhalten_t {
    const uint offsetsAndSize[16];
    char stringdata0[88];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_Fahrverhalten_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_Fahrverhalten_t qt_meta_stringdata_Fahrverhalten = {
    {
QT_MOC_LITERAL(0, 13), // "Fahrverhalten"
QT_MOC_LITERAL(14, 15), // "geschwindigkeit"
QT_MOC_LITERAL(30, 8), // "drehzahl"
QT_MOC_LITERAL(39, 7), // "bremsen"
QT_MOC_LITERAL(47, 7), // "reibung"
QT_MOC_LITERAL(55, 4), // "gang"
QT_MOC_LITERAL(60, 12), // "hochschalten"
QT_MOC_LITERAL(73, 14) // "runterschalten"

    },
    "Fahrverhalten\0geschwindigkeit\0drehzahl\0"
    "bremsen\0reibung\0gang\0hochschalten\0"
    "runterschalten"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Fahrverhalten[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       7,   14, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // properties: name, type, flags
       1, QMetaType::Int, 0x00015003, uint(-1), 0,
       2, QMetaType::Int, 0x00015001, uint(-1), 0,
       3, QMetaType::Int, 0x00015002, uint(-1), 0,
       4, QMetaType::Int, 0x00015002, uint(-1), 0,
       5, QMetaType::Int, 0x00015001, uint(-1), 0,
       6, QMetaType::Int, 0x00015002, uint(-1), 0,
       7, QMetaType::Int, 0x00015002, uint(-1), 0,

       0        // eod
};

void Fahrverhalten::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{

#ifndef QT_NO_PROPERTIES
    if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<Fahrverhalten *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = _t->getBeschleunigen(); break;
        case 1: *reinterpret_cast< int*>(_v) = _t->getDrehzahl(); break;
        case 4: *reinterpret_cast< int*>(_v) = _t->getGang(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<Fahrverhalten *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->beschleunigen(*reinterpret_cast< int*>(_v)); break;
        case 2: _t->bremsen(*reinterpret_cast< int*>(_v)); break;
        case 3: _t->reibungsKraft(*reinterpret_cast< int*>(_v)); break;
        case 5: _t->hochSchalten(*reinterpret_cast< int*>(_v)); break;
        case 6: _t->runterSchalten(*reinterpret_cast< int*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    } else if (_c == QMetaObject::BindableProperty) {
    }
#endif // QT_NO_PROPERTIES
    (void)_o;
    (void)_id;
    (void)_c;
    (void)_a;
}

const QMetaObject Fahrverhalten::staticMetaObject = { {
    QMetaObject::SuperData::link<Steuereinheit::staticMetaObject>(),
    qt_meta_stringdata_Fahrverhalten.offsetsAndSize,
    qt_meta_data_Fahrverhalten,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_Fahrverhalten_t
, QtPrivate::TypeAndForceComplete<int, std::true_type>, QtPrivate::TypeAndForceComplete<int, std::true_type>, QtPrivate::TypeAndForceComplete<int, std::true_type>, QtPrivate::TypeAndForceComplete<int, std::true_type>, QtPrivate::TypeAndForceComplete<int, std::true_type>, QtPrivate::TypeAndForceComplete<int, std::true_type>, QtPrivate::TypeAndForceComplete<int, std::true_type>, QtPrivate::TypeAndForceComplete<Fahrverhalten, std::true_type>



>,
    nullptr
} };


const QMetaObject *Fahrverhalten::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Fahrverhalten::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Fahrverhalten.stringdata0))
        return static_cast<void*>(this);
    return Steuereinheit::qt_metacast(_clname);
}

int Fahrverhalten::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Steuereinheit::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    
#ifndef QT_NO_PROPERTIES
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
