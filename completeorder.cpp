#include "completeorder.h"
#include "ui_completeorder.h"
#include<QFile>
#include<QTextStream>
#include<QMessageBox>
#include<QDebug>
#include<QStringList>

completeorder::completeorder(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::completeorder)
{
    ui->setupUi(this);
}

completeorder::~completeorder()
{
    delete ui;
}

void completeorder::on_pushButton_clicked()
{
    QFile file("C:/Users/UmerAslam/Documents/FoodyPi/orderdata.txt");

    if(!file.open(QFile::ReadOnly | QFile::Text)){
        QMessageBox::warning(this,"WARNING","No Order Found");
    }
    QTextStream in(&file);
    QString text=in.readAll();
    file.close();


    QString filedata="";
    QString employeedata="";
    QStringList deleteEmployee;
    QString employeeid=ui->lineEdit->text();
    deleteEmployee=text.split("#");
    for(int i=0;i<deleteEmployee.count()-1;i+=6){
        if(!(deleteEmployee.at(i).toLocal8Bit().constData()==employeeid)){
            for(int j=0;j<6;j++){
                  filedata+=deleteEmployee.at(i+j).toLocal8Bit().constData();
                  filedata+="#";
            }
        }
        if(deleteEmployee.at(i).toLocal8Bit().constData()==employeeid){
            for(int j=0;j<6;j++){

                  employeedata+=deleteEmployee.at(i+j).toLocal8Bit().constData();
                  employeedata+="\n";
                  if(j==5){
                      QFile file1("C:/Users/UmerAslam/Documents/FoodyPi/sales.txt");

                      if(!file1.open(QFile::Append | QFile::Text)){
                          QMessageBox::warning(this,"WARNING","No Order Place");
                      }
                      QTextStream out(&file1);


                      out<<deleteEmployee.at(i+j).toLocal8Bit().constData();
                      out<<"#";


                      file1.flush();
                      file1.close();

                  }
            }
        }
    }



    ui->textEdit->setText(employeedata);

    QFile file1("C:/Users/UmerAslam/Documents/FoodyPi/orderdata.txt");

    if(!file1.open(QFile::WriteOnly | QFile::Text)){
        QMessageBox::warning(this,"WARNING","No Order Place");
    }
    QTextStream out(&file1);


    out<<filedata;


    file1.flush();
    file1.close();
    QMessageBox::information(this,"Successfull","Order Completed Successfully");
}



void completeorder::on_pushButton_2_clicked()
{
    hide();
}
