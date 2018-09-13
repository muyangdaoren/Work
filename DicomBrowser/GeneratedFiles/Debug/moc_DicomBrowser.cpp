/****************************************************************************
** Meta object code from reading C++ file 'DicomBrowser.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../DicomBrowser.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DicomBrowser.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_DicomBrowser_t {
    QByteArrayData data[8];
    char stringdata0[134];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DicomBrowser_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DicomBrowser_t qt_meta_stringdata_DicomBrowser = {
    {
QT_MOC_LITERAL(0, 0, 12), // "DicomBrowser"
QT_MOC_LITERAL(1, 13, 18), // "loadBtnClickedSlot"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 13), // "preBtnClicked"
QT_MOC_LITERAL(4, 47, 14), // "nextBtnClicked"
QT_MOC_LITERAL(5, 62, 23), // "windowCenterChangedSlot"
QT_MOC_LITERAL(6, 86, 22), // "windowWidthChangedSlot"
QT_MOC_LITERAL(7, 109, 24) // "switchTo3DBtnClickedSlot"

    },
    "DicomBrowser\0loadBtnClickedSlot\0\0"
    "preBtnClicked\0nextBtnClicked\0"
    "windowCenterChangedSlot\0windowWidthChangedSlot\0"
    "switchTo3DBtnClickedSlot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DicomBrowser[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x0a /* Public */,
       3,    0,   45,    2, 0x0a /* Public */,
       4,    0,   46,    2, 0x0a /* Public */,
       5,    1,   47,    2, 0x0a /* Public */,
       6,    1,   50,    2, 0x0a /* Public */,
       7,    0,   53,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,

       0        // eod
};

void DicomBrowser::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DicomBrowser *_t = static_cast<DicomBrowser *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->loadBtnClickedSlot(); break;
        case 1: _t->preBtnClicked(); break;
        case 2: _t->nextBtnClicked(); break;
        case 3: _t->windowCenterChangedSlot((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->windowWidthChangedSlot((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->switchTo3DBtnClickedSlot(); break;
        default: ;
        }
    }
}

const QMetaObject DicomBrowser::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_DicomBrowser.data,
      qt_meta_data_DicomBrowser,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *DicomBrowser::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DicomBrowser::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_DicomBrowser.stringdata0))
        return static_cast<void*>(const_cast< DicomBrowser*>(this));
    return QWidget::qt_metacast(_clname);
}

int DicomBrowser::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
