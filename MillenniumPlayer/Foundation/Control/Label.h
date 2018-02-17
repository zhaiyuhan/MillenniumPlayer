#pragma once

#include <QLabel>

class Label : public QLabel
{
	Q_OBJECT

public:
	Label(QWidget * parent, QString text);
	Label(QWidget * parent, QString text, int fontsize, QColor fontcolor);
	~Label();
};
