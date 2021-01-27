#ifndef REGISTRYWINDOW_H
#define REGISTRYWINDOW_H

#include <QWidget>
#include <QString>
#include <QSqlQuery>

namespace Ui {
class RegistryWindow;
}

class RegistryWindow : public QWidget
{
    Q_OBJECT

public:
    explicit RegistryWindow(QWidget *parent = nullptr);
    ~RegistryWindow();

private slots:
    void on_SingInButton_clicked();

    bool Register(const QString &, const QString &, const QString &, const QString &);

    void on_CancelButton_clicked();

private:
    Ui::RegistryWindow *ui;
    QString path="user.db";
    QSqlQuery sql;
};

#endif // REGISTRYWINDOW_H
