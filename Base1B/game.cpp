#include "game.h"
#include "player.h"
#include "ui_game.h"
#include <QTimer>
#include <iostream>

using namespace std;
game::game(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::game),
    m_config(Config("tiny",200,3,QDir("long.jpg")))
{
    ui->setupUi(this);
    this->resize(1000, 600);
    //setup background
    QPixmap pixmap;
    pixmap.load(":/images/"+ m_config.getBackground().path());
    if (pixmap.isNull()) {
        //error handling-invalid background
        cout<<"Invalid background in config files!"<<endl;
        exit(EXIT_FAILURE);
    }

    pixmap = pixmap.scaled(QSize(pixmap.width(),600), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    Coordinate background_c = Coordinate(0,0,1000,600);
    m_background = Background(background_c,m_config.getVelocity(),pixmap);

    //setup timer for background moving
    QTimer *timer = new QTimer(this);
    m_timer = timer;
    connect(timer, SIGNAL(timeout()), this, SLOT(nextFrame()));
    timer->start(32);

    //initialise change to 0
    m_count = 0;

    //setup bgm if set in config.txt
    if (m_config.hasBGM()) {
        QMediaPlayer *bgm = new QMediaPlayer();
        m_bgm = bgm;

        if (m_config.getBGM().path() != "bgm.mp3" &&
                m_config.getBGM().path() != "bgm2.mp3") {
            //error handling-invalid bgm
            cout<<"Invalid bgm in config files!"<<endl;
            exit(EXIT_FAILURE);
        }

        bgm->setMedia(QUrl("qrc:/bgm/"+m_config.getBGM().path()));
        bgm->play();

    }

    //setup stickman
    //using factory designed pattern
    //FixedFactory is the factory interface
    //playerFactory is the concrete factory
    FixedFactory *playerCreator = new playerFactory();
    m_playerCreator = playerCreator;
    QPixmap pixmap_player;

    if (m_config.hasPlayer()) {

        pixmap_player.load(":/images/"+m_config.getPlayer().path());
        if (pixmap_player.isNull()) {
            //error handling-invalid player
            cout<<"Invalid Player in config files!"<<endl;
            exit(EXIT_FAILURE);
        }

    } else {
        pixmap_player.load(":/images/man1.png");
    }

    //using factory designed pattern
    //FixedItem is the product interface
    //player is the concrete product
    //every time call factory to create product
    FixedItem *player = playerCreator->createFixedItem(m_config.getSize(),Coordinate(m_config.getXCoordinate(),680,1000,600),pixmap_player);
    m_player = player;

    //set up pause button
    QPushButton *button = new QPushButton(this);
    m_button = button;
    button->setText("Pause");
    button->resize(100,50);
    button->move(900,10);
    QObject::connect(button, SIGNAL(clicked()),this,SLOT(handleButton()));
    button ->show();

    this->update();
}

void game::nextFrame()
{
    update();
}

//buttom method for pause and resume
void game::handleButton()
{
    if (m_timer->isActive())
    {
        m_timer->stop();
        m_bgm ->pause();
        m_button->move(450,250);
        m_button->setText("Resume");
    } else {
        m_button->move(900,10);
        m_timer->start();
        m_bgm->play();
        m_button->setText("Pause");
    }

}

void game::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    //let background move
    m_background.render(painter,m_count);

    //using different images to do the stickman animation
    if (m_count % 10 >= 0 && m_count % 10 <= 5)
    {
        painter.drawPixmap(m_player->getCoordinate().getQtRenderingXCoordinate(),
                          580-m_player->getPixmap().height(),
                          m_player->getPixmap());
    } else {
        painter.drawPixmap(m_player->getCoordinate().getQtRenderingXCoordinate(),
                          580-m_player->getRpixmap().height(),
                          m_player->getRpixmap());
    }

}

//memory handling
game::~game()
{
    delete m_button;
    delete ui;
    if (m_config.hasBGM())
        delete m_player;

    delete m_player;
    delete m_timer;
    delete m_playerCreator;

}
