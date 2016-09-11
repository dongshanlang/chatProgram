#ifndef TOOLBOX1_H
#define TOOLBOX1_H

#include <QToolBox>
#include <QToolButton>
#include <QEvent>
#include "widget.h"


#define CLIENTCOUNT 256//最大客户数

class toolbox1 : public QToolBox
{
    Q_OBJECT
public:
    explicit toolbox1(QWidget *parent = 0);

signals:

public slots:
    bool eventFilter(QObject *watched, QEvent *event);

private:
    QString userName[CLIENTCOUNT];
    QToolButton *toolBtn[CLIENTCOUNT];//创建256个button
    Widget *child[CLIENTCOUNT];
    void init_toolBtn();
    void init_userName();

};

#endif // TOOLBOX1_H
