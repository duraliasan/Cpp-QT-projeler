#include "uye_islem.h"
#include "ui_uye_islem.h"

Uye_Islem::Uye_Islem(QSqlDatabase db, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Uye_Islem)
{
    ui->setupUi(this);
    sorgu = new QSqlQuery(db);
    listele();
}

Uye_Islem::~Uye_Islem()
{
    delete ui;
}

void Uye_Islem::on_btn_yeniKayit_clicked()
{
    if(ui->le_uyeAd->text() == "" || ui->le_uyeSoyad->text() == "")
    {
        QMessageBox::critical(this, "HATA", "Gerekli alanları doldurunuz!");
        return;
    }

    sorgu->prepare("insert into uye(uye_ad,uye_soyad) values(?,?)");
    sorgu->addBindValue(ui->le_uyeAd->text());
    sorgu->addBindValue(ui->le_uyeSoyad->text());

    if(!sorgu->exec()){
        QMessageBox::critical(this, "HATA!", sorgu->lastError().text());
        return;
    }
    listele();
}


void Uye_Islem::on_btn_guncelle_clicked()
{
    if(ui->le_uyeAd->text() == "" || ui->le_uyeSoyad->text() == "")
    {
        QMessageBox::critical(this, "HATA", "Gerekli alanları doldurunuz!");
        return;
    }

    sorgu->prepare("update uye set uye_ad=? , uye_soyad=? where uye_no=?");
    sorgu->addBindValue(ui->le_uyeAd->text());
    sorgu->addBindValue(ui->le_uyeSoyad->text());
    sorgu->addBindValue(ui->le_uyeNo->text());
    sorgu->exec();
    listele();

}


void Uye_Islem::on_btn_sil_clicked()
{



    sorgu->prepare("select * from odunc_alinan where uye_no=?");
    sorgu->addBindValue(ui->le_uyeNo->text().toInt());
    sorgu->exec();
    while(sorgu->next()){
        QMessageBox::critical(this, "HATA", "Bu kişi kitabını teslim etmeden kaydını silemez!");
        return;
    }

    sorgu->prepare("delete from uye where uye_no=?");
    sorgu->addBindValue(ui->le_uyeNo->text().toInt());
    sorgu->exec();
    listele();
}

void Uye_Islem::listele()
{
    sorgu->prepare("select * from uye");

    if(!sorgu->exec()){
        QMessageBox::critical(this, "hata", "hataburda1");
    }
    model = new QSqlQueryModel();
    model->setQuery(*sorgu);
    ui->tbl_uyeler->setModel(model);
}


void Uye_Islem::on_tbl_uyeler_clicked(const QModelIndex &index)
{
    ui->le_uyeNo->setText(model->index(index.row(),0).data().toString());
    ui->le_uyeAd->setText(model->index(index.row(),1).data().toString());
    ui->le_uyeSoyad->setText(model->index(index.row(),2).data().toString());
}

