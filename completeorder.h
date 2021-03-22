#ifndef COMPLETEORDER_H
#define COMPLETEORDER_H

#include <QDialog>

namespace Ui {
class completeorder;
}

class completeorder : public QDialog
{
    Q_OBJECT

public:
    explicit completeorder(QWidget *parent = nullptr);
    ~completeorder();


private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::completeorder *ui;
};

#endif // COMPLETEORDER_H
