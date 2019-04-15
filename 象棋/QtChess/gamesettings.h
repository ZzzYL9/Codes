#ifndef GAMESETTINGS_H
#define GAMESETTINGS_H
#include <QString>

class GameSettings
{
public:
    GameSettings();
    ~GameSettings();
    void loadSettings();
    void saveSettings();

    int getGameType() const;
    void setGameType(int value);

    int getCompetitorSide() const;
    void setCompetitorSide(int value);

    int getAhead() const;
    void setAhead(int value);

    int getStepTime() const;
    void setStepTime(int value);

    int getServerOrClient() const;
    void setServerOrClient(int value);

    QString getIpAddr() const;
    void setIpAddr(const QString &value);

    int getPort() const;
    void setPort(int value);

    void createSettingsFile(const QString &file);

private:
    int gameType;
    int competitorSide;
    int ahead;
    int stepTime;
    int serverOrClient;
    QString ipAddr;
    int port;
};

extern GameSettings g_gameSettings;

#endif // GAMESETTINGS_H
