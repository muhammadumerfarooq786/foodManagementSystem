#include "deleteemployee.h"
#include "ui_deleteemployee.h"
#include<QFile>
#include<QTextStream>
#include<QMessageBox>
#include<QDebug>
#include<QStringList>


deleteemployee::deleteemployee(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::deleteemployee)
{
    ui->setupUi(this);
}

deleteemployee::~deleteemployee()
{
    delete ui;
}

void deleteemployee::on_pushButton_clicked()
{
    QFile file("C:/Users/UmerAslam/Documents/FoodyPi/employeedata.txt");

    if(!file.open(QFile::ReadOnly | QFile::Text)){
        QMessageBox::warning(this,"WARNING","File Not Open");
    }
    QTextStream in(&file);
    QString text=in.readAll();
    file.close();


    QString filedata="";
    QString employeedata="";
    QStringList deleteEmployee;
    QString employeeid=ui->lineEdit->text();
    deleteEmployee=text.split("#");
    for(int i=0;i<deleteEmployee.count()-1;i+=5){
        if(!(deleteEmployee.at(i).toLocal8Bit().constData()==employeeid)){
            for(int j=0;j<5;j++){

                  filedata+=deleteEmployee.at(i+j).toLocal8Bit().constData();
                  filedata+="#";
            }
        }
        if(deleteEmployee.at(i).toLocal8Bit().constData()==employeeid){
            for(int j=0;j<5;j++){

                  employeedata+=deleteEmployee.at(i+j).toLocal8Bit().constData();
                  employeedata+="\n";
            }
        }
    }

    ui->textEdit->setText(employeedata);

    QFile file1("C:/Users/UmerAslam/Documents/FoodyPi/employeedata.txt");

    if(!file1.open(QFile::WriteOnly | QFile::Text)){
        QMessageBox::warning(this,"WARNING","File Not Open");
    }
    QTextStream out(&file1);


    out<<filedata;


    file.flush();
    file.close();
    QMessageBox::information(this,"Successfull","Employee Deleted Successfully");




}

void deleteemployee::on_pushButton_2_clicked()
{
    hide();
}
