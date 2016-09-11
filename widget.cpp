#include "widget.h"
#include "toolbox1.h"
#include <QHBoxLayout>
#include <QPalette>

Widget::Widget(const QIcon icon, int ID, QString name, toolbox1 *w, QWidget *parent)
    : QWidget(parent)
{
    userID = ID;
    userName = name;
    main_w = w;
    setWindowTitle(name);
    setWindowIcon(icon);
    //设置最大化最小化失效
    setWindowFlags(windowFlags()&~Qt::WindowMaximizeButtonHint & ~Qt::WindowMinimizeButtonHint);
    //设置背景颜色
    setAutoFillBackground(true);
    QPalette palette;
    palette.setColor(QPalette::Background, QColor(Qt::darkCyan));
    setPalette(palette);

    init_widget();

}

Widget::~Widget()
{

}

void Widget::init_widget()
{
    textBrower = new QTextBrowser;
    // 设置textBrowser背景颜色图片
    textBrower->setStyleSheet("background-image: url(:/images/2.jpg;");

    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(textBrower);

    fontCombox = new QFontComboBox;
    fontCombox->setToolTip(tr("字体"));

    comboBox = new QComboBox;
    comboBox->setToolTip(tr("字号"));
    comboBox->setEditable(true);
    comboBox->addItem(QString::number(8));
    comboBox->addItem(QString::number(9));
    comboBox->addItem(QString::number(10));
    comboBox->addItem(QString::number(11));
    comboBox->addItem(QString::number(12));
    comboBox->addItem(QString::number(13));
    comboBox->addItem(QString::number(14));
    comboBox->addItem(QString::number(15));
    comboBox->addItem(QString::number(16));
    comboBox->addItem(QString::number(17));
    comboBox->addItem(QString::number(18));
    comboBox->addItem(QString::number(19));
    comboBox->addItem(QString::number(20));
    comboBox->addItem(QString::number(21));
    comboBox->addItem(QString::number(22));
    comboBox->setCurrentIndex(4);//设置当前索引号第四个，从0开始算


    toolBtn1 = new QToolButton;
    toolBtn1->setToolTip(tr("加粗"));
    toolBtn1->setText(tr("加粗"));
    toolBtn1->setCheckable(true);
    toolBtn1->setAutoRaise(true);//鼠标移动到这里会浮起
    toolBtn1->setIcon(QPixmap(":/images/bold.png"));

    toolBtn2 = new QToolButton;
    toolBtn2->setToolTip(tr("倾斜"));
    toolBtn2->setText(tr("倾斜"));
    toolBtn2->setCheckable(true);
    toolBtn2->setAutoRaise(true);//鼠标移动到这里会浮起
    toolBtn2->setIcon(QPixmap(":/images/italic.png"));

    toolBtn3 = new QToolButton;
    toolBtn3->setToolTip(tr("下划线"));
    toolBtn3->setText(tr("下划线"));
    toolBtn3->setCheckable(true);
    toolBtn3->setAutoRaise(true);//鼠标移动到这里会浮起
    toolBtn3->setIcon(QPixmap(":/images/under.png"));

    toolBtn4 = new QToolButton;
    toolBtn4->setToolTip(tr("颜色"));
    toolBtn4->setText(tr("颜色"));
    toolBtn4->setCheckable(true);
    toolBtn4->setAutoRaise(true);//鼠标移动到这里会浮起
    toolBtn4->setIcon(QPixmap(":/images/color.png"));

    toolBtn = new QToolButton;
    toolBtn->setText(tr("显示窗口"));
    toolBtn->setAutoRaise(true);

    QHBoxLayout *layout2 = new QHBoxLayout;
    layout2->addWidget(fontCombox);
    layout2->addWidget(comboBox);
    layout2->addWidget(toolBtn1);
    layout2->addWidget(toolBtn2);
    layout2->addWidget(toolBtn3);
    layout2->addWidget(toolBtn4);
    layout2->addWidget(toolBtn);

    lineEdit = new QLineEdit;

    pushBtn = new QPushButton;
    pushBtn->setText(tr("发送"));

    QHBoxLayout *layout3 = new QHBoxLayout;
    layout3->addWidget(lineEdit);
    layout3->addWidget(pushBtn);

    QVBoxLayout *mainlayout = new QVBoxLayout(this);
    mainlayout->addLayout(layout);
    mainlayout->addLayout(layout2);
    mainlayout->addLayout(layout3);

    mainlayout->setSizeConstraint(QLayout::SetFixedSize);//设置窗口大小不能改变
    setLayout(mainlayout);

    textBrower->setCurrentFont(fontCombox->font());//设置textbrowser的默认字体
    textBrower->setFontPointSize(comboBox->currentText().toDouble());//设置textBrowser的
    lineEdit->setFocus();




}
