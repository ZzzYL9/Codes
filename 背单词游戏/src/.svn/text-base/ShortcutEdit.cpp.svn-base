#include "ShortcutEdit.h"
#include <QKeyEvent>
#include <QKeySequence>

ShortcutEdit::ShortcutEdit(QWidget *parent)	: QLineEdit(parent) {}

QString ShortcutEdit::getModifierString(QKeyEvent* event) const
{
	Qt::KeyboardModifiers modifiers = event->modifiers();
	QString result;
	if(modifiers.testFlag(Qt::ControlModifier))
		result += "Ctrl+";
	if(modifiers.testFlag(Qt::ShiftModifier))
		result += "Shift+";
	if(modifiers.testFlag(Qt::AltModifier))
		result += "Alt+";
	return result;
}

bool ShortcutEdit::isModifier(int key) const
{
	return key == Qt::Key_Control || 
		   key == Qt::Key_Shift   || 
		   key == Qt::Key_Alt;
}

QString ShortcutEdit::getKeyString(QKeyEvent* event) const {
	return isModifier(event->key()) ? QString() 
									: QKeySequence(event->key()).toString();
}

void ShortcutEdit::keyPressEvent(QKeyEvent* event) {
	update(event);
}

void ShortcutEdit::keyReleaseEvent(QKeyEvent* event) {
	if(!acceptable())
		update(event);
}

void ShortcutEdit::update(QKeyEvent* event) {
	setText(getModifierString(event) + getKeyString(event));
}

// if ends with letter or number
bool ShortcutEdit::acceptable() const
{
	const QChar key = text().at(text().length() - 1);
	return key.isLetterOrNumber();
}