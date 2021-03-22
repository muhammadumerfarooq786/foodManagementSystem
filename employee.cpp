#include "employee.h"
#include "ui_employee.h"
#include<QPixmap>
#include<QMessageBox>
#include<QFile>
#include<QTextStream>
#include<QDebug>
#include<QStringList>

employee::employee(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::employee)
{
    ui->setupUi(this);
    QPixmap pic("C:/Users/UmerAslam/Desktop/waiter.png");
    int w=ui->label->width();
    int h=ui->label->height();
    ui->label->setPixmap(pic.scaled(w,h,Qt::KeepAspectRatio));

    QPixmap pixmap("C:/Users/UmerAslam/Desktop/waiter.png");
    QIcon ButtonIcon(pixmap);
    QPixmap add("C:/Users/UmerAslam/Desktop/add_employee.png");
    QIcon addemp(add);
    QPixmap deleted("C:/Users/UmerAslam/Desktop/delete_employee.png");
    QIcon deleteemp(deleted);
    ui->pushButton->setIcon(ButtonIcon);
    ui->pushButton->setIconSize(pixmap.rect().size());
    ui->pushButton->setIconSize(QSize(150, 75));

    ui->pushButton_2->setIcon(ButtonIcon);
    ui->pushButton_2->setIconSize(pixmap.rect().size());
    ui->pushButton_2->setIconSize(QSize(150, 75));


    ui->pushButton_3->setIcon(ButtonIcon);
    ui->pushButton_3->setIconSize(pixmap.rect().size());
    ui->pushButton_3->setIconSize(QSize(150, 75));


    ui->pushButton_4->setIcon(ButtonIcon);
    ui->pushButton_4->setIconSize(pixmap.rect().size());
    ui->pushButton_4->setIconSize(QSize(150, 75));


    ui->pushButton_7->setIcon(ButtonIcon);
    ui->pushButton_7->setIconSize(pixmap.rect().size());
    ui->pushButton_7->setIconSize(QSize(150, 75));

    ui->pushButton_8->setIcon(ButtonIcon);
    ui->pushButton_8->setIconSize(pixmap.rect().size());
    ui->pushButton_8->setIconSize(QSize(150, 75));

    ui->pushButton_9->setIcon(ButtonIcon);
    ui->pushButton_9->setIconSize(pixmap.rect().size());
    ui->pushButton_9->setIconSize(QSize(150, 75));

    ui->pushButton_10->setIcon(ButtonIcon);
    ui->pushButton_10->setIconSize(pixmap.rect().size());
    ui->pushButton_10->setIconSize(QSize(150, 75));


    ui->pushButton_5->setIcon(addemp);
    ui->pushButton_5->setIconSize(pixmap.rect().size());
    ui->pushButton_5->setIconSize(QSize(150, 75));


    ui->pushButton_6->setIcon(deleteemp);
    ui->pushButton_6->setIconSize(pixmap.rect().size());
    ui->pushButton_6->setIconSize(QSize(150, 75));



}

employee::~employee()
{
    delete ui;
}

void employee::on_pushButton_clicked()
{

}

void employee::on_pushButton_2_clicked()
{

}

void employee::on_pushButton_3_clicked()
{

}

void employee::on_pushButton_5_clicked()
{

    addemp=new addemployee(this);
    addemp->show();
}

void employee::on_pushButton_6_clicked()
{

    delemp=new deleteemployee(this);
    delemp->show();
}

void employee::on_pushButton_4_clicked()
{

}

void employee::on_pushButton_11_clicked()
{
    QFile file("C:/Users/UmerAslam/Documents/FoodyPi/employeedata.txt");

    if(!file.open(QFile::ReadOnly | QFile::Text)){
        QMessageBox::warning(this,"WARNING","File Not Open");
    }
    QTextStream in(&file);
    QStringList employeedata;
    QString text=in.readAll();

    int increment=0;
    QString element;
    ui->label_4->setText("");
    ui->label_5->setText("");
    ui->label_6->setText("");
    ui->label_7->setText("");
    ui->label_8->setText("");
    ui->label_9->setText("");
    ui->label_10->setText("");
    ui->label_11->setText("");
    employeedata=text.split("#");
    for(int i=0;i<(employeedata.count()-1)/5;i++){
             for(int j=0;j<5;j++){
                 element+=employeedata.at(j+increment).toLocal8Bit().constData();
                 element+="\n";
             }
             if(increment==0){
             ui->label_4->setText(element);
             }
             if(increment==5){
                 ui->label_5->setText(element);
             }
             if(increment==10){
                 ui->label_6->setText(element);
             }
             if(increment==15){
                 ui->label_7->setText(element);
             }
             if(increment==20){
                 ui->label_8->setText(element);
             }
             if(increment==25){
                 ui->label_9->setText(element);
             }
             if(increment==30){
                 ui->label_10->setText(element);
             }
             if(increment==35){
                 ui->label_11->setText(element);
             }

             increment+=5;
             element="";
    }





    file.close();
}

void employee::on_pushButton_12_clicked()
{
    hide();
}
