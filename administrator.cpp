#include "administrator.h"
#include "ui_administrator.h"
#include<QPixmap>


Administrator::Administrator(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Administrator)
{
    ui->setupUi(this);
    QPixmap pic("C:/Users/UmerAslam/Desktop/stock/worker.png");

    int w=ui->label_3->width();
    int h=ui->label_3->height();
    ui->label_3->setPixmap(pic.scaled(w,h,Qt::KeepAspectRatio));
    ui->label_4->setText("FoodyPi Mission Statement\nEvery customer says, \nI'll be back! We are the employer of\nchoice offering team members\nopportunities for growth, advancement,\nand rewarding careers in a fun,\n safe working environment.We\nare accountable for profitability\nin everything we\n do, providing our shareholders with\n value growth.");

}

Administrator::~Administrator()
{
    delete ui;
}

void Administrator::on_placeanorder_clicked()
{

    order_place=new place_an_order(this);
    order_place->show();
}

void Administrator::on_checkallorder_clicked()
{

    allorders=new showallorders(this);
    allorders->show();
}

void Administrator::on_pushButton_4_clicked()
{
    ordercancel =new cancelorder(this);
    ordercancel->show();
}

void Administrator::on_pushButton_clicked()
{
    hide();
}
