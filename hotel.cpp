#include "hotel.h"
#include "ui_hotel.h"

hotel::hotel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::hotel)
{
    ui->setupUi(this);
}

hotel::~hotel()
{
    delete ui;
}

void hotel::on_pushButton_clicked()
{
   ui->label_3->setText( ui->comboBox->currentText()+"-----"+
    ui->comboBox_2->currentText());
}

void hotel::on_pushButton_2_clicked()
{
    hide();
}
