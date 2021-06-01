#include "delete.h"
#include "ui_delete.h"

#include <AdminControler.h>
#include <MainWindow.h>

Delete::Delete(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Delete)
{
    ui->setupUi(this);
}

Delete::~Delete()
{
    delete ui;
}

void Delete::on_pushButton_2_clicked()
{
    MainWindow mainP ;
    AdminControler ref;
    mainP.openConnection();
    QString id = ui->lineEdit->text();


    QString sqlRequete = QString("delete from productt where id = %1").arg(id);
   // qDebug()<<(sqlRequete);

    QSqlQuery sqliteQuery;
    sqliteQuery.prepare(sqlRequete);

    sqliteQuery.exec();
    mainP.closeConnection();
    ref.refresh();

}


