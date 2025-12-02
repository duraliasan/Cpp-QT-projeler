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

double genelOrtalama, toplamKredi = 0, toplamNot = 0;

void MainWindow::on_kesinEkle_clicked()
{
    QString harfOrt = ui->kesinOrtalama->currentText();
    double notOrt;
    if(harfOrt == "AA")
    {
        notOrt = 4.0;
    }
    else if(harfOrt == "BA")
    {
        notOrt = 3.5;
    }
    else if(harfOrt == "BB")
    {
        notOrt = 3.0;
    }
    else if(harfOrt == "CB")
    {
        notOrt = 2.5;
    }
    else if(harfOrt == "CC")
    {
        notOrt = 2.0;
    }
    else if(harfOrt == "DC")
    {
        notOrt = 1.5;
    }
    else if(harfOrt == "DD")
    {
        notOrt = 1.00;
    }
    else if(harfOrt == "FD")
    {
        notOrt = 0.5;
    }
    else if(harfOrt == "FF")
    {
        notOrt = 0.0;
    }

    toplamNot = toplamNot + (notOrt * ui->kesinKredi->value());
    toplamKredi = toplamKredi + ui->kesinKredi->value();
    genelOrtalama = toplamNot / toplamKredi;
    ui->kesinLabel->setText(QString::number(genelOrtalama));

}

