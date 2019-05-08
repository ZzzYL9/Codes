#include "window.h"
#include "ui_window.h"

#include <QTextEdit>
#include <QFileDialog>
#include <QFileInfo>
#include "freete.h"

Window::Window(Freete *freete, QWidget *parent) :
    QMainWindow(parent),
    _ui(new Ui::Window),_freete{freete}
{
    _ui->setupUi(this);
//    QObject::connect(_ui->actionSave, &QAction::triggered, _freete, &Freete::save);

}

Window::~Window()
{
    delete _ui;
}

void Window::showDocument(Document *document)
{
    QString shownName =  document->name();
    setWindowTitle(tr("%1[*] - %2").arg(shownName)
                   .arg(tr("Freete")));
    document->setView(_ui->centralWidget);
//    _ui->centralWidget->setDocument(document->text());
}


QString Window::getFileName()
{

    m_currentFileName =  QFileDialog::getSaveFileName(this,
                                                      tr("Save TextFile"), ".",
                                                      tr("Text files (*.txt);;Any files(*)"));
    return m_currentFileName;
}



void Window::saveHint(QString message)
{
    statusBar()->showMessage(message + " \""+ m_currentFileName +"\"");
}

