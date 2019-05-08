#ifndef CONFIG_H
#define CONFIG_H

#include <QString>
#include <QSize>
#include <background.h>
#include <QDir>

//this is the header file of config class
class Config
{
public:
    Config(QString size,
           unsigned int xCoordinat,
           unsigned int velocity,
           QDir background_dir);

    unsigned int getXCoordinate();
    unsigned int getVelocity() ;
    QDir getBackground() ;
    QDir getPlayer() ;
    QDir getBGM() ;
    QSize getSize();
    bool hasBGM();
    bool hasPlayer();

private:
    //all information read from config.txt
    unsigned int xCoordinate;
    unsigned int velocity;
    QDir background_dir;
    QDir player_dir;
    QDir bgm_dir;
    QSize size;
    bool has_BGM;
    bool has_background;
    bool has_size;
    bool has_x;
    bool has_velocity;
    bool has_player;
    void setSize(QString size);

};

#endif // CONFIG_H
