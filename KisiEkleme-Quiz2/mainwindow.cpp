//DURALİ ASAN
//20010011063

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    db.setDatabaseName("C:/Users/dural/OneDrive/Belgeler/Cpp_QtCreator/20010011063_Quiz2/personeller.db");
    if(!db.open()){
        ui->statusBar->showMessage("Veri tabanına Bağlanılamadı");
    }
    else{
        ui->statusBar->showMessage("Veri tabanına Bağlanıldı");
    }
    sorgu = new QSqlQuery(db);
    listele();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::listele()
{
    sorgu->prepare("select * from personeller where per_bolum='Muhasebe'");
    sorgu->exec();
    QSqlQueryModel *model1 = new QSqlQueryModel();
    model1->setQuery(*sorgu);
    ui->tw_BilgisayarBolumu->setModel(model1);

    sorgu->prepare("select * from personeller where per_bolum='Yazılım'");
    sorgu->exec();
    QSqlQueryModel *model2 = new QSqlQueryModel();
    model2->setQuery(*sorgu);
    ui->tw_YazilimBolumu->setModel(model2);
}

void MainWindow::on_btn_Ekle_clicked()
{
    if(ui->AD->text() == "" || ui->SOYAD->text() == "")
    {
        QMessageBox::critical(this, "HATA!!", "Boş değer bırakılamaz.");
        return;
    }

    sorgu->prepare("select * from personeller where per_id=?");
    sorgu->addBindValue(ui->ID->value());
    if(!sorgu->exec()){
        QMessageBox::critical(this, "HATA!", sorgu->lastError().text());
        return;
    }
    int sayac = 0;
    while(sorgu->next()){
        sayac++;
        break;
    }
    if(sayac > 0){
        QMessageBox::critical(this, "HATA!", "Aynı öğrenci numarası olamaz");
        return;
    }
    else{
        int yas = QDate::currentDate().year() - ui->TARIH->date().year();

        sorgu->prepare("insert into personeller(per_id,per_ad,per_soyad,per_yas,per_bolum) values(?,?,?,?,?)");
        sorgu->addBindValue(ui->ID->value());
        sorgu->addBindValue(ui->AD->text());
        sorgu->addBindValue(ui->SOYAD->text());
        sorgu->addBindValue(yas);
        sorgu->addBindValue(ui->BOLUM->currentText());
        if(!sorgu->exec()){
            QMessageBox::critical(this, "HATA!", sorgu->lastError().text());
            return;
        }


        //txt yazma işlemi
        QFile dosya("C:/Users/dural/OneDrive/Belgeler/Cpp_QtCreator/20010011063_Quiz2/personeller.txt");
        if(!dosya.open(QIODevice::WriteOnly)){
            QMessageBox::critical(this,"HATA",dosya.errorString());
            return;
        }
        sorgu->prepare("select * from personeller");
        sorgu->exec();
        QSqlQueryModel *model3 = new QSqlQueryModel();
        model3->setQuery(*sorgu);

        QTextStream stream(&dosya);
        for (int satir = 0; satir < model3->rowCount(); satir++)
        {
            for(int sutun = 0; sutun < model3->columnCount(); sutun++)
            {
                stream << model3->index(satir, sutun).data().toString() + " ";
            }
            stream << "\n";
        }
        dosya.close();
        listele();

    }

}

