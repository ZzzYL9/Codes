#ifndef SETTINGDLG_H
#define SETTINGDLG_H

#include <QDialog>
#include <QString>
#include <QFont>
#include <QColor>
#include "ui_SettingDlg.h"

class UserSetting;

class SettingDlg : public QDialog
{
	Q_OBJECT

public:
	SettingDlg(const QString& user, QWidget *parent = 0);

	void importSetting(const UserSetting& setting);
	UserSetting& exportSetting() const;

public slots:
	virtual void accept();

private slots:
	void slotSetTableFont();
	void slotSetWordFont();
	void slotSetChineseFont();
	void slotSetPhoneticFont();
	void slotSetNoteFont();
	void slotSetGUIFont();
	void slotSetNewColor();
	void slotSetUnfamiliarColor();
	void slotSetFamiliarColor();
	void slotSetPhoneticColor();
	void slotSetWavDir();
	void slotSetMp3Dir();
	void slotSetDBFileName();
	void slotSetAutoHide(bool hide);
	void slotSetAutoBackup(bool hide);

private:
	QString getRightShortcut()       const;
	QString getWrongShortcut()       const;
	QString getChineseShortcut()     const;
	QString getSetFamiliarShortcut() const;
	void setRightShortcut      (const QString& shortcut);
	void setWrongShortcut      (const QString& shortcut);
	void setChineseShortcut    (const QString& shortcut);
	void setSetFamiliarShortcut(const QString& shortcut);

	QFont getTableFont()    const { return tableFont;    }
	QFont getWordFont()     const { return wordFont;     }
	QFont getPhoneticFont() const { return phoneticFont; }
	QFont getChineseFont()  const { return chineseFont;  }
	QFont getNoteFont()     const { return noteFont;     }
	QFont getGUIFont()      const { return guiFont;      }
	void setTableFont   (const QFont& font) { tableFont    = font; }
	void setWordFont    (const QFont& font) { wordFont     = font; }
	void setPhoneticFont(const QFont& font) { phoneticFont = font; }
	void setChineseFont (const QFont& font) { chineseFont  = font; }
	void setNoteFont    (const QFont& font) { noteFont     = font; }
	void setGUIFont     (const QFont& font) { guiFont      = font; }

	QColor getNewWordColor()    const;
	QColor getUnfamiliarColor() const;
	QColor getFamiliarColor()   const;
	QColor getPhoneticColor()   const;
	void setNewWordColor   (const QColor& color);
	void setUnfamiliarColor(const QColor& color);
	void setFamiliarColor  (const QColor& color);
	void setPhoneticColor  (const QColor& color);

	QString getDBFileName()   const;
	QString getWavDir()       const;
	QString getMp3Dir()       const;
	QString getFilteredChar() const;
	bool    getAutoBackup()   const;
	int     getBackupDays()   const;
	void setDBFileName  (const QString& name);
	void setWavDir      (const QString& dir);
	void setMp3Dir      (const QString& dir);
	void setFilteredChar(const QString& chars);
	void setAutoBackup  (bool backup);
	void setBackupDays  (int days);

	bool getAutoHide()  const;
	int  getHideDelay() const;
	int  getShowDelay() const;
	void setAutoHide (bool hide);
	void setHideDelay(int delay);
	void setShowDelay(int delay);

private:
	Ui::SettingDlgClass ui;
	QFont   tableFont;
	QFont   wordFont;
	QFont   phoneticFont;
	QFont   chineseFont;
	QFont   noteFont;
	QFont   guiFont;
	QString userName;
};

#endif // SETTINGDLG_H
