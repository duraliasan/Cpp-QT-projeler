#ifndef FIYATLISTESI_H
#define FIYATLISTESI_H

#include <QMainWindow>

namespace Ui {
class fiyatListesi;
}

class fiyatListesi : public QMainWindow
{
    Q_OBJECT

public:
    explicit fiyatListesi(QWidget *parent = nullptr);
    ~fiyatListesi();

private:
    Ui::fiyatListesi *ui;
};

#endif // FIYATLISTESI_H
