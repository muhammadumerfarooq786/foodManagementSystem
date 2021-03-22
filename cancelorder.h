#ifndef CANCELORDER_H
#define CANCELORDER_H

#include <QDialog>
#include<QFileDialog>

namespace Ui {
class cancelorder;
}

class cancelorder : public QDialog
{
    Q_OBJECT

public:
    explicit cancelorder(QWidget *parent = nullptr);
    ~cancelorder();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::cancelorder *ui;
};

#endif // CANCELORDER_H
