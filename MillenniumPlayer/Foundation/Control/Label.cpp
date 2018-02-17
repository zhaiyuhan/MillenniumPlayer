#include "stdafx.h"
#include "Label.h"

Label::Label(QWidget *parent, QString text)
	: QLabel(parent)
{
	setText(text);
	setScaledContents(true);
}

Label::Label(QWidget * parent, QString text, int fontsize, QColor fontcolor)
{	
	setText(text);
	setScaledContents(true);
	QFont f;
	f.setPointSize(fontsize);
	setFont(f);
	QPalette p;
	p.setColor(QPalette::Foreground, fontcolor);
	setPalette(p);
}

Label::~Label()
{
}
