#ifndef USERSETTING_H
#define USERSETTING_H

#include <QFont>
#include <QColor>
#include <QKeySequence>
#include "MySetting.h"

struct DictSetting
{
	int     unitSize;
	int     currentUnit;
	int     threshold1;
	int     threshold2;
	bool    showNew;
	bool    showUnFamiliar;
	bool    showFamiliar;
};

class UserSetting : public MySetting<UserSetting>
{
public:
	UserSetting(const QString& name);
	QFont        getFont    (const QString& section) const;
	QColor       getColor   (const QString& section) const;
	QKeySequence getShortcut(const QString& section) const;
	int          getSize    (const QString& section) const;
	void         setFont    (const QString& section, const QFont& font);
	void         setColor   (const QString& section, const QColor& color);
	void         setShortcut(const QString& section, const QKeySequence& keySequence);
	void         setSize    (const QString& section, int size);
	bool        containsDictSetting(const QString& dictName) const;
	DictSetting getDictSetting     (const QString& dictName);
	void        setDictSetting     (const QString& dictName, const DictSetting& setting);

private:
	void loadDefaults();
};

#endif // USERSETTING_H
