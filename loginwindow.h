#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QWidget>
#include <QSqlQuery>

namespace Ui {
class LoginWindow;
}

class LoginWindow : public QWidget
{
    Q_OBJECT

public:
    explicit LoginWindow(QWidget *parent = nullptr);
    ~LoginWindow();

private slots:
    void on_CancelButton_clicked();
    bool Login(const QString &, const QString &);
    void on_AcceptButton_clicked();

private:
    Ui::LoginWindow *ui;
    QString path="user.db";
    QSqlQuery sql;
};

#endif // LOGINWINDOW_H
