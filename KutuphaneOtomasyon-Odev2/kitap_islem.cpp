#include "kitap_islem.h"
#include "ui_kitap_islem.h"

Kitap_Islem::Kitap_Islem(QSqlDatabase db, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Kitap_Islem)
{
    ui->setupUi(this);
    sorgu = new QSqlQuery(db);
    listele();
}

Kitap_Islem::~Kitap_Islem()
{
    delete ui;
}

void Kitap_Islem::on_tbl_kitaplar_clicked(const QModelIndex &index)
{
    ui->le_kitapNo->setText(model->index(index.row(),0).data().toString());
    ui->le_kitapAd->setText(model->index(index.row(),1).data().toString());
    ui->le_kitapStok->setText(model->index(index.row(),2).data().toString());


    sorgu->prepare("select * from odunc_alinan where kitap_no=?");
    sorgu->addBindValue(ui->le_kitapNo->text().toInt());
    sorgu->exec();
    model1 = new QSqlQueryModel();
    model1->setQuery(*sorgu);
    ui->tbl_oduncKitaplar->setModel(model1);


    sorgu->prepare("select * from odunc_teslim_edilen where kitap_no=?");
    sorgu->addBindValue(ui->le_kitapNo->text().toInt());
    sorgu->exec();
    model2 = new QSqlQueryModel();
    model2->setQuery(*sorgu);
    ui->tbl_gecmisOduncKitaplar->setModel(model2);



}

void Kitap_Islem::listele()
{
    sorgu->prepare("select * from kitap");

    if(!sorgu->exec()){
        QMessageBox::critical(this, "hata", "hataburda1");
    }
    model = new QSqlQueryModel();
    model->setQuery(*sorgu);
    ui->tbl_kitaplar->setModel(model);
}




void Kitap_Islem::on_btn_yeniKayit_clicked()
{
    if(ui->le_kitapAd->text() == "" || ui->le_kitapStok->text() == "")
    {
        QMessageBox::critical(this, "HATA", "Gerekli alanları doldurunuz!");
        return;
    }

    sorgu->prepare("insert into kitap(kitap_ad,kitap_sayi) values(?,?)");
    sorgu->addBindValue(ui->le_kitapAd->text());
    sorgu->addBindValue(ui->le_kitapStok->text());

    if(!sorgu->exec()){
        QMessageBox::critical(this, "HATA!", sorgu->lastError().text());
        return;
    }
    listele();
}


void Kitap_Islem::on_btn_sil_clicked()
{
    sorgu->prepare("select * from odunc_alinan where kitap_no=?");
    sorgu->addBindValue(ui->le_kitapNo->text().toInt());
    sorgu->exec();
    while(sorgu->next()){
        QMessageBox::critical(this, "HATA", "Kitap okuyucudayken silinemez!");
        return;
    }

    sorgu->prepare("delete from kitap where kitap_no=?");
    sorgu->addBindValue(ui->le_kitapNo->text().toInt());
    sorgu->exec();
    listele();
}


void Kitap_Islem::on_btn_guncelle_clicked()
{
    if(ui->le_kitapAd->text() == "" || ui->le_kitapStok->text() == "")
    {
        QMessageBox::critical(this, "HATA", "Gerekli alanları doldurunuz!");
        return;
    }

    sorgu->prepare("update kitap set kitap_ad=? , kitap_sayi=? where kitap_no=?");
    sorgu->addBindValue(ui->le_kitapAd->text());
    sorgu->addBindValue(ui->le_kitapStok->text());
    sorgu->addBindValue(ui->le_kitapNo->text().toInt());
    sorgu->exec();
    listele();
}

