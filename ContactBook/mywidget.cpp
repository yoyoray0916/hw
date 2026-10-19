#include "mywidget.h"
#include "ui_mywidget.h"

#include <QFile>
#include <QDebug>


QString mFilename = "C:/text/myfile.txt";

void Write(QString fileName,QString str)
{
    QFile mFile(fileName);
    if(!mFile.open(QFile::WriteOnly | QFile::Text))
    {
        qDebug()<<"Open File failed!";
        return;
    }

    QTextStream out(&mFile);
    out<<str;
    mFile.flush();
    mFile.close();
}

MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MyWidget)
{
    ui->setupUi(this);
    ui->tableWidget->setColumnCount(4);
    QStringList colTotal;
    colTotal<<"學號"<<"班級"<<"姓名"<<"電話";
    ui->tableWidget->setHorizontalHeaderLabels(colTotal);
}

MyWidget::~MyWidget()
{
    delete ui;
}

void MyWidget::on_pushButton_clicked()
{
    QTableWidgetItem *col1, *col2, *col3, *col4;
    col1=new QTableWidgetItem(ui->lineEdit->text());
    col2=new QTableWidgetItem(ui->lineEdit_2->text());
    col3=new QTableWidgetItem(ui->lineEdit_3->text());
    col4=new QTableWidgetItem(ui->lineEdit_4->text());
    int row = ui->tableWidget->rowCount();
    qDebug()<<row;
    ui->tableWidget->insertRow(row);
    ui->tableWidget->setItem(row,0,col1);
    ui->tableWidget->setItem(row,1,col2);
    ui->tableWidget->setItem(row,2,col3);
    ui->tableWidget->setItem(row,3,col4);
}


void MyWidget::on_pushButton_2_clicked()
{
    QString saveFile="";

    for(int i=0;i<ui->tableWidget->rowCount();i++){
        for(int j=0;j<ui->tableWidget->columnCount();j++){
            saveFile+=ui->tableWidget->item(i,j)->text()+",";
        }
        saveFile+="\n";
    }
    Write(mFilename,saveFile);
}

