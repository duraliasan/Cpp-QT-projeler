#ifndef UYE_ISLEM_H
#define UYE_ISLEM_H

#include <QDialog>
#include <QSql>
#include <QSqlDatabase>
#include <QSqlError>
#include <QMessageBox>
#include <QErrorMessage>
#include <QSqlQuery>
#include <QSqlQueryModel>


namespace Ui {
class Uye_Islem;
}

class Uye_Islem : public QDialog
{
    Q_OBJECT

public:
    explicit Uye_Islem(QSqlDatabase, QWidget *parent = nullptr);
    ~Uye_Islem();
    void listele();

private slots:
    void on_btn_yeniKayit_clicked();

    void on_btn_guncelle_clicked();

    void on_btn_sil_clicked();

    void on_tbl_uyeler_clicked(const QModelIndex &index);

private:
    Ui::Uye_Islem *ui;
    QSqlQuery *sorgu;
    QSqlQueryModel *model;
};

#endif // UYE_ISLEM_H
