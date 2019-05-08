#include "DictionaryModel.h"
#include "Library.h"
#include <QtSql/QSqlQuery>

DictionaryModel::DictionaryModel(QObject *parent, const QString& user) : 
	QSqlTableModel(parent), 
	userName(user),
	recite(false),
	upper(false),
	newWordColor   (Qt::red),
	unfamiliarColor(Qt::darkGray),
	familiarColor  (Qt::darkGreen) {}

void DictionaryModel::setDictionary(const QString& d)
{
	setTable(dictName = d);
	copyCredits();
	select();
}

void DictionaryModel::setShowChinese(bool show, int row)
{
	rowBeShowed = show ? row : -1;   // -1 makes this row invisible
	dataChanged(index(rowBeShowed, CHINESE), index(rowBeShowed, CHINESE));  // refresh
}

QVariant DictionaryModel::data(const QModelIndex &idx, int role) const
{
	if(role == Qt::DisplayRole)
	{
		if(idx.column() == ENGLISH)
			if(upper)
				return QSqlTableModel::data(idx, role).toString().toUpper();
		if(idx.column() == CHINESE)
			if(recite && idx.row() != rowBeShowed)  // -1 makes this row invisible
				return QString();
	}
	else if(role == Qt::TextColorRole)
	{
		if(idx.column() == ENGLISH)
		{
			int credit = getCredit(idx.row());
			if(credit < filter.threshold1)
				return newWordColor;
			if(credit >= filter.threshold2)
				return familiarColor;
			else
				return unfamiliarColor;
		}
	}
	
	return QSqlTableModel::data(idx, role);
}

bool DictionaryModel::setData(const QModelIndex& idx, const QVariant& value, int role)
{
	if(idx.column() == CREDIT && role == Qt::EditRole)  // to user table
		Library::setCredit(dictName, userName, getEnglish(idx.row()), value.toInt());
	return QSqlTableModel::setData(idx, value, role);
}

QString DictionaryModel::getFilterString(const Filter& flt) {
	return tr("%1 AND %2").arg(getUnitRangeFilter(flt)).arg(getCreditRangeFilter(flt));
}

QString DictionaryModel::getUnitRangeFilter(const Filter& flt)
{
	const int minID = flt.unitSize * (flt.currentUnit - 1) + 1;
	const int maxID = flt.unitSize * flt.currentUnit;
	return tr("(编号 BETWEEN %1 AND %2)").arg(minID).arg(maxID);
}

QString DictionaryModel::getCreditRangeFilter(const Filter& flt)
{
	QStringList clauses;
	if(flt.showNew)
		clauses << tr("(得分<%1)").arg(flt.threshold1);
	if(flt.showUnFamiliar)
		clauses << tr("(得分 BETWEEN %1 AND %2)").arg(flt.threshold1).arg(flt.threshold2-1);
	if(flt.showFamiliar)
		clauses << tr("(得分>=%1)").arg(flt.threshold2);
	return "(" + clauses.join(tr(" OR ")) + ")";
}

void DictionaryModel::updateFilter(const Filter& flt)
{
	filter = flt;
	setFilter(getFilterString(filter));
}

int DictionaryModel::getID(int row) const {
	return data(index(row, ID)).toInt();
}
QString DictionaryModel::getEnglish(int row, bool origional) const {
	return origional ? QSqlQueryModel::data(index(row, ENGLISH)).toString()
					 : data(index(row, ENGLISH)).toString();
}
QString DictionaryModel::getChinese(int row) const {
	return data(index(row, CHINESE)).toString();
}
QString DictionaryModel::getPhonetic(int row) const {
	return data(index(row, PHONETIC)).toString();
}
QString DictionaryModel::getNote(int row) const {
	return data(index(row, NOTE)).toString();
}
QString DictionaryModel::getEnglishColor(int row) const {
	return data(index(row, ENGLISH), Qt::TextColorRole).toString();
}
int DictionaryModel::getCredit(int row) const {
	return data(index(row, CREDIT)).toInt();
}

void DictionaryModel::shuffle()
{
	QSqlQuery query;
	query.exec(tr("UPDATE %1 SET 排序=random() WHERE %2").arg(dictName)
														 .arg(getUnitRangeFilter(filter)));
	sort(SORTING, Qt::AscendingOrder);
}

int DictionaryModel::getWordCount(bool newWords, bool unfamiliar, bool familiar) const
{
	Filter flt = filter;
	flt.showNew        = newWords;
	flt.showUnFamiliar = unfamiliar;
	flt.showFamiliar   = familiar;
	QSqlQuery query;
	query.exec(tr("SELECT count(编号) FROM %1 WHERE %2").arg(dictName)
														.arg(getFilterString(flt)));
	return query.next() ? query.value(0).toInt() : 0;
}

int DictionaryModel::getNewWordCount() const {
	return getWordCount(true, false, false);
}
int DictionaryModel::getUnfamiliarCount() const {
	return getWordCount(false, true, false);
}
int DictionaryModel::getFamiliarCount() const {
	return getWordCount(false, false, true);
}

// copy credits from user table to dictionary table
void DictionaryModel::copyCredits()
{
	QSqlQuery query;
	query.exec(tr("UPDATE %1 SET 得分=0").arg(dictName));
	query.exec(tr("UPDATE %1 SET 得分=(SELECT %2.credit FROM %2 WHERE %2.word=%1.单词) \
				   WHERE 单词 in (SELECT word FROM %1, %2 WHERE %2.word=%1.单词)")
				   .arg(dictName).arg(userName));
}