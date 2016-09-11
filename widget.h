#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QTextBrowser>
#include <QFontComboBox>
#include <QComboBox>
#include <QToolButton>
#include <QColor>

class toolbox1;//在toolbox1中包含了wodget.h，在这个文件中就不能包含toolbox1了，防止交叉包含，解决办法：在这里声明要用到这个类，在才cpp文件中包含即可
class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(const QIcon icon, int ID, QString name, toolbox1 *w, QWidget *parent = 0);
    ~Widget();

    QPushButton *pushBtn;

private:
    void init_widget();
    QTextBrowser *textBrower;
    QFontComboBox *fontCombox;
    QComboBox *comboBox;
    QToolButton *toolBtn1, *toolBtn2, *toolBtn3, *toolBtn4, *toolBtn;

    QLineEdit *lineEdit;

    int userID;
    QString userName;
    QColor color;
    toolbox1 *main_w;











};

#endif // WIDGET_H
