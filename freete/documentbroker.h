#ifndef DOCUMENTBROKER_H
#define DOCUMENTBROKER_H
#include <QFile>
#include <QTextDocumentWriter>
#include <QByteArray>
#include "document.h"

class DocumentBroker
{
public:
    DocumentBroker();
    Document *open(QString fileName);
    QByteArray readFile(QString fileName);
    bool writeFile(QTextDocument *document, QString fileName,QString fileFormat);
private:
    QFile file;
    QTextDocumentWriter writer;
    QList<Document *> _documents;
};

#endif // DOCUMENTBROKER_H
