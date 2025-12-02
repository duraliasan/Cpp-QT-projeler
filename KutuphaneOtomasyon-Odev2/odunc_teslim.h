#ifndef ODUNC_TESLIM_H
#define ODUNC_TESLIM_H

#include <QDialog>
#include <QSql>
#include <QSqlDatabase>
#include <QSqlError>
#include <QMessageBox>
#include <QErrorMessage>
#include <QSqlQuery>
#include <QSqlQueryModel>

namespace Ui {
class Odunc_Teslim;
}

class Odunc_Teslim : public QDialog
{
    Q_OBJECT

public:
    explicit Odunc_Teslim(QSqlDatabase, QWidget *parent = nullptr);
    ~Odunc_Teslim();
    void listele();

private slots:
    void on_tbl_oduncAlinan_clicked(const QModelIndex &index);

    void on_btn_oduncVer_clicked();

private:
    Ui::Odunc_Teslim *ui;
    QSqlQuery *sorgu;
    QSqlQueryModel *model, *model1;
};

#endif // ODUNC_TESLIM_H
