#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <stack>
#include "UserSetting.h"
#include "ui_MainWindow.h"

class DictionaryModel;
class QStandardItemModel;
class QCloseEvent;
class MiniPlayer;

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(const QString& user, QWidget *parent = 0);
	virtual void closeEvent(QCloseEvent*);

private slots:
	void slotRight();
	void slotWrong();
	void slotShuffle();
	void slotPrevUnit();
	void slotNextUnit();
	void slotPlay(bool);
	void slotBack();
	void slotForceShowChinese();
	void slotNewDict();
	void slotDelDict();
	void slotDelWord();
	void slotAbout();         
	void slotSetting();
	void slotChangeUser();
	void slotSetCurrentDict(const QString& dict);
	void slotResizeUnit(int size);
	void slotUpdateFilter();
	void slotSetMaxThreshold1(int value);
	void slotSetCurrentRow(const QModelIndex&);
	void slotTimeout();
	void slotGotoCurrentID();
	void slotRecite(bool recite);
	void slotJump(int id, bool back = true);
	void slotSectionPressed();
	void slotUpdateTitle();
	void slotExport();
	void slotFullScreen();
	void slotExitFullScreen();
	void slotHideControlBar(bool hide);
	void slotBackup();
	void slotUpper(bool upper);
	void slotSetFamiliar();
	void slotMiniPlayer();

private:
	void initModel();
	void initView();
	void updateView();
	void initConnection();

	void loadSetting();
	void saveSettings();
	void loadSizes();
	void saveSizes();
	void loadButtonStatus();
	void saveButtonStatus();
	void loadDictSetting();
	void saveDictSetting(const QString& user);
	void importSetting(const UserSetting& setting);
	DictSetting exportDictSetting() const;

	void updateDictList();
	void updateProgress();
	void updateGroups (bool show);
	void updateCognate(bool show);

	void selectRow(int row);
	void showDetail(bool show);
	void speak();
	void gotoNext(); 
	void gotoPrev();
	void submitAll();
	void delOldBackups();
	void backup(const QString& fileName = QString());
	void enableJumpBack(bool enable);
	void jumpInPage(int id);
	void updateCurrentDict();

	QString getCurrentDictName() const;
	QString getCurrentEnglish()  const;
	int getUnit()       const;
	int getUnitSize()   const;
	int getThreshold1() const;
	int getThreshold2() const;
	int getPlayDelay()  const;
	void setUnit    (int unit);
	void setUnitSize(int size);
	void setCredit  (int credit);

public:
	static QString userName;

private:
	Ui::MainWindowClass ui;
	DictionaryModel*    model;
	QStandardItemModel* progressModel;
	QString lastDict;
	QString lastUser;
	int     currentRow;
	int     currentID;
	QTimer  timer;
	QString wavDir;
	QString mp3Dir;
	UserSetting* setting;
	std::stack<int> jumpHistroy;
	MiniPlayer* miniPlayer;
};

#endif // MAINWINDOW_H
