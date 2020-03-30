#pragma once

#include <QWidget>
#include "3rdparty/QMW/Includes/qtmaterialautocomplete.h"
QT_BEGIN_NAMESPACE
class QAbstractItemModel;
class QCheckBox;
class QComboBox;
class QGroupBox;
class QLabel;
class QLineEdit;
class QSortFilterProxyModel;
class QTreeView;
QT_END_NAMESPACE
class PlayList : public QWidget
{
	Q_OBJECT

public:
	explicit PlayList(QWidget *parent = nullptr);
	~PlayList();
	void setSourceModel(QAbstractItemModel* model)
	{
		PlayListModel->setSourceModel(model);
	}
	QSortFilterProxyModel* PlayListModel;
	QTreeView* PlayListView;
	QtMaterialAutoComplete* searchLineEdit;

	void filterRegExpChanged()
	{
		QRegExp::PatternSyntax syntax =
			QRegExp::PatternSyntax::RegExp;
		Qt::CaseSensitivity caseSensitivity =
			Qt::CaseInsensitive;
		QRegExp regExp(searchLineEdit->text(), caseSensitivity, syntax);
		PlayListModel->setFilterRegExp(regExp);
	}
};
