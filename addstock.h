#ifndef ADDSTOCK_H
#define ADDSTOCK_H

#include <QDialog>

namespace Ui {
class AddStock;
}

class AddStock : public QDialog
{
    Q_OBJECT

public:
    explicit AddStock(QWidget *parent = nullptr);
    ~AddStock();

private slots:
    void on_pushButton_10_clicked();

    void on_pushButton_9_clicked();

private:
    Ui::AddStock *ui;
};

#endif // ADDSTOCK_H
