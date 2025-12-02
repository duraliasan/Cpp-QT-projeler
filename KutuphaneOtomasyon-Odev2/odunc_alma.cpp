#include "odunc_alma.h"
#include "ui_odunc_alma.h"

Odunc_Alma::Odunc_Alma(QSqlDatabase db, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Odunc_Alma)
{
    ui->setupUi(this);
    sorgu = new QSqlQuery(db);
    QDate simdikizaman = QDate::currentDate();
    ui->tarih_oduncAlma->setDate(simdikizaman);
    listele();
}

Odunc_Alma::~Odunc_Alma()
{
    delete ui;
}

void Odunc_Alma::listele()
{
    sorgu->prepare("select * from uye");
    sorgu->exec();
    model = new QSqlQueryModel();
    model->setQuery(*sorgu);
    ui->tbl_uyeler->setModel(model);

    sorgu->prepare("select * from kitap");
    sorgu->exec();
    model1 = new QSqlQueryModel();
    model1->setQuery(*sorgu);
    ui->tbl_kitaplar->setModel(model1);
}

void Odunc_Alma::on_tbl_uyeler_clicked(const QModelIndex &index)
{
    ui->le_uyeNo->setText(model->index(index.row(),0).data().toString());

    sorgu->prepare("select * from odunc_alinan where uye_no=?");
    sorgu->addBindValue(ui->le_uyeNo->text().toInt());
    sorgu->exec();
    model2 = new QSqlQueryModel();
    model2->setQuery(*sorgu);
    ui->tbl_oduncAlinanKitaplar->setModel(model2);

}

int kitapSayisi;
void Odunc_Alma::on_tbl_kitaplar_clicked(const QModelIndex &index)
{
    ui->le_kitapNo->setText(model1->index(index.row(),0).data().toString());
    kitapSayisi = model1->index(index.row(),2).data().toInt();
}


void Odunc_Alma::on_btn_oduncAl_clicked()
{
    if(ui->le_kitapNo->text() == "" || ui->le_uyeNo->text() == "")
    {
        QMessageBox::critical(this, "HATA", "Boş değer bırakılamaz!");
        return;
    }

    sorgu->prepare("select * from odunc_alinan where kitap_no=?");
    sorgu->addBindValue(ui->le_kitapNo->text().toInt());
    sorgu->exec();
    int sayac = 0;
    while (sorgu->next()) {
        sayac++;
        if(sayac >= kitapSayisi)
        {
            QMessageBox::information(this, "MAALESEF", "Elimizde bu kitap kalmamış.");
            return;
        }
    }


    sorgu->prepare("select * from odunc_alinan where uye_no=? and kitap_no=?");
    sorgu->addBindValue(ui->le_uyeNo->text().toInt());
    sorgu->addBindValue(ui->le_kitapNo->text().toInt());
    sorgu->exec();
    while(sorgu->next())
    {
        QMessageBox::critical(this, "HATA", "Aynı kitap birden fazla alınamaz!!");
        return;
    }



    sorgu->prepare("insert into odunc_alinan(uye_no,kitap_no,odunc_alma_tarih) values(?,?,?)");
    sorgu->addBindValue(ui->le_uyeNo->text().toInt());
    sorgu->addBindValue(ui->le_kitapNo->text().toInt());
    sorgu->addBindValue(ui->tarih_oduncAlma->date().toString("dd.MM.yyyy"));

    if(!sorgu->exec()){
        QMessageBox::critical(this, "HATA!", sorgu->lastError().text());
        return;
    }
    listele();
}

