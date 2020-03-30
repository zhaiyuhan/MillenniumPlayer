#include "stdafx.h"
#include "PlayList.h"

PlayList::PlayList(QWidget *parent)
	: QWidget(parent)
{
	PlayListModel = new QSortFilterProxyModel;
	PlayListView = new QTreeView;
	PlayListView->setModel(PlayListModel);
	PlayListView->setRootIsDecorated(false);
	PlayListView->setAlternatingRowColors(true);
	PlayListView->setSortingEnabled(true);
	searchLineEdit = new QtMaterialAutoComplete();
	connect(searchLineEdit, &QLineEdit::textChanged, this,
		[=]() { filterRegExpChanged(); });
	QVBoxLayout* mainLayout = new QVBoxLayout;
	mainLayout->addWidget(searchLineEdit, Qt::AlignCenter);
	mainLayout->addWidget(PlayListView);
	setLayout(mainLayout);
}

PlayList::~PlayList()
{
}
