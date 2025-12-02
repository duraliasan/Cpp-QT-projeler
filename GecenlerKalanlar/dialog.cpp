#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    QFile dosya(":/liste/gecenler.txt");
    QFile dosya2(":/liste/kalanlar.txt");

    if(!dosya.open(QIODevice::ReadOnly) || !dosya2.open(QIODevice::ReadOnly)){
        QMessageBox::critical(this,"HATA",dosya.errorString());
        return;
    }
    QTextStream stream(&dosya);
    QTextStream stream2(&dosya2);
    while(!stream.atEnd()){
        ui->LW_gecenler->addItem(stream.readLine());
    }
    dosya.close();
    while (!stream2.atEnd()) {
        ui->LW_kalanLar->addItem(stream2.readLine());
    }
    dosya2.close();
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_BTN_hesapla_clicked()
{
    double vizeNotu = ui->SB_vize->value();
    double finalNotu = ui->SB_final->value();
    double ortalamaNot = vizeNotu* 0.4 + finalNotu * 0.6;
    if(ortalamaNot >= 60){
        ui->LW_gecenler->addItem(ui->LE_ad->text() + " " + ui->LE_soyad->text() + " " + "Ortalama Not:" + QString::number(ortalamaNot));
    }
    else{
        ui->LW_kalanLar->addItem(ui->LE_ad->text() + " " + ui->LE_soyad->text() + " " + "Ortalama Not:" + QString::number(ortalamaNot));
    }
}


void Dialog::on_BTN_kaydet_clicked()
{
    QFile dosya("C:/Users/dural/OneDrive/Masaüstü/gecenler.txt");
    QFile dosya2("C:/Users/dural/OneDrive/Masaüstü/kalanlar.txt");
    if(!dosya.open(QIODevice::WriteOnly)){
        QMessageBox::critical(this,"HATA",dosya.errorString());
        return;
    }
    if(!dosya2.open(QIODevice::WriteOnly)){
        QMessageBox::critical(this,"HATA",dosya.errorString());
        return;
    }

    QTextStream stream(&dosya);
    for (int i = 0; i < ui->LW_gecenler->count(); i++)
    {
        stream << ui->LW_gecenler->item(i)->text() + "\n";
    }
    dosya.close();

    QTextStream stream2(&dosya2);
    for (int k = 0; k < ui->LW_kalanLar->count(); k++)
    {
        stream2 << ui->LW_kalanLar->item(k)->text() + "\n";
    }

    dosya2.close();
}

