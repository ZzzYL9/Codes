#pragma once

#include <QDialog>
#include <Phonon/phonon>
#include <QPixmap>
#include "ui_MiniPlayer.h"

class QSqlTableModel;
class DictionaryModel;

class MiniPlayer : public QDialog
{
	Q_OBJECT

public:
	MiniPlayer(DictionaryModel* m, QWidget *parent = 0, Qt::WFlags flags = 0);

protected:
	virtual void closeEvent(QCloseEvent*);
	virtual void wheelEvent(QWheelEvent* event);

private slots:
	void slotPlay();
	void slotStop();
	void slotPrev();
	void slotNext();
	void slotSetCurrentRow(const QModelIndex& idx);
	void slotOnFinish();
	void slotSetVolume(int volume);

private:
	void initView();
	void initConnection();
	void setCurrentRow(int row);
	void speak(const QString& word);

private:
	Ui::MiniPlayerClass ui;
	DictionaryModel*    model;
	Phonon::MediaObject mediaObject;
	Phonon::AudioOutput audioOutput;
	Phonon::Path        outputPath;
	QPixmap volumePixmap;
	QPixmap mutedPixmap;
	int     currentRow;
	bool    playing;
	QString mp3Dir;
};
