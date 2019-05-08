#include "config.h"
#include <QFile>
#include <QTextStream>
#include <iostream>
#include <cstdlib>
using namespace std;

//Config class
//read the config file and store all the information

Config::Config(QString a_size,
               unsigned int a_xCoordinate,
               unsigned int a_velocity,
               QDir a_background)
{
    setSize(a_size);
    xCoordinate = a_xCoordinate;
    velocity = a_velocity;
    background_dir = a_background;
    player_dir = QDir("man1.png");

    has_BGM = false;
    has_background = false;
    has_size = false;
    has_x = false;
    has_velocity = false;
    has_player = false;

    //readConfigFile
    QFile file(":/config.txt");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {

        QTextStream in(&file);

        while (!in.atEnd())
        {
            QString line = in.readLine();
            QStringList result = line.split(" = ");

            if (result[0] == "size") {
                has_size = true;
                setSize(result[1]);
            } else if (result[0] == "xCoordinate") {
                has_x = true;
                int x = result[1].toInt();

                //error handles: program ends
                if (x < 0 || x > 600) {
                    cout<<"Invalid XCoordinate in Config.txt!"<<endl;
                    exit(EXIT_FAILURE);
                }

                xCoordinate = x;

            } else if (result[0] == "velocity") {
                has_velocity = true;
                int v = result[1].toInt();

                //error handles: program ends
                if (v < 0 || v > 600) {
                    cout<<"Invalid velocity in Config.txt!"<<endl;
                    exit(EXIT_FAILURE);
                }

                velocity = v;

            } else if (result[0] == "background") {
                has_background = true;
                background_dir = QDir(result[1]);
            } else if (result[0] == "player") {
                has_player = true;
                player_dir = QDir(result[1]);
            } else if (result[0] == "bgm") {
                //bgm is optional
                has_BGM = true;
                bgm_dir = QDir(result[1]);
            } else {
                //error handles: program ends
                cout<<"Invalid Input in Config.txt!"<<endl;
                exit(EXIT_FAILURE);
            }
        }

        file.close();

        if (!has_size||!has_x||!has_velocity||!has_background)
        {
            cout<<"Lack of Information in Config!"<<endl;
            exit(EXIT_FAILURE);
        }


    }
}

//separate method to setSize of stickman
void Config::setSize(QString ssize)
{

    if (ssize == "tiny") {
        size = QSize(100,100);
    } else if (ssize == "normal") {
        size = QSize(200,200);
    } else if (ssize == "large") {
        size = QSize(300,300);
    } else if (ssize == "giant") {
        size = QSize(400,400);
    } else {
        //error handling-invalid size
        cout<<"Invalid Size in config files!"<<endl;
        exit(EXIT_FAILURE);
    }
}

//usual get methods
unsigned int Config::getXCoordinate()
{
    return xCoordinate;
}

unsigned int Config::getVelocity()
{
    return velocity;
}

QSize Config::getSize()
{
    return size;
}

QDir Config::getBackground()
{
    return background_dir;
}

QDir Config::getPlayer()
{
    return player_dir;
}

QDir Config::getBGM()
{
    return bgm_dir;
}

bool Config::hasBGM()
{
    return has_BGM;
}

bool Config::hasPlayer()
{
    return has_player;
}
