#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_txtMetin_textChanged();

    void on_btnTemizle_clicked();

    void on_btnKaydet_clicked();

    void on_btnOku_clicked();

private:
    Ui::Dialog *ui;
    void oku_();
    void kaydet_();
    bool m_kaydedilmi;
};
#endif // DIALOG_H
