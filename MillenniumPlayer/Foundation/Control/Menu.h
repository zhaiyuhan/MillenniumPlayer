#pragma once

#include <QMenu>

class Menu : public QMenu
{
	Q_OBJECT

public:
	explicit Menu(QWidget *parent = 0);
	explicit Menu(const QString & title);

protected:
	virtual bool event(QEvent *event);
};
