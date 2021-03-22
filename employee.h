#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <QDialog>
#include<addemployee.h>
#include<QFileDialog>
#include<deleteemployee.h>

namespace Ui {
class employee;
}

class employee : public QDialog
{
    Q_OBJECT

public:
    explicit employee(QWidget *parent = nullptr);
    ~employee();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_12_clicked();

private:
    Ui::employee *ui;
    addemployee *addemp;
    deleteemployee *delemp;
};

#endif // EMPLOYEE_H
