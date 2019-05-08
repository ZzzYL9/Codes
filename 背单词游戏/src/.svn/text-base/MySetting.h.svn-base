/*
 *	Setting Manager, derived from QSetting
 */

#ifndef MYSETTING_H
#define MYSETTING_H

#include <QSettings>
#include <QDir>

template <class T>
class MySetting : public QSettings
{
	typedef std::map<QString, T*> Manager;

public:
	QString getUserName() const { return userName; }

	static QString findUser(const QString& section, const QVariant& v);
	static T*      getInstance(const QString& userName);
	static void    destroySettingManager();

protected:
	MySetting(const QString& name);
	MySetting(const MySetting& other);
	MySetting& operator = (const MySetting& other);
	virtual ~MySetting() {}

	virtual void loadDefaults() = 0;

private:
	static Manager settingManager;
	QString userName;
};

template <class T>
MySetting<T>::MySetting(const QString& name) 
	: QSettings(name+".ini", IniFormat), userName(name) {}


//////////////////////////////////////////////////////////////////////////
// SettingManager
template <class T>
typename MySetting<T>::Manager MySetting<T>::settingManager;

template <class T>
T* MySetting<T>::getInstance(const QString& userName)
{
	Manager::iterator it = settingManager.find(userName);
	if(it != settingManager.end())
		return it->second;

	T* setting = new T(userName);
	settingManager.insert(std::make_pair(userName, setting));
	return setting;
}

template <class T>
QString MySetting<T>::findUser(const QString& section, const QVariant& v)
{
	// search all ini files
	const QStringList files = QDir().entryList(QStringList() << "*.ini", QDir::Files);
	foreach(QString file, files)
	{
		QSettings setting(file, QSettings::IniFormat);
		if(setting.value(section) == v)
			return file.left(file.length() - 4);   // - .ini
	}
	return QString();
}

template <class T>
void MySetting<T>::destroySettingManager()
{
	for(Manager::iterator it = settingManager.begin(); it != settingManager.end(); ++it)
		delete it->second;
	settingManager.clear();
}

#endif // MYSETTING_H
