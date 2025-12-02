#include "fiyatlistesi.h"
#include "ui_fiyatlistesi.h"

fiyatListesi::fiyatListesi(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::fiyatListesi)
{
    ui->setupUi(this);
}

fiyatListesi::~fiyatListesi()
{
    delete ui;
}
