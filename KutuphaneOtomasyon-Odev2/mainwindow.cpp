#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    db.setDatabaseName("C:/Users/dural/OneDrive/Belgeler/Cpp_QtCreator/20010011063_Odev2/kutuphane.db");

    if(db.open())
    {
        ui->statusBar->showMessage("Veri tabanına Bağlanıldı");
    }
    else
    {
        ui->statusBar->showMessage("Veri tabanına Bağlanılamadı");
    }
    sorgu = new QSqlQuery(db);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_uye_islemleri_clicked()
{
    Uye_Islem *uyeler = new Uye_Islem(db);
    uyeler->show();
}


void MainWindow::on_kitap_islemleri_clicked()
{
    Kitap_Islem *kitaplar = new Kitap_Islem(db);
    kitaplar->show();
}


void MainWindow::on_teslim_etme_islem_clicked()
{
    Odunc_Alma *oduncAlma = new Odunc_Alma(db);
    oduncAlma->show();
}


void MainWindow::on_odunc_alma_islem_clicked()
{
    Odunc_Teslim *teslim = new Odunc_Teslim(db);
    teslim->show();
}

