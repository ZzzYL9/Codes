#include "Control.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    /* 启动画面 */
    QPixmap welcome(":/images/start_img.jpg");
    QSplashScreen splash(welcome);
    splash.resize(welcome.size());
    splash.show();
    app.processEvents();
//    sleep(1000);
    QTime t;
    t.start();
    while(t.elapsed()<1000)
        QCoreApplication::processEvents();

    Control *ctrl = new Control;

    /* 显示界面 */
    QGraphicsView *view = new QGraphicsView;
//    view->setSceneRect(0,0,800,600);
//    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
//    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    splash.finish(view);
    view->setWindowTitle(QObject::tr("FIGHT OF PLANES"));
    view->setScene(ctrl);
//    view->setBackgroundBrush(QBrush(QPixmap(":/images/bg.jpg")));
    view->setStyleSheet("background-image:url(:/images/bg.jpg);");

    view->show();

    return app.exec();
}
