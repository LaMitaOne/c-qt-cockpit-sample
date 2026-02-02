/****************************************************************************
** Meta object code from reading C++ file 'fahrzeuginfo.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../Fahrzeug_GUI/fahrzeuginfo.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'fahrzeuginfo.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FahrzeugInfo_t {
    const uint offsetsAndSize[14];
    char stringdata0[68];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_FahrzeugInfo_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_FahrzeugInfo_t qt_meta_stringdata_FahrzeugInfo = {
    {
QT_MOC_LITERAL(0, 12), // "FahrzeugInfo"
QT_MOC_LITERAL(13, 9), // "verbrauch"
QT_MOC_LITERAL(23, 4), // "temp"
QT_MOC_LITERAL(28, 7), // "strecke"
QT_MOC_LITERAL(36, 10), // "gesStrecke"
QT_MOC_LITERAL(47, 9), // "streckeKM"
QT_MOC_LITERAL(57, 10) // "tankinhalt"

    },
    "FahrzeugInfo\0verbrauch\0temp\0strecke\0"
    "gesStrecke\0streckeKM\0tankinhalt"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FahrzeugInfo[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       6,   14, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // properties: name, type, flags
       1, QMetaType::QString, 0x00015001, uint(-1), 0,
       2, QMetaType::Int, 0x00015001, uint(-1), 0,
       3, QMetaType::Int, 0x00015002, uint(-1), 0,
       4, QMetaType::Int, 0x00015001, uint(-1), 0,
       5, QMetaType::Int, 0x00015001, uint(-1), 0,
       6, QMetaType::Int, 0x00015001, uint(-1), 0,

       0        // eod
};

void FahrzeugInfo::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{

#ifndef QT_NO_PROPERTIES
    if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<FahrzeugInfo *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->getVerbrauch(); break;
        case 1: *reinterpret_cast< int*>(_v) = _t->getTemp(); break;
        case 3: *reinterpret_cast< int*>(_v) = _t->getGesStrecke(); break;
        case 4: *reinterpret_cast< int*>(_v) = _t->getStreckeKM(); break;
        case 5: *reinterpret_cast< int*>(_v) = _t->getTankInhalt(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<FahrzeugInfo *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 2: _t->streckePlus(*reinterpret_cast< int*>(_v)); break;
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

const QMetaObject FahrzeugInfo::staticMetaObject = { {
    QMetaObject::SuperData::link<Steuereinheit::staticMetaObject>(),
    qt_meta_stringdata_FahrzeugInfo.offsetsAndSize,
    qt_meta_data_FahrzeugInfo,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_FahrzeugInfo_t
, QtPrivate::TypeAndForceComplete<QString, std::true_type>, QtPrivate::TypeAndForceComplete<int, std::true_type>, QtPrivate::TypeAndForceComplete<int, std::true_type>, QtPrivate::TypeAndForceComplete<int, std::true_type>, QtPrivate::TypeAndForceComplete<int, std::true_type>, QtPrivate::TypeAndForceComplete<int, std::true_type>, QtPrivate::TypeAndForceComplete<FahrzeugInfo, std::true_type>



>,
    nullptr
} };


const QMetaObject *FahrzeugInfo::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FahrzeugInfo::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FahrzeugInfo.stringdata0))
        return static_cast<void*>(this);
    return Steuereinheit::qt_metacast(_clname);
}

int FahrzeugInfo::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Steuereinheit::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    
#ifndef QT_NO_PROPERTIES
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
