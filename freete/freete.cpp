#include "freete.h"
#include "ui_window.h"
#include <QFileDialog>


Freete::Freete(int argc, char** argv, QObject *parent)
    : QObject(parent),
      _window(new Window(this)),_documentbroker{new DocumentBroker}
{
    QString fileName("");
    if(argv[1] != nullptr)
        fileName = QString(argv[1]);

    _document = _documentbroker->open(fileName);
    _window->showDocument(_document);
    _window->show();
}


//bool Freete::open()
//{

//}



//void Freete::save()
//{
//    if(!_document->hasFileName()){
//        saveAs();
//        return;
//    }
//    bool success = _document->save(_documentbroker);
//    if (success) {
//        _window->saveHint("Wrote");
//    } else {
//        _window->saveHint("Could not write to file");
//    }
//}

//void Freete::saveAs()
//{
//    QString oldShownName = _document->name();
//    _document->updateFileName(_window);
//    if(oldShownName == _document->name())
//        return ;
//    _window->setWindowTitle(_document->name());
//    save();
//}

