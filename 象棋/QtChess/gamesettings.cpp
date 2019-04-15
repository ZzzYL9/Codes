#include "gamesettings.h"
#include "commdef.h"
#include <QSettings>
#include <QFile>

GameSettings g_gameSettings;

GameSettings::GameSettings()
{

}

GameSettings::~GameSettings()
{

}

void GameSettings::loadSettings()
{
    QSettings settings(SETTINGS_FILE, QSettings::IniFormat);
    settings.beginGroup("Game");
    gameType = settings.value("GameType", 2).toInt();
    competitorSide = settings.value("CompetitorSide",2).toInt();
    ahead = settings.value("Ahead",1).toInt();
    stepTime = settings.value("StepTime", 30).toInt();
    serverOrClient = settings.value("ServerOrClient", 1).toInt();
    port = settings.value("Port", 8000).toInt();
    ipAddr = settings.value("IpAddr", "localhost").toString();
    settings.endGroup();
}

void GameSettings::saveSettings()
{
    createSettingsFile(QString(SETTINGS_FILE));

    QSettings settings(SETTINGS_FILE, QSettings::IniFormat);
    settings.beginGroup("Game");
    settings.setValue("GameType", gameType);
    settings.setValue("CompetitorSide", competitorSide);
    settings.setValue("Ahead", ahead);
    settings.setValue("StepTime", stepTime);
    settings.setValue("ServerOrClient", serverOrClient);
    settings.setValue("Port", port);
    settings.setValue("IpAddr", ipAddr);
    settings.endGroup();
}
int GameSettings::getGameType() const
{
    return gameType;
}

void GameSettings::setGameType(int value)
{
    gameType = value;
}
int GameSettings::getCompetitorSide() const
{
    return competitorSide;
}

void GameSettings::setCompetitorSide(int value)
{
    competitorSide = value;
}
int GameSettings::getAhead() const
{
    return ahead;
}

void GameSettings::setAhead(int value)
{
    ahead = value;
}
int GameSettings::getStepTime() const
{
    return stepTime;
}

void GameSettings::setStepTime(int value)
{
    stepTime = value;
}
int GameSettings::getServerOrClient() const
{
    return serverOrClient;
}

void GameSettings::setServerOrClient(int value)
{
    serverOrClient = value;
}
QString GameSettings::getIpAddr() const
{
    return ipAddr;
}

void GameSettings::setIpAddr(const QString &value)
{
    ipAddr = value;
}
int GameSettings::getPort() const
{
    return port;
}

void GameSettings::setPort(int value)
{
    port = value;
}

void GameSettings::createSettingsFile(const QString &filePath)
{
    if (!QFile::exists(filePath))
    {
        QFile file(filePath);
        file.open(QIODevice::ReadWrite|QIODevice::Text|QIODevice::Truncate);
        file.close();
    }
}


