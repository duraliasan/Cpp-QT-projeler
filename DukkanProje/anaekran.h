#ifndef ANAEKRAN_H
#define ANAEKRAN_H

#include <QMainWindow>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class AnaEkran; }
QT_END_NAMESPACE

class AnaEkran : public QMainWindow
{
    Q_OBJECT

public:
    AnaEkran(QWidget *parent = nullptr);
    ~AnaEkran();

private:
    Ui::AnaEkran *ui;
};
#endif // ANAEKRAN_H
