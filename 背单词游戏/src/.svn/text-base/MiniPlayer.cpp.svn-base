#include "MiniPlayer.h"
#include "DictionaryModel.h"
#include "UserSetting.h"
#include <QStyle>
#include <QTimer>
#include <QWheelEvent>
#include <QDesktopWidget>

MiniPlayer::MiniPlayer(DictionaryModel* m, QWidget *parent, Qt::WFlags)
	: QDialog(parent, Qt::Dialog | Qt::WindowStaysOnTopHint | Qt::WindowMinimizeButtonHint), 
	  model(m)
{
	ui.setupUi(this);
	initView();
	initConnection();
	slotStop();

	mp3Dir = UserSetting::getInstance("Global")->value("Mp3Dir").toString();
	outputPath = Phonon::createPath(&mediaObject, &audioOutput);
}

void MiniPlayer::closeEvent(QCloseEvent*) {
	slotStop();
	emit accepted();
}

void MiniPlayer::initView()
{
	ui.buttonPlay->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
	ui.buttonStop->setIcon(style()->standardIcon(QStyle::SP_MediaStop));
	ui.buttonPrev->setIcon(style()->standardIcon(QStyle::SP_MediaSeekBackward));
	ui.buttonNext->setIcon(style()->standardIcon(QStyle::SP_MediaSeekForward));
	volumePixmap = style()->standardPixmap(QStyle::SP_MediaVolume);
	mutedPixmap  = style()->standardPixmap(QStyle::SP_MediaVolumeMuted);
	ui.labelVolume->setPixmap(volumePixmap);
	ui.listView->setModel(model);
	ui.listView->setModelColumn(DictionaryModel::ENGLISH);
	ui.listView->hide();
	ui.wordDisplayer->setPhoneticFont(QFont("TOPhonetic", 12));
	ui.wordDisplayer->setEnglishFont (QFont("Arial", 24, QFont::Bold));
}

void MiniPlayer::initConnection()
{
	connect(ui.buttonPlay, SIGNAL(clicked()),  this, SLOT(slotPlay()));
	connect(ui.buttonStop, SIGNAL(clicked()),  this, SLOT(slotStop()));
	connect(ui.buttonPrev, SIGNAL(clicked()),  this, SLOT(slotPrev()));
	connect(ui.buttonNext, SIGNAL(clicked()),  this, SLOT(slotNext()));
	connect(ui.sliderVolume, SIGNAL(valueChanged(int)), this, SLOT(slotSetVolume(int)));
	connect(&mediaObject,    SIGNAL(finished()),        this, SLOT(slotOnFinish()));
	connect(ui.listView->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)),
			this,						   SLOT  (slotSetCurrentRow(QModelIndex)));
}

void MiniPlayer::slotSetCurrentRow(const QModelIndex& idx)
{
	if(idx.isValid())
		setCurrentRow(idx.row());
}

void MiniPlayer::slotPlay()
{
	playing = !playing;
	ui.buttonStop->setEnabled(playing);
	ui.buttonPlay->setIcon(style()->standardIcon(
		playing ? QStyle::SP_MediaPause : QStyle::SP_MediaPlay));

	speak(model->getEnglish(currentRow, false));
}

void MiniPlayer::slotStop()
{
	playing = false;
	setCurrentRow(0);
	ui.buttonStop->setEnabled(false);
	ui.buttonPlay->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
}

void MiniPlayer::slotPrev() {
	setCurrentRow(currentRow - 1);
}

void MiniPlayer::slotNext() 
{
	if(currentRow == model->rowCount()-1 && !ui.buttonRepeat->isChecked())
		slotStop();
	else
		setCurrentRow((currentRow + 1) % model->rowCount());
}

void MiniPlayer::setCurrentRow(int row)
{
	currentRow = row;
	ui.listView->selectionModel()->select(model->index(row, DictionaryModel::ENGLISH),
										  QItemSelectionModel::SelectCurrent);
	ui.listView->scrollTo(model->index(row, DictionaryModel::ENGLISH));
	ui.listView->setFocus();
	ui.wordDisplayer->setEnglishColor(model->getEnglishColor(currentRow));
	ui.wordDisplayer->setHtml("<center>" + 
									model->getEnglish(currentRow, false) + 
									"<p>" + model->getPhonetic(currentRow) + "</p>" + 
							  "</center>");
	speak(model->getEnglish(currentRow, false));
}

void MiniPlayer::speak(const QString& word)
{
	if(!playing)
		return;

	QString fileName = mp3Dir + "/" + QString(word.at(0)) + "/" + word + ".mp3";
	if(QFile::exists(fileName))
	{
		mediaObject.setCurrentSource(Phonon::MediaSource(fileName));
		mediaObject.play();
	}
	else
		slotOnFinish();
}

void MiniPlayer::slotOnFinish() {
	QTimer::singleShot(1000, this, SLOT(slotNext()));
}

void MiniPlayer::wheelEvent(QWheelEvent* event) {
	ui.sliderVolume->setValue(ui.sliderVolume->value() + event->delta()/10.0);
}

void MiniPlayer::slotSetVolume(int volume)
{
	audioOutput.setVolume(volume / 100.0);
	ui.labelVolume->setPixmap(volume == 0 ? mutedPixmap : volumePixmap);
}