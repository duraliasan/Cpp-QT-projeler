#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

int randomSayi, ustSinir, altSinir;
void MainWindow::on_SB_UstSinir_valueChanged(int arg1)
{
    if(ui->SB_AltSinir->value() >= ui->SB_UstSinir->value()){
        QMessageBox::critical(this, "Hata", "Alt Sınır Üst Sınıra Eşit veya Büyük olamaz!", "OK", "Cancel");
    }
    else{
        int altSinir, ustSinir;
        altSinir = ui->SB_AltSinir->value();
        ustSinir = ui->SB_UstSinir->value();
        randomSayi = rand() % (ustSinir-altSinir) + altSinir;
        ui->label->setText(QString::number(randomSayi));
    }
}


void MainWindow::on_SB_AltSinir_valueChanged(int arg1)
{
    if(ui->SB_AltSinir->value() >= ui->SB_UstSinir->value()){
        QMessageBox::critical(this, "Hata", "Alt Sınır Üst Sınıra Eşit veya Büyük olamaz!", "OK", "Cancel");
    }
    else{
        int altSinir, ustSinir;
        altSinir = ui->SB_AltSinir->value();
        ustSinir = ui->SB_UstSinir->value();
        randomSayi = rand() % (ustSinir-altSinir) + altSinir;
        ui->label->setText(QString::number(randomSayi));
    }
}



void MainWindow::on_BTN_TahminEt_clicked()
{
    ui->LW_Tahminler->clear();
    QFont Font;
    int sayac = 0, yeniRandomSayi, altSinir, ustSinir;
    altSinir = ui->SB_AltSinir->value();
    ustSinir = ui->SB_UstSinir->value();
    Font.setFamily(ui->CB_Font->currentText());
    Font.setPointSize(ui->SB_YaziBoyut->value());
    Font.setBold(ui->CB_Bold->isChecked());
    Font.setItalic(ui->CB_Italic->isChecked());

    ui->LW_Tahminler->setFont(Font);

    while (true) {
        sayac += 1;
        yeniRandomSayi = rand() % (ustSinir-altSinir) + altSinir;

        ui->LW_Tahminler->addItem(QString::number(sayac) + ". deneme. Sayi: " + QString::number(yeniRandomSayi));
        if(yeniRandomSayi == randomSayi){
            ui->LW_Tahminler->addItem(QString::number(sayac) + ". denemede buldunuz. Sayi: " + QString::number(yeniRandomSayi));
            break;
        }
    }
}

