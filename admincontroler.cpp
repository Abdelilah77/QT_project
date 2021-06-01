#include "admincontroler.h"
#include "ui_admincontroler.h"
#include<QtXml>
#include <MainWindow.h>



void AdminControler::refresh(){
    MainWindow mainP ;
    mainP.openConnection();
    QSqlQueryModel *Model = new QSqlQueryModel();
    QSqlQuery *Query = new QSqlQuery(mainP.db);
    QString sqlRequete = QString("select * from productt" );
    Query->prepare(sqlRequete);
    Query->exec();
    Model->setQuery(*Query);
    ui->tableView->setModel(Model);
    mainP.closeConnection();

}

AdminControler::AdminControler(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminControler)
{
    ui->setupUi(this);
    refresh();
}

AdminControler::~AdminControler()
{
    delete ui;

}

void AdminControler::on_pushButton_Add_clicked()
{
    MainWindow mainP ;
    mainP.openConnection();
    QString name = ui->lineEdit_Name->text();
    QString price = ui->lineEdit_Price->text();
    QString qte = ui->lineEdit_Qte->text();

    QString sqlRequete = QString("insert into productt values(null,'%1',%2,%3)").arg(name).arg(price).arg(qte);
   // qDebug()<<(sqlRequete);

    QSqlQuery sqliteQuery;
    sqliteQuery.prepare(sqlRequete);

    sqliteQuery.exec();
    mainP.closeConnection();
    refresh();
    ui->lineEdit_Name->setText("");
     ui->lineEdit_Price->setText("");
    ui->lineEdit_Qte->setText("");
}

void AdminControler::on_pushButton_detele_clicked()
{
    Delete Ad;
    Ad.setModal(1);
    Ad.exec();

}

void AdminControler::on_pushButton_Text_clicked()
{

    QString filename="Data.txt";
    QFile file( filename );

    MainWindow mainP ;
    mainP.openConnection();
   if (file.open(QIODevice::ReadWrite) )
   {
    QTextStream stream( &file );
    QSqlQuery Query ;
    QString sqlRequete = QString("select * from productt" );
    Query.prepare(sqlRequete);
    Query.exec();
    int counter =1;
    while(Query.next())
      {

           QSqlRecord localRecord = Query.record();
              stream<<"Product " <<counter<<"\n";
                for(int x=0; x < localRecord.count(); x++)
                {
                        stream << localRecord.fieldName(x)<<":"<<localRecord.value(x).toString()<<"\n";
                }
           counter++;
          }

    }
    mainP.closeConnection();



}

void AdminControler::on_pushButton_Xml_clicked()
{
    QString filename="myXml.xml";
    QFile file( filename );

    MainWindow mainP ;
    mainP.openConnection();

    QTextStream stream( &file );
    QSqlQuery Query ;
    QString sqlRequete = QString("select * from productt" );
    Query.prepare(sqlRequete);
    Query.exec();
    int counter =1;
    //xml
    QDomDocument document;
     //root element
    QDomElement root = document.createElement("Products");

    while(Query.next())
      {
         QDomElement Product = document.createElement("Product");
           QSqlRecord localRecord = Query.record();


             Product.setAttribute("id",QString::number(counter));
                for(int x=0; x < localRecord.count(); x++)
                {
                    QDomElement Elm = document.createElement(localRecord.fieldName(x));
                    QDomText doc = document.createTextNode(localRecord.value(x).toString());
                    Elm.appendChild(doc);
                    Product.appendChild(Elm);
                }
           root.appendChild(Product);
           counter++;

          }
    document.appendChild(root);

    if (file.open(QIODevice::ReadWrite) )
    {
        stream <<document.toString() ;
        QMessageBox::information(this,"Xml","Save Successed ");
    }
    mainP.closeConnection();
}

void AdminControler::on_pushButton_clicked()
{
     refresh();
}

void AdminControler::on_pushButton_search_clicked()
{
    MainWindow mainP ;
    mainP.openConnection();
    QString id = ui->lineEdit_5->text();

    QString sqlRequete = QString("select * from productt where id =%1").arg(id);
    qDebug()<<(sqlRequete);

    QSqlQuery sqliteQuery;
    sqliteQuery.prepare(sqlRequete);

    sqliteQuery.exec();
    int counter = 0;
    if(sqliteQuery.next()){counter++;}
    if(counter==1){
    QSqlRecord localRecord = sqliteQuery.record();
    ui->lineEdit->setText(localRecord.value(0).toString());
    ui->lineEdit_Name->setText(localRecord.value(1).toString());
    ui->lineEdit_Price->setText(localRecord.value(2).toString());
    ui->lineEdit_Qte->setText(localRecord.value(3).toString());

}
    else{

        QMessageBox::information(this,"Search","Product not Existe");
    }



    mainP.closeConnection();
    refresh();
}

void AdminControler::on_pushButton_update_clicked()
{
    MainWindow mainP ;
    mainP.openConnection();
    QString id = ui->lineEdit->text();


    if(id==""){
        QMessageBox::information(this,"Search","Please Search first for the id You want to update");
    }
    else{
        QString name = ui->lineEdit_Name->text();
        QString price = ui->lineEdit_Price->text();
        QString qte = ui->lineEdit_Qte->text();
        QString sqlRequete = QString("update productt set nameP='%1',prix=%2,qte=%3 where id=%4").arg(name).arg(price).arg(qte).arg(id);
        qDebug()<<(sqlRequete);

        QSqlQuery sqliteQuery;
        sqliteQuery.prepare(sqlRequete);

        sqliteQuery.exec();



    }

    mainP.closeConnection();
    refresh();
}
