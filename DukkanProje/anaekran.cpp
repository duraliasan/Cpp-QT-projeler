#include "anaekran.h"
#include "ui_anaekran.h"

AnaEkran::AnaEkran(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::AnaEkran)
{
    ui->setupUi(this);
}

AnaEkran::~AnaEkran()
{
    delete ui;
}

