#include "document.h"
#include <QTextDocument>
#include <QFileInfo>

#include "freete.h"


Document::Document(QString fileName, QString fileFormat, const QString text):
    m_fileName{fileName}, m_fileFormat{fileFormat}, _text{new QTextDocument(text)}
{

}

bool Document::hasFileName()
{
    if(m_fileName != "")
        return true;
    else
        return false;
}

QString Document::name()
{
    if(m_fileName == "")
        return QString("Untitled");
    return QFileInfo(m_fileName).fileName();

}

//void Document::updateFileName(Window *window)
//{
//    m_fileName = window->getFileName();
//}

//bool Document::save(DocumentBroker *documentBroker)
//{
//    auto success = documentBroker->writeFile(_text, m_fileName, m_fileFormat);
//    if (success) {
//        _text->setModified(false);
//    }

//    return success;
//}

//QTextDocument *Document::content() const
//{
//    return _text;
//}

//void Document::setContent(QTextDocument *content)
//{
//    _text = content;
//}

//bool Document::open(QString fileName)
//{

//}

void Document::setView(QTextEdit *textEdit)
{
    _text->setParent(textEdit);
    textEdit->setDocument(_text);
}




//bool Document::save(Freete *freete)
//{
//    if(m_fileName == "")
//        return freete->saveAs();
//    else
//        return _dataAccess.writeFile(_text, m_fileName, m_fileFormat);
//}

//bool Document::save(QString fileName)
//{
//    m_fileName = fileName;
//    return _dataAccess.writeFile(_text, m_fileName, m_fileFormat);
//}


