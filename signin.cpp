#include "signin.h"
#include "ui_signin.h"

SignIN::SignIN(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SignIN)
{
    ui->setupUi(this);
}

SignIN::~SignIN()
{
    delete ui;
}
