#ifndef DOCUMENT_H
#define DOCUMENT_H

#include <QString>
#include <QTextEdit>
#include <window.h>
class DocumentBroker;
class QTextDocument;


class Document
{
public:
    Document(QString fileName, QString fileFormat,const QString text);

//    bool open(QString fileName);
    bool hasFileName();

    QString name();
//    void updateFileName(Window *window);
//    bool save(DocumentBroker *documentBroker);
//    bool save(QString fileName);
    void setView(QTextEdit *textEdit);

private:
    QString m_fileName;
    QString m_fileFormat;

    QTextDocument *_text;
};

#endif // DOCUMENT_H
