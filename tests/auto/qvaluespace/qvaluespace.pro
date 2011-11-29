include(../auto.pri)

QT += publishsubscribe

!contains(config_test_gconf, yes) {
    DEFINES += QT_NO_GCONFLAYER
}

!contains(config_test_contextkit, yes) {
    DEFINES += QT_NO_CONTEXTKIT
}

!contains(QT_CONFIG, jsondb) {
    DEFINES += QT_NO_JSONDBLAYER
} else {
    QT += jsondb jsondb-private
}

SOURCES += tst_qvaluespace.cpp
