#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_btn_Onay_clicked()
{
    QFont my_font;
    my_font.setFamily(ui->fontComboBox->currentText());
    my_font.setPointSize(ui->sb_Buyukluk->value());
    QPalette my_palet;
    my_palet.setColor(QPalette::WindowText, ui->cb_Renk->currentText());

    if(ui->chb_Kalin->isChecked())
    {
        my_font.setBold(true);
    }
    if(ui->chb_Italik->isChecked())
    {
        my_font.setItalic(true);
    }

    ui->YAZDIR->setPalette(my_palet);
    ui->YAZDIR->setFont(my_font);
    ui->YAZDIR->setText(ui->txt_Yazi->text());
}

