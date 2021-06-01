#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QtSql>
#include<QtDebug>
#include<QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    QSqlDatabase db;
    bool openConnection(){
        db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("../ProjectCppStock/database/product.db");
        if (!db.open()){
            qDebug()<<("Failed To open database");
            return false;
        }
         qDebug()<<("Successed");
        return true;
    }
    void closeConnection(){
        db.close();
        db.removeDatabase(QSqlDatabase::defaultConnection);
    }
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_7_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
