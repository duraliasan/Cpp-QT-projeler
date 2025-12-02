#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QPushButton"
#include <QTime>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    this->showMaximized();

    ui->label_png->setGeometry(0,90,this->geometry().width(),this->geometry().height());

    ui->sure_label->setText("Süre = <font color = blue>0</font>");
    ui->sure_label->setGeometry(0,0,250,90);

    ui->label_vurulanBalon->setText("Vurulan Balon Sayısı : <font color = green>0</font>");
    ui->label_vurulanBalon->setGeometry(this->geometry().width()-ui->label_vurulanBalon->geometry().width()-50,0,350,45);

    ui->label_kacanBalon->setText("Kacan Balon Sayisi : <font color = red>0</font>");
    ui->label_kacanBalon->setGeometry(this->geometry().width()-ui->label_kacanBalon->geometry().width()-50,45,350,45);


    QTimer *zamanlayici = new QTimer(this);
    connect(zamanlayici,&QTimer::timeout,this,&MainWindow::zamanlayıcı);
    zamanlayici->start(1000);

    QTimer *timer=new QTimer(this);
    connect(timer,&QTimer::timeout,this,&MainWindow::butonOlustur);
    timer->start(700);

    QTimer *baslaTimer = new QTimer(this);
    connect(baslaTimer,&QTimer::timeout,this,&MainWindow::basla);
    baslaTimer->start(1000/160);

}

int deger = 0;
int vurulan = 0;
int kacan = 0;


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::butonOlustur()
{
    int width = this->width();
    button *my_button = new button(this);
    int randomJpg = rand()%(7);
    int randomKonum = rand()%(width-41);  //ekranın boyutu 1400 ise 0 ile 1400 arası üretsin
    my_button->setGeometry(randomKonum,91,55,55);

    my_button->setIcon(QIcon(":/image/images/"+QString::number(randomJpg)+".jpg"));
    my_button->setIconSize(QSize(55, 55));
    my_button->show();
    buttons.append(my_button);
}

void MainWindow::basla()
{
    ui->label_png->setGeometry(0,90,this->geometry().width(),this->geometry().height());
    ui->label_vurulanBalon->setGeometry(this->geometry().width()-ui->label_vurulanBalon->geometry().width()-50,0,350,45);
    ui->label_kacanBalon->setGeometry(this->geometry().width()-ui->label_kacanBalon->geometry().width()-50,45,350,45);

    foreach(button *str, buttons)
    {
        if(str->tiklandimi == false){
            str->setGeometry(str->x(),str->y()+1,str->width(),str->height());
        }
        if(str->tiklandimi){
            str->setIcon(QIcon(":/image/images/patlama.jpg"));
            vurulan++;
            ui->label_vurulanBalon->setText("Vurulan Balon Sayısı : <font color = green>"+QString::number(vurulan)+"</font>");
            str->setIconSize(QSize(55, 55));
            buttons.removeOne(str);
        }
        if(this->geometry().height() < str->y()){
            kacan++;
            ui->label_kacanBalon->setText("Kacan Balon Sayisi :  <font color = red>"+QString::number(kacan)+"</font>");
            buttons.removeOne(str);
            str->hide();
        }
    }
}


void MainWindow::zamanlayıcı()
{
    deger++;
    ui->sure_label->setText("Süre = <font color = blue>"+QString::number(deger)+ "</font>");
}



