#ifndef KITCHEN_H
#define KITCHEN_H

#include<completeorder.h>
#include <QDialog>


namespace Ui {
class kitchen;
}

class kitchen : public QDialog
{
    Q_OBJECT

public:
    explicit kitchen(QWidget *parent = nullptr);
    ~kitchen();
    int row=0;
    int column=-1;
    int increment=0;

private slots:
    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::kitchen *ui;
    completeorder *compord;
};

#endif // KITCHEN_H
