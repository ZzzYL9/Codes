#include "documentbroker.h"

#include <QTextCodec>
#include <QTextDocument>

DocumentBroker::DocumentBroker()
{

}

Document *DocumentBroker::open(QString fileName)
{
    if(fileName != ""){
        if (!QFile::exists(fileName))
            return nullptr;
        QFile file(fileName);
        if (!file.open(QFile::ReadOnly))
            return nullptr;

        QByteArray data = file.readAll();
        QTextCodec *codec = Qt::codecForHtml(data);
        QString text = codec->toUnicode(data);
        if (Qt::mightBeRichText(text)) {
            return new Document(fileName, "html", text);
        } else {
            text = QString::fromLocal8Bit(data);
            return new Document(fileName, "txt", text);
        }
    }else {
        return  new Document("", "txt", "");
    }
}



//bool DocumentBroker::writeFile(QTextDocument *document, QString fileName,QString fileFormat)
//{
//    writer.setFileName(fileName);
//    writer.setFormat(fileFormat.toUtf8());
//    bool success = writer.write(document);

//    return success;
//}
