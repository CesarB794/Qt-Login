#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_LoginButton_clicked();

    void on_RegistryButton_clicked();

    void on_ExitButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
