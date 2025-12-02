#ifndef ODUNC_ALMA_H
#define ODUNC_ALMA_H

#include <QDialog>
#include <QSql>
#include <QSqlDatabase>
#include <QSqlError>
#include <QMessageBox>
#include <QErrorMessage>
#include <QSqlQuery>
#include <QSqlQueryModel>

namespace Ui {
class Odunc_Alma;
}

class Odunc_Alma : public QDialog
{
    Q_OBJECT

public:
    explicit Odunc_Alma(QSqlDatabase, QWidget *parent = nullptr);
    ~Odunc_Alma();
    void listele();

private slots:
    void on_tbl_uyeler_clicked(const QModelIndex &index);

    void on_tbl_kitaplar_clicked(const QModelIndex &index);

    void on_btn_oduncAl_clicked();

private:
    Ui::Odunc_Alma *ui;
    QSqlQuery *sorgu;
    QSqlQueryModel *model, *model1, *model2;
};

#endif // ODUNC_ALMA_H
