#ifndef LOGINDLG_H
#define LOGINDLG_H

#include <QDialog>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>

class loginDlg : public QDialog
{
    Q_OBJECT
public:
    explicit loginDlg(QWidget *parent = 0);

    int userID;
    QString passwd;
    QString hostIP;
    int hostport;
    bool isLogin;

signals:

public slots:
private slots:
    void loginBtnOnClick();
    void logoutBtnOnClick();


private:
    QLabel *label1, *label2, *label3, *label4;
    QLineEdit *lineEditUserID, *lineEditPsaawd, *lineEditHostIP, *lineEditHostport;
    QPushButton *loginBtn, *logoutBtn;
};

#endif // LOGINDLG_H
