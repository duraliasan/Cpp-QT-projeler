#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSql>
#include <QSqlDatabase>
#include <QSqlError>
#include <QMessageBox>
#include <QErrorMessage>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <uye_islem.h>
#include <kitap_islem.h>
#include <odunc_alma.h>
#include <odunc_teslim.h>


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
    void on_uye_islemleri_clicked();

    void on_kitap_islemleri_clicked();

    void on_teslim_etme_islem_clicked();

    void on_odunc_alma_islem_clicked();

private:
    Ui::MainWindow *ui;
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    QSqlQuery *sorgu;
};
#endif // MAINWINDOW_H
