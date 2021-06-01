#ifndef ADMINCONTROLER_H
#define ADMINCONTROLER_H

#include <QDialog>
#include <Delete.h>
namespace Ui {
class AdminControler;
}

class AdminControler : public QDialog
{
    Q_OBJECT
public:
    void refresh();
public:
    explicit AdminControler(QWidget *parent = nullptr);
    ~AdminControler();

private slots:
    void on_pushButton_Add_clicked();

    void on_pushButton_detele_clicked();

    void on_pushButton_Text_clicked();

    void on_pushButton_Xml_clicked();

    void on_pushButton_clicked();

    void on_pushButton_search_clicked();

    void on_pushButton_update_clicked();

private:
    Ui::AdminControler *ui;
    Delete * Ad;
};

#endif // ADMINCONTROLER_H
