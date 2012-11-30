/****************************************************************************
** Meta object code from reading C++ file 'JsonAccess.hpp'
**
** Created: Fri Nov 30 12:09:10 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/JsonAccess.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'JsonAccess.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_JsonAccess[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      25,   12,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
      48,   11,   11,   11, 0x0a,
      73,   62,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_JsonAccess[] = {
    "JsonAccess\0\0info,success\0"
    "complete(QString,bool)\0onDataReply()\0"
    "reply,ator\0"
    "provideAuthentication(QNetworkReply*,QAuthenticator*)\0"
};

void JsonAccess::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        JsonAccess *_t = static_cast<JsonAccess *>(_o);
        switch (_id) {
        case 0: _t->complete((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 1: _t->onDataReply(); break;
        case 2: _t->provideAuthentication((*reinterpret_cast< QNetworkReply*(*)>(_a[1])),(*reinterpret_cast< QAuthenticator*(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData JsonAccess::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject JsonAccess::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_JsonAccess,
      qt_meta_data_JsonAccess, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &JsonAccess::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *JsonAccess::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *JsonAccess::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_JsonAccess))
        return static_cast<void*>(const_cast< JsonAccess*>(this));
    return QObject::qt_metacast(_clname);
}

int JsonAccess::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void JsonAccess::complete(QString _t1, bool _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
