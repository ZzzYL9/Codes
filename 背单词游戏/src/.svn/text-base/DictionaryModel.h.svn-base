#ifndef DICTIONARYMODEL_H
#define DICTIONARYMODEL_H

#include <QtSql/QSqlTableModel>
#include <QColor>
#include "UserSetting.h"

typedef DictSetting Filter;

class DictionaryModel : public QSqlTableModel
{
	Q_OBJECT

public:
	DictionaryModel(QObject *parent, const QString& user);

	void setUser(const QString& user) { userName = user; }
	void setDictionary(const QString& d);

	QColor getNewWordColor  () const { return newWordColor;    }
	QColor getFamiliarColor () const { return familiarColor;   }
	QColor getUnfamilarColor() const { return unfamiliarColor; }
	void   setNewWordColor   (const QColor& color) { newWordColor    = color; }
	void   setFamiliarColor  (const QColor& color) { familiarColor   = color; }
	void   setUnfamiliarColor(const QColor& color) { unfamiliarColor = color; }

	bool isReciting() const { return recite; }
	void setRecite(bool re) { recite = re; rowBeShowed = -1;  }
	void setUpper (bool u)  { upper = u; select(); }
	void setShowChinese(bool show, int row = -1);
	void updateFilter(const Filter& flt);
	int getNewWordCount()    const;
	int getUnfamiliarCount() const;
	int getFamiliarCount()   const;
	
	int     getID          (int row) const;  // for convenience
	int     getCredit      (int row) const;
	QString getChinese     (int row) const;
	QString getPhonetic    (int row) const;
	QString getNote        (int row) const;
	QString getEnglishColor(int row) const;
	QString getEnglish     (int row, bool origional = true) const;  // upper if origional is false

	void shuffle();

	virtual QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const;
	virtual bool  setData(const QModelIndex& index, const QVariant& value, int role = Qt::EditRole);

private:
	static QString getFilterString     (const Filter& flt);
	static QString getUnitRangeFilter  (const Filter& flt);
	static QString getCreditRangeFilter(const Filter& flt);
	int getWordCount(bool newWords, bool unfamiliar, bool familiar) const;
	void copyCredits();    // copy credits from user table to dictionary table

public:
	enum {ID, ENGLISH, CHINESE, CREDIT, PHONETIC, NOTE, SORTING};

private:
	int     rowBeShowed;
	Filter  filter;
	QColor  newWordColor;
	QColor  unfamiliarColor;
	QColor  familiarColor;
	QString userName;
	QString dictName;
	bool    recite;
	bool    upper;
};

#endif // DICTIONARYMODEL_H
