#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <AdminControler.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_7_clicked()
{
    QApplication::exit();
}

void MainWindow::on_pushButton_2_clicked()
{
    openConnection();
    QString name = ui->nameTextBox->text();
    QString pw = ui->pwTextBox->text();

    QString sqlRequete = QString("select * from admin where name='%1' and password='%2'").arg(name).arg(pw);
   // qDebug()<<(sqlRequete);

    QSqlQuery sqliteQuery;
    sqliteQuery.prepare(sqlRequete);

    if(sqliteQuery.exec()){
        int Counter=0;
        while(sqliteQuery.next()){
            Counter++;
        }
        if(Counter==1){
         QMessageBox::information(this,"Connection To Account","Connection Successed ");
         closeConnection();
         this->hide();
         AdminControler Ad;
         Ad.setModal(1);
         Ad.exec();

        }
        else{
           QMessageBox::warning(this,"Connection To Account","Connection Failed ");
        }

    }
}

void MainWindow::on_pushButton_clicked()
{
    this->hide();
    AdminControler Ad;
    Ad.setModal(1);
    Ad.exec();
}
