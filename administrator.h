#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H
#include<place_an_order.h>
#include<showallorders.h>
#include <QDialog>
#include<cancelorder.h>

namespace Ui {
class Administrator;
}

class Administrator : public QDialog
{
    Q_OBJECT

public:
    explicit Administrator(QWidget *parent = nullptr);
    ~Administrator();

private slots:
    void on_placeanorder_clicked();

    void on_checkallorder_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_clicked();

private:
    Ui::Administrator *ui;
    place_an_order *order_place;
    showallorders *allorders;
    cancelorder *ordercancel;
};

#endif // ADMINISTRATOR_H
