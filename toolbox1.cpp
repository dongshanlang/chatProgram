#include "toolbox1.h"
#include <QGroupBox>
#include <QVBoxLayout>
#include "logindlg.h"

toolbox1::toolbox1(QWidget *parent) :
    QToolBox(parent)
{
    setWindowIcon(QPixmap(":/images/3.png"));//设置主窗口图标
    init_userName();// 设置用户名
    init_toolBtn();//初始化主窗口控件
    loginDlg login;
    login.exec();//弹出模式对话框，程序到此处阻塞





}

bool toolbox1::eventFilter(QObject *watched, QEvent *event)
{
    if(event->type() == QEvent::MouseButtonPress)//如果是鼠标按键信号
    {
        int i = watched->objectName().toInt();
        child[i]->hide();
        child[i]->showNormal();//将toolbtn对应的child显示到屏幕上
    }
    return QToolBox::eventFilter(watched, event);//其他信号交给父类进行默认处理
}

void toolbox1::init_toolBtn()
{
    QString imageName;
    for(int i = 0; i<CLIENTCOUNT; i++)
    {
        toolBtn[i] = new QToolButton();//new 256个toolBtn
        toolBtn[i]->setObjectName(QString::number(i));//为每个toolbtn设置objectname属性
        toolBtn[i]->installEventFilter(this);//toolbtn的点击事件由toolbox1来处理，括号内部为响应事件的widget，
        toolBtn[i]->setText(userName[i]);//设置toolbtn标题
        imageName.sprintf(":images/%d.png", i);//拼接字符串
        toolBtn[i]->setIcon(QPixmap(imageName));//设置btn的图标（头像）
        toolBtn[i]->setIconSize(QPixmap(imageName).size());//设置toolbtn大小和图像一致
        toolBtn[i]->setAutoRaise(true);//设置toolbtn的自动浮起效果
        toolBtn[i]->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);//设置toolbtn文字在图像旁边
        toolBtn[i]->setToolTip(tr("未知"));//设置toolbtn鼠标提示，未知
        child[i] = new Widget(toolBtn[i]->icon(), i, toolBtn[i]->text(), this);
    }

    QGroupBox *groupBox[8];
    QVBoxLayout *layout[8];
    static int index = 0;
    for(int i = 0; i<8; i++)
    {
        groupBox[i] = new QGroupBox;
        layout[i] = new QVBoxLayout(groupBox[i]);//初始化设置属于
        layout[i]->setMargin(10);//设置间距
        layout[i]->setAlignment(Qt::AlignHCenter);//设置布局中窗体的位置
        for(int j = 0; j < 32; j++)
        {
            layout[i]->addWidget(toolBtn[index++]);//循环加到layout中
        }
        layout[i]->addStretch();//加入一个占位符
    }
    addItem((QWidget *)groupBox[0], tr("好友"));
    addItem((QWidget *)groupBox[1], tr("同学"));
    addItem((QWidget *)groupBox[2], tr("同事"));
    addItem((QWidget *)groupBox[3], tr("同志"));
    addItem((QWidget *)groupBox[4], tr("网友"));
    addItem((QWidget *)groupBox[5], tr("驴友"));
    addItem((QWidget *)groupBox[6], tr("家人"));
    addItem((QWidget *)groupBox[7], tr("陌生人"));



}

void toolbox1::init_userName()
{
    for (int i = 0; i<CLIENTCOUNT; i++)
    {
        userName[i] = tr("用户名") + QString::number(i);
    }
}
