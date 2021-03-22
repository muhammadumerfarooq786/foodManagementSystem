#include "addemployee.h"
#include "ui_addemployee.h"
#include<QFile>
#include<QTextStream>
#include<QMessageBox>

addemployee::addemployee(QWidget *parent):
    QDialog(parent),
    ui(new Ui::addemployee)
{
    ui->setupUi(this);
}

addemployee::~addemployee()
{
    delete ui;
}

void addemployee::on_pushButton_5_clicked()
{
    QString filename=QFileDialog::getOpenFileName(this,tr("Choose Image"),"",tr("Images (*.png *.jpg *.bmp *.gif *.jpeg)"));

    if(QString::compare(filename,QString())!=0){
        QImage image;
        bool check=image.load(filename);
        if(check){
            image=image.scaledToWidth(ui->label_3->width(),Qt::SmoothTransformation);
            ui->label_3->setPixmap(QPixmap::fromImage(image));
        }
        else{
            ui->label_3->setText("Invalid Command");

        }
    }
}

void addemployee::on_pushButton_4_clicked()
{
    if(ui->lineEdit->text().isEmpty() || ui->lineEdit_2->text().isEmpty() || ui->lineEdit_4->text().isEmpty() || ui->lineEdit_3->text().isEmpty()){

            QMessageBox::warning(this,"Invalid Entry","please fill the information!");

    }
    else if(!ui->lineEdit->text().toInt()){
        QMessageBox::warning(this,"Id","INVALID ID TYPE");
    }
    else if((!ui->lineEdit_4->text().toInt()) ){
         QMessageBox::warning(this,"Salary","Invalid Salary");
    }
    else if(!(ui->lineEdit_3->text().length()==11)){
        QMessageBox::warning(this,"Phone Number","Invalid Number");
    }

    else{


    QFile file("C:/Users/UmerAslam/Documents/FoodyPi/employeedata.txt");

    if(!file.open(QFile::Append | QFile::Text)){
        QMessageBox::warning(this,"WARNING","File Not Open");
    }
    QTextStream out(&file);


    QString text=ui->lineEdit->text()+"#"+ui->lineEdit_2->text()+"#"+ui->comboBox->currentText()+"#"+ui->lineEdit_4->text()+"#"+ui->lineEdit_3->text()+"#";
    out<<text;
    file.flush();
    file.close();
    QMessageBox::information(this,"Successfull","Data Inserted Successfully");

   }



}

/*void addemployee::on_pushButton_6_clicked()
{
    QFile file("C:/Users/UmerAslam/Documents/FoodyPi/employeedata.txt");

    if(!file.open(QFile::ReadOnly | QFile::Text)){
        QMessageBox::warning(this,"WARNING","File Not Open");
    }
    QTextStream in(&file);
    QString text=in.readAll();

    ui->lineEdit_2->setText(text);

    file.close();
}*/

void addemployee::on_pushButton_6_clicked()
{
    hide();
}
