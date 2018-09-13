/****************************************************************************
** Meta object code from reading C++ file 'DicomToJPGClass.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../DicomToJPGClass.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DicomToJPGClass.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_DicomToJPGClass_t {
    QByteArrayData data[4];
    char stringdata0[49];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DicomToJPGClass_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DicomToJPGClass_t qt_meta_stringdata_DicomToJPGClass = {
    {
QT_MOC_LITERAL(0, 0, 15), // "DicomToJPGClass"
QT_MOC_LITERAL(1, 16, 12), // "workFinished"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 18) // "convertDcm2JpgSlot"

    },
    "DicomToJPGClass\0workFinished\0\0"
    "convertDcm2JpgSlot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DicomToJPGClass[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   24,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   25,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Bool,

       0        // eod
};

void DicomToJPGClass::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DicomToJPGClass *_t = static_cast<DicomToJPGClass *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->workFinished(); break;
        case 1: { bool _r = _t->convertDcm2JpgSlot();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (DicomToJPGClass::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DicomToJPGClass::workFinished)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject DicomToJPGClass::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_DicomToJPGClass.data,
      qt_meta_data_DicomToJPGClass,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *DicomToJPGClass::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DicomToJPGClass::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_DicomToJPGClass.stringdata0))
        return static_cast<void*>(const_cast< DicomToJPGClass*>(this));
    return QObject::qt_metacast(_clname);
}

int DicomToJPGClass::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void DicomToJPGClass::workFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
