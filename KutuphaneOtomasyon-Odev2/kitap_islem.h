#ifndef KITAP_ISLEM_H
#define KITAP_ISLEM_H

#include <QDialog>
#include <QSql>
#include <QSqlDatabase>
#include <QSqlError>
#include <QMessageBox>
#include <QErrorMessage>
#include <QSqlQuery>
#include <QSqlQueryModel>

namespace Ui {
class Kitap_Islem;
}

class Kitap_Islem : public QDialog
{
    Q_OBJECT

public:
    explicit Kitap_Islem(QSqlDatabase, QWidget *parent = nullptr);
    ~Kitap_Islem();
    void listele();

private slots:
    void on_tbl_kitaplar_clicked(const QModelIndex &index);

    void on_btn_yeniKayit_clicked();

    void on_btn_sil_clicked();

    void on_btn_guncelle_clicked();

private:
    Ui::Kitap_Islem *ui;
    QSqlQuery *sorgu;
    QSqlQueryModel *model, *model1, *model2;
};

#endif // KITAP_ISLEM_H
