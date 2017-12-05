#include "pProbe.hh"
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QVariant>
#include <cstdio>
#include <cstdarg>
#include "config.hh"

void pAlert(char *msg) {
    QMessageBox msgBox;
    msgBox.setText(msg);
    msgBox.exec();
}

void pPrintf(char *format, ...) {
    va_list va;
    va_start(va, format);
    vdprintf(2, format, va);
    va_end(va);
}

bool recordToSqlite(QString word) {
    pPrintf("%s\n", word.toUtf8().data());
    QString dbFileName = Config::getNewwordDbFileName();
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(dbFileName);
    if (!db.open()) {
        pPrintf("record fail\n");
        return false;
    }
    QString qs;
    qs = "INSERT INTO word VALUES ( \"" + word + "\", strftime(\"%s\", \"now\"));";
    pPrintf("%s\n", qs.toUtf8().data());
    QSqlQuery query = QSqlQuery(qs, db);

    return true;
}
