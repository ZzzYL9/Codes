#ifndef SHORTCUTEDIT_H
#define SHORTCUTEDIT_H

#include <QLineEdit>

class QKeyEvent;

class ShortcutEdit : public QLineEdit
{
	Q_OBJECT

public:
	ShortcutEdit(QWidget *parent = 0);

protected:
	virtual void keyPressEvent  (QKeyEvent* event);
	virtual void keyReleaseEvent(QKeyEvent* event);

private:
	QString getModifierString(QKeyEvent* event) const;
	QString getKeyString     (QKeyEvent* event) const;
	bool    isModifier(int key) const;
	void    update(QKeyEvent* event);
	bool    acceptable() const;
};

#endif // SHORTCUTEDIT_H
