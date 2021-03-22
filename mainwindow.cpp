#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMessageBox>
#include<QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);




    QPixmap pic("C:/Users/UmerAslam/Desktop/burger.jpg");
    int w=ui->label_5->width();
    int h=ui->label_5->height();
    ui->label_5->setPixmap(pic.scaled(w,h,Qt::KeepAspectRatio));

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{

   // rep.exec();
   //
    QString username=ui->username->text();
    QString password=ui->password->text();
    QString position=ui->comboBox->currentText();

    if(username=="receptionist" && password=="123" && position=="Receptionist"  ){

        adm=new Administrator(this);
        adm->show();

    }
    else if(username=="manager" && password=="456" && position=="Manager"){

        man =new manager(this);
        man->show();
    }
    //  receptionist rep;
      //rep.setModal(true);
    else if(username=="kitchen" && password=="789" && position=="Kitchen"){

        kit=new kitchen(this);
        kit->show();
    }
    else{
        QMessageBox::warning(this,"Validation","Invalid Username Or Password");
    }


}


