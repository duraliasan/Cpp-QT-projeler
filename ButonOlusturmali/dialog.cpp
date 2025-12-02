#include "dialog.h"
#include "ui_dialog.h"
#include "QFile"
#include "QTextStream"
#include "QMessageBox"
#include "QPushButton"
#include "QIcon"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    QPushButton *btnAccept=new QPushButton(QIcon(":/dialog/images/accept.png"),"Accept",this);

    QPushButton *btnReject=new QPushButton("Reject",this);
    btnReject->setIcon(QIcon(":/dialog/images/cancel.png"));

    ui->buttonBox->addButton(btnAccept,QDialogButtonBox::ButtonRole::AcceptRole);
    ui->buttonBox->addButton(btnReject,QDialogButtonBox::ButtonRole::RejectRole);

    connect(btnAccept,&QPushButton::clicked,this,&Dialog::kaydet_);
    connect(btnReject,&QPushButton::clicked,this,&Dialog::reject);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::kaydet_()
{
    QFile file("metin.txt");
    if (!file.open(QIODevice::WriteOnly))
    {
        QMessageBox::critical(this,"Hata",file.errorString());

    }
    QTextStream stream(&file);
    stream << ui->txtMetin->toPlainText();
    file.close();
    m_kaydedilmi=true;

    QMessageBox::information(this,"BİlGİ","Metin Kaydedildi");
}
void Dialog::oku_()
{
    QFile file("metin.txt");
    if (!file.open(QIODevice::ReadOnly))
    {
        QMessageBox::critical(this,"Hata",file.errorString());

    }
    QTextStream stream(&file);
    ui->txtMetin->setPlainText(stream.readAll());
    file.close();

}




void Dialog::on_txtMetin_textChanged()
{
    m_kaydedilmi=false;
}

void Dialog::on_btnTemizle_clicked()
{
    ui->txtMetin->clear();
}

void Dialog::on_btnKaydet_clicked()
{
    kaydet_();
}

void Dialog::on_btnOku_clicked()
{
    oku_();
}
