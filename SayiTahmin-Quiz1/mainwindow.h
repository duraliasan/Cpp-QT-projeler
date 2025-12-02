#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <random>

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
    void on_SB_UstSinir_valueChanged(int arg1);

    void on_SB_AltSinir_valueChanged(int arg1);

    void on_BTN_TahminEt_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
