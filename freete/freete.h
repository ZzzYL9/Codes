#ifndef FREETE_H
#define FREETE_H

#include <QObject>
#include "window.h"
#include "documentbroker.h"

class Freete : public QObject
{
    Q_OBJECT
public:
    explicit Freete( int argc, char** argv, QObject *parent = nullptr);
//    bool open();
//    void save();
//    void saveAs();

signals:

public slots:
private:
    Window *_window;
    Document *_document;
    DocumentBroker *_documentbroker;
};

#endif // FREETE_H
