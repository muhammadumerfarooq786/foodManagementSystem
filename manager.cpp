#include "manager.h"
#include "ui_manager.h"
#include<employee.h>
#include<QPixmap>
#include<QMessageBox>
#include<QFile>
#include<QTextStream>
#include<QDebug>
#include<QStringList>
manager::manager(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::manager)
{
    ui->setupUi(this);

    QPixmap pic1("C:/Users/UmerAslam/Desktop/stock/worker.png");


    int w=ui->label_3->width();
    int h=ui->label_3->height();
    ui->label_3->setPixmap(pic1.scaled(w,h,Qt::KeepAspectRatio));
    ui->label_4->setText("FoodyPi Mission Statement\nEvery customer says, \nI'll be back! We are the employer of\nchoice offering team members\nopportunities for growth, advancement,\nand rewarding careers in a fun,\n safe working environment.We\nare accountable for profitability\nin everything we\n do, providing our shareholders with value growth.");
}

manager::~manager()
{
    delete ui;
}

void manager::on_pushButton_clicked()
{

    emp =new employee(this);
    emp->show();

}

void manager::on_pushButton_2_clicked()
{

    stoc =new stock(this);
    stoc->show();
}

void manager::on_pushButton_4_clicked()
{
    QFile file1("C:/Users/UmerAslam/Documents/FoodyPi/sales.txt");

    if(!file1.open(QFile::ReadOnly | QFile::Text)){
        QMessageBox::warning(this,"WARNING","No Earning");
    }
    QTextStream in(&file1);
    QString text=in.readAll();
    file1.close();
    QStringList orderdata;
    orderdata=text.split("#");
    for(int i=0;i<orderdata.count()-1;i++){

        QString data=orderdata.at(i).toLocal8Bit().constData();
        int val=data.toInt();
         sum=sum+val;
    }

    QString s = QString::number(sum);
    ui->label_6->setText(s);
}

void manager::on_pushButton_5_clicked()
{
    hide();
}

void manager::on_pushButton_3_clicked()
{
    tim=new hotel(this);
    tim->show();
}
