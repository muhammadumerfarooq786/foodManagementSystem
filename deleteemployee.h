#ifndef DELETEEMPLOYEE_H
#define DELETEEMPLOYEE_H

#include <QDialog>
#include<QFileDialog>

namespace Ui {
class deleteemployee;
}

class deleteemployee : public QDialog
{
    Q_OBJECT

public:
    explicit deleteemployee(QWidget *parent = nullptr);
    ~deleteemployee();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::deleteemployee *ui;
};

#endif // DELETEEMPLOYEE_H
