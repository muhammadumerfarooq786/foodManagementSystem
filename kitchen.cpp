#include "kitchen.h"
#include "ui_kitchen.h"

#include<QFile>
#include<QTextStream>
#include<QMessageBox>
#include<QDebug>
#include<QStringList>
kitchen::kitchen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::kitchen)
{
    ui->setupUi(this);
}

kitchen::~kitchen()
{
    delete ui;
}

void kitchen::on_pushButton_4_clicked()
{
    hide();
}

void kitchen::on_pushButton_2_clicked()
{


    compord= new completeorder(this);
    compord->show();
}

void kitchen::on_pushButton_clicked()
{
    QFile file("C:/Users/UmerAslam/Documents/FoodyPi/orderdata.txt");

    if(!file.open(QFile::ReadOnly | QFile::Text)){
        QMessageBox::warning(this,"WARNING","File Not Open");
    }
    QTextStream in(&file);
    QString text=in.readAll();
    file.close();

    QStringList orderdata;
    orderdata=text.split("#");

    ui->tableWidget->clear();
    QStringList header;

    header << "Order Id" << "Customer Name" << "Table Reserve" << "Status" <<
              "Menu Selected" << "Bill";
    ui->tableWidget->setHorizontalHeaderLabels(header);

    for(int i=0;i<(orderdata.count()-1)/6;i++){
             for(int j=0;j<6;j++){
                 ui->tableWidget->setItem(row,++column,new QTableWidgetItem(orderdata.at(j+increment).toLocal8Bit().constData()));
             }
             row++;
             column=-1;
             increment+=6;
    }
    increment=0;
    row=0;
    column=-1;
}
