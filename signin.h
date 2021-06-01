#ifndef SIGNIN_H
#define SIGNIN_H

#include <QDialog>

namespace Ui {
class SignIN;
}

class SignIN : public QDialog
{
    Q_OBJECT

public:
    explicit SignIN(QWidget *parent = nullptr);
    ~SignIN();

private:
    Ui::SignIN *ui;
};

#endif // SIGNIN_H
