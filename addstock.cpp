#include "addstock.h"
#include "ui_addstock.h"
#include<QMessageBox>
#include<QFile>
#include<QTextStream>
#include<QDebug>
#include<QStringList>

AddStock::AddStock(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddStock)
{
    ui->setupUi(this);
    ui->lineEdit->setText("0");
    ui->lineEdit_2->setText("0");
    ui->lineEdit_3->setText("0");
    ui->lineEdit_4->setText("0");
    ui->lineEdit_5->setText("0");
    ui->lineEdit_6->setText("0");
    ui->lineEdit_7->setText("0");
    ui->lineEdit_8->setText("0");



}

AddStock::~AddStock()
{
    delete ui;
}

void AddStock::on_pushButton_10_clicked()
{
    hide();
}

void AddStock::on_pushButton_9_clicked()
{
    if((ui->lineEdit->text().toInt() || ui->lineEdit->text()=="0")  && (ui->lineEdit_2->text().toInt() || ui->lineEdit_2->text()=="0") && (ui->lineEdit_3->text().toInt() || ui->lineEdit_3->text()=="0") &&
    (ui->lineEdit_4->text().toInt() || ui->lineEdit_4->text()=="0")  && (ui->lineEdit_5->text().toInt() || ui->lineEdit_5->text()=="0") && (ui->lineEdit_6->text().toInt() || ui->lineEdit_6->text()=="0") &&
    (ui->lineEdit_7->text().toInt() || ui->lineEdit_7->text()=="0")  && (ui->lineEdit_8->text().toInt() || ui->lineEdit_8->text()=="0")){
         if(ui->lineEdit->text().toInt()<0 || ui->lineEdit_2->text().toInt()<0 || ui->lineEdit_3->text().toInt()<0 || ui->lineEdit_4->text().toInt()<0 || ui->lineEdit_5->text().toInt()<0
                  || ui->lineEdit_6->text().toInt()<0 || ui->lineEdit_7->text().toInt()<0 || ui->lineEdit_8->text().toInt()<0){
             QMessageBox::warning(this,"Invalid Entries","Negative Values Are Not Allowed");
         }
         else{
             
             QFile file("C:/Users/UmerAslam/Documents/FoodyPi/addstock.txt");


             if(!file.open(QFile::ReadOnly | QFile::Text)){
                 QMessageBox::warning(this,"WARNING","Failure");
             }
             QTextStream in(&file);
             QString text=in.readAll();
             file.close();


             QString ind_data="";
             QString com_data="";
             QStringList sum_data;

             sum_data=text.split("#");
             //QString s=QString::number(sum_data.count());



             int num=0;
             int takesum=0;
             for(int i=0;i<8;i++){
                 ind_data=sum_data.at(i).toLocal8Bit().constData();
                 if(ind_data=="0"){
                    if(i==0){
                        com_data+=ui->lineEdit->text();
                        com_data+="#";
                    }
                    else if(i==1){
                        com_data+=ui->lineEdit_2->text();
                        com_data+="#";

                    }
                    else if(i==2){
                        com_data+=ui->lineEdit_3->text();
                        com_data+="#";
                    }
                    else if(i==3){
                        com_data+=ui->lineEdit_4->text();
                        com_data+="#";
                    }
                    else if(i==4){
                        com_data+=ui->lineEdit_5->text();
                        com_data+="#";
                    }
                    else if(i==5){
                        com_data+=ui->lineEdit_6->text();
                        com_data+="#";
                    }
                    else if(i==6){
                        com_data+=ui->lineEdit_7->text();
                        com_data+="#";
                    }
                    else if(i==7){
                        com_data+=ui->lineEdit_8->text();
                        com_data+="#";
                    }

                 }
                 else{
                     num=ind_data.toInt();

                     if(i==0){
                         int numbered=ui->lineEdit->text().toInt();
                         takesum=numbered+num;
                         QString st = QString::number(takesum);
                         com_data+=st;
                         com_data+="#";
                     }
                     else if(i==1){
                         int numbered=ui->lineEdit_2->text().toInt();
                         takesum=numbered+num;
                         QString st = QString::number(takesum);
                         com_data+=st;
                         com_data+="#";

                     }
                     else if(i==2){
                         int numbered=ui->lineEdit_3->text().toInt();
                         takesum=numbered+num;
                         QString st = QString::number(takesum);
                         com_data+=st;
                         com_data+="#";
                     }
                     else if(i==3){
                         int numbered=ui->lineEdit_4->text().toInt();
                         takesum=numbered+num;
                         QString st = QString::number(takesum);
                         com_data+=st;
                         com_data+="#";
                     }
                     else if(i==4){
                         int numbered=ui->lineEdit_5->text().toInt();
                         takesum=numbered+num;
                         QString st = QString::number(takesum);
                         com_data+=st;
                         com_data+="#";
                     }
                     else if(i==5){
                         int numbered=ui->lineEdit_6->text().toInt();
                         takesum=numbered+num;
                         QString st = QString::number(takesum);
                         com_data+=st;
                         com_data+="#";
                     }
                     else if(i==6){
                         int numbered=ui->lineEdit_7->text().toInt();
                         takesum=numbered+num;
                         QString st = QString::number(takesum);
                         com_data+=st;
                         com_data+="#";
                     }
                     else if(i==7){
                         int numbered=ui->lineEdit_8->text().toInt();
                         takesum=numbered+num;
                         QString st = QString::number(takesum);
                         com_data+=st;
                         com_data+="#";
                     }


                 }

             }


             QFile file1("C:/Users/UmerAslam/Documents/FoodyPi/addstock.txt");


             if(!file1.open(QFile::WriteOnly | QFile::Text)){
                 QMessageBox::warning(this,"WARNING","Failure");
             }
             QTextStream out(&file1);
             out<<com_data;
             file1.flush();
             file1.close();




         }

    }
    else{

      QMessageBox::warning(this,"Invalid Entries","Some Entries Contain Invalid input");

    }


}
