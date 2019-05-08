#ifndef GAME_H
#define GAME_H
#include "config.h"
#include "player.h"
#include "playerfactory.h"
#include <QDialog>
#include <QMediaPlayer>
#include <QPushButton>

//header file of the game
namespace Ui
{
class game;
}

class game : public QDialog
{
    Q_OBJECT

public:
    explicit game(QWidget *parent = nullptr);
    ~game();

public slots:
    void nextFrame();
    void handleButton();

protected:
    void paintEvent(QPaintEvent *event);

private:
    Ui::game *ui;
    //store all the object information in the frame
    Config m_config;
    Background m_background;
    FixedItem *m_player;
    QTimer *m_timer;
    QMediaPlayer *m_bgm;
    QPushButton *m_button;
    FixedFactory *m_playerCreator;
    //helper to do the animation of stickman
    int m_count;
};


#endif // GAME_H
