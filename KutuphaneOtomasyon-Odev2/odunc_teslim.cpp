#include "odunc_teslim.h"
#include "ui_odunc_teslim.h"

Odunc_Teslim::Odunc_Teslim(QSqlDatabase db, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Odunc_Teslim)
{
    ui->setupUi(this);
    sorgu = new QSqlQuery(db);
    QDate simdikizaman = QDate::currentDate();
    ui->tarih_oduncVerme->setDate(simdikizaman);
    listele();
}

Odunc_Teslim::~Odunc_Teslim()
{
    delete ui;
}

void Odunc_Teslim::listele()
{
    sorgu->prepare("select * from odunc_alinan");
    sorgu->exec();
    model = new QSqlQueryModel();
    model->setQuery(*sorgu);
    ui->tbl_oduncAlinan->setModel(model);

    sorgu->prepare("select * from odunc_teslim_edilen");
    sorgu->exec();
    model1 = new QSqlQueryModel();
    model1->setQuery(*sorgu);
    ui->tbl_teslimEdilen->setModel(model1);
}


QDate alinanTarih;
void Odunc_Teslim::on_tbl_oduncAlinan_clicked(const QModelIndex &index)
{
    ui->le_uyeNo->setText(model->index(index.row(),0).data().toString());
    ui->le_kitapNo->setText(model->index(index.row(),1).data().toString());
    QString alinanTarihSTR = model->index(index.row(),2).data().toString();
    alinanTarih = QDate::fromString(alinanTarihSTR, "dd.MM.yyyy");
    ui->tarih_oduncVerme->setMinimumDate(alinanTarih);
}


void Odunc_Teslim::on_btn_oduncVer_clicked()
{
    sorgu->prepare("select * from odunc_alinan where uye_no=? and kitap_no=?");
    sorgu->addBindValue(ui->le_uyeNo->text().toInt());
    sorgu->addBindValue(ui->le_kitapNo->text().toInt());
    sorgu->exec();
    while (sorgu->next())
    {
//ODUNC TESLIM TABLOSUNA EKLİYOR.
        sorgu->prepare("insert into odunc_teslim_edilen(uye_no,kitap_no,odunc_alma_tarih,odunc_teslim_tarih,borc) values(?,?,?,?,?)");
        sorgu->addBindValue(ui->le_uyeNo->text().toInt());
        sorgu->addBindValue(ui->le_kitapNo->text().toInt());
        sorgu->addBindValue(alinanTarih.toString("dd.MM.yyyy"));
        sorgu->addBindValue(ui->tarih_oduncVerme->date().toString("dd.MM.yyyy"));
        int gun = alinanTarih.daysTo(ui->tarih_oduncVerme->date());
        QString borc;
        if(gun > 15)
        {
            sorgu->addBindValue(gun - 15);
            borc = QString::number(gun - 15);
        }
        else
        {
            sorgu->addBindValue(0);
            borc = "0";
        }
        sorgu->exec();

//ODUNC ALINAN TABLOSUNDAN SİLİYOR
        sorgu->prepare("delete from odunc_alinan where uye_no=? and kitap_no=?");
        sorgu->addBindValue(ui->le_uyeNo->text().toInt());
        sorgu->addBindValue(ui->le_kitapNo->text().toInt());
        sorgu->exec();
        listele();
        QMessageBox::information(this, "TAMAM", "Kitap teslim edildi. Borcunuz: " + borc + " TL");
        break;
    }

}

