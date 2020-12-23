#ifndef REGISTRYWINDOW_H
#define REGISTRYWINDOW_H

#include <QWidget>

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

    void on_CancelButton_clicked();

private:
    Ui::RegistryWindow *ui;
};

#endif // REGISTRYWINDOW_H
