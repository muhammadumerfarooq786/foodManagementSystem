#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include<manager.h>
#include<kitchen.h>
#include<administrator.h>
#include<QtSql>
#include<QSqlDatabase>
#include<QDebug>
#include<QFileInfo>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();



private:
    Ui::MainWindow *ui;

    Administrator *adm;
    manager *man;
    kitchen *kit;
};
#endif // MAINWINDOW_H
