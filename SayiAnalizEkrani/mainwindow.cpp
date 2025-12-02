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

int randomSayi;
void MainWindow::on_BTN_sayiUret_clicked()
{
    ui->LW_tum->clear();
    ui->LW_asal->clear();

    int altSinir, ustSinir;
    altSinir = ui->SB_altSinir->value();
    ustSinir = ui->SB_ustSinir->value();
    if (altSinir >= ustSinir){
        QMessageBox::critical(this, "Hata", "DEĞER!");
        return;
    }

    randomSayi = rand()%(ustSinir - altSinir) + altSinir;
    ui->L_sayiKutusu->setText(QString::number(randomSayi));

}


void MainWindow::on_BTN_listele_clicked()
{
    ui->LW_tum->clear();
    ui->LW_asal->clear();

    if(ui->LW_tum->isEnabled())
    {
        for(int i = 1 ; i <= randomSayi ; i++)
        {
            if(randomSayi%i == 0)
            {
                ui->LW_tum->addItem(QString::number(i));
            }
        }
    }

    if(ui->LW_asal->isEnabled())
    {
        for(int i = 2 ; i <= randomSayi/2 ; i++)
        {
            int kontrol = 0;

            if(randomSayi % i == 0)
            {
                for(int j = 2 ; j <= i/2 ; j++)
                {
                    if(i % j == 0)
                    {
                        kontrol = 1;
                        break;
                    }
                }
                if(kontrol == 0)
                {
                    ui->LW_asal->addItem(QString::number(i));
                }
            }
        }
    }

}


void MainWindow::on_checkBox_stateChanged(int arg1)
{
    if(ui->LW_tum->isEnabled()){
        ui->LW_tum->setEnabled(false);
        ui->LW_tum->clear();
    }

    else{
        ui->LW_tum->setEnabled(true);
    }
}


void MainWindow::on_checkBox_2_stateChanged(int arg1)
{
    if(ui->LW_asal->isEnabled()){
        ui->LW_asal->setEnabled(false);
        ui->LW_asal->clear();
    }

    else{
        ui->LW_asal->setEnabled(true);
    }
}

