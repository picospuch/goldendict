#ifndef PPROBE_HH
#define PPROBE_HH

#include <QString>

void pAlert(char *msg);

void pPrintf(char *format, ...);

bool recordToSqlite(QString word);

#endif // PPROBE_HH
