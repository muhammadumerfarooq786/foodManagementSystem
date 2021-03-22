#ifndef MANAGER_H
#define MANAGER_H
#include<hotel.h>
#include<employee.h>
#include<stock.h>

#include <QDialog>

namespace Ui {
class manager;
}

class manager : public QDialog
{
    Q_OBJECT

public:
    explicit manager(QWidget *parent = nullptr);
    ~manager();
    int sum=0;

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::manager *ui;
    employee *emp;
    stock *stoc;
    hotel *tim;
};

#endif // MANAGER_H
