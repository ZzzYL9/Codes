#ifndef WINDOW_H
#define WINDOW_H

#include <QMainWindow>
class Freete;
class QTextDocument;
class Document;
namespace Ui {
class Window;
}

class Window : public QMainWindow
{
    Q_OBJECT

public:
    explicit Window(Freete *freete,QWidget *parent = nullptr);
    ~Window();

    void showDocument(Document *document);
    QString getFileName();
    void saveHint(QString message);
private:
    Ui::Window *_ui;
    Freete *_freete;
    QString m_currentFileName;
};

#endif // WINDOW_H
