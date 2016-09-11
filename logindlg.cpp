#include "logindlg.h"
#include <QGridLayout>
#include <QMessageBox>
loginDlg::loginDlg(QWidget *parent) :
    QDialog(parent)
{
    label1 = new QLabel;
    label1->setText(tr("用户名"));
    lineEditUserID = new QLineEdit;

    label2 = new QLabel;
    label2->setText(tr("密码"));
    lineEditPsaawd = new QLineEdit;
    lineEditPsaawd->setEchoMode(QLineEdit::Password);//设置为密码框

    label3 = new QLabel;
    label3->setText(tr("服务器IP"));
    lineEditHostIP = new QLineEdit;

    label4 = new QLabel;
    label4->setText(tr("服务端口号"));
    lineEditHostport = new QLineEdit;

    loginBtn = new QPushButton;
    loginBtn->setText(tr("登陆"));
    logoutBtn = new QPushButton;
    logoutBtn->setText(tr("取消"));

    QGridLayout *layout1 = new QGridLayout(this);
    layout1->addWidget(label1, 0, 0);
    layout1->addWidget(lineEditUserID, 0, 1);
    layout1->addWidget(label2, 1, 0);
    layout1->addWidget(lineEditPsaawd, 1, 1);
    layout1->addWidget(label3, 2, 0);
    layout1->addWidget(lineEditHostIP, 2, 1);
    layout1->addWidget(label4, 3, 0);
    layout1->addWidget(lineEditHostport, 3, 1);

    layout1->addWidget(loginBtn, 4, 0);
    layout1->addWidget(logoutBtn, 4, 1);

    layout1->setColumnStretch(0, 1);
    layout1->setColumnStretch(1, 1);

    layout1->setMargin(15);
    layout1->setSpacing(10);
    layout1->setSizeConstraint(QLayout::SetFixedSize);

    connect(loginBtn, SIGNAL(clicked()), this, SLOT(loginBtnOnClick()));
    connect(logoutBtn, SIGNAL(clicked()), this, SLOT(logoutBtnOnClick()));

    isLogin = false;
    setWindowIcon(QPixmap(":/images/3.png"));//设置窗口图标
    lineEditUserID->setFocus();//设置lineEditUserID控件具有输入焦点

    //设置窗口没有边框
    setWindowFlags(Qt::FramelessWindowHint);

    //设置对话框背景颜色或图片
    setAutoFillBackground(true);
    QPalette palette;
    palette.setBrush(QPalette::Background, QBrush(QPixmap(":/images/1.jpg")));
    setPalette(palette);


}

void loginDlg::loginBtnOnClick()
{
    if(lineEditUserID->text().isEmpty())
    {
        QMessageBox::information(this, tr("错误"), tr("请输入用户名"));
        lineEditUserID->setFocus();
    }else
    {
        bool ok;
        userID = lineEditUserID->text().toInt(&ok);
        if(!ok)
        {
            QMessageBox::information(this, tr("错误"), tr("用户名为0-255"));
            lineEditUserID->setFocus();
        }else
        {
            isLogin = true;
            passwd = lineEditPsaawd->text();
            hostIP = lineEditHostIP->text();
            hostport = lineEditHostport->text().toInt();
            close();
        }
    }
}

void loginDlg::logoutBtnOnClick()
{
    close();
}
