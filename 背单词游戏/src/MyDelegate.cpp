#include "MyDelegate.h"
#include <QPainter>
#include "DictionaryModel.h"

MyDelegate::MyDelegate(QObject *parent)
	: QItemDelegate(parent), star(QPixmap(":/Entrance/Images/star.png"))
{}

void MyDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option,
                       const QModelIndex &index) const
{
	if(index.column() == DictionaryModel::CREDIT)
	{
        const QAbstractItemModel* model = index.model();
        QPalette::ColorGroup cg = option.state & QStyle::State_Enabled
                                ? QPalette::Normal : QPalette::Disabled;
        if(option.state & QStyle::State_Selected)
            painter->fillRect(option.rect, option.palette.color(cg, QPalette::Highlight));

        int rating = model->data(index).toInt();
        int x = option.rect.x();
        int y = option.rect.y() + (option.rect.height() / 2) - (star.height() / 2);
        for(int i = 0; i < rating; ++i) 
		{
            painter->drawPixmap(x, y, star);
            x += star.width();
        }
    }
	else
		QItemDelegate::paint(painter, option, index);
}