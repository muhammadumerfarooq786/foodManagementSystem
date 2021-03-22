#ifndef ADDEMPLOYEE_H
#define ADDEMPLOYEE_H

#include <QDialog>
#include<QFileDialog>

namespace Ui {
class addemployee;
}

class addemployee : public QDialog
{
    Q_OBJECT

public:
    explicit addemployee(QWidget *parent = nullptr);
    ~addemployee();

private slots:
    void on_pushButton_5_clicked();

    void on_pushButton_4_clicked();



    void on_pushButton_6_clicked();

private:
    Ui::addemployee *ui;
};

#endif // ADDEMPLOYEE_H
