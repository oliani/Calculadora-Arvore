#include "mainwindow.h"
#include "ui_mainwindow.h"

#include<QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton_zero, SIGNAL(released()), this,SLOT(digit_pressed()));
    connect(ui->pushButton_one, SIGNAL(released()), this,SLOT(digit_pressed()));
    connect(ui->pushButton_two, SIGNAL(released()), this,SLOT(digit_pressed()));
    connect(ui->pushButton_three, SIGNAL(released()), this,SLOT(digit_pressed()));
    connect(ui->pushButton_four, SIGNAL(released()), this,SLOT(digit_pressed()));
    connect(ui->pushButton_five, SIGNAL(released()), this,SLOT(digit_pressed()));
    connect(ui->pushButton_six, SIGNAL(released()), this,SLOT(digit_pressed()));
    connect(ui->pushButton_seven, SIGNAL(released()), this,SLOT(digit_pressed()));
    connect(ui->pushButton_eight, SIGNAL(released()), this,SLOT(digit_pressed()));
    connect(ui->pushButton_nine, SIGNAL(released()), this,SLOT(digit_pressed()));

    connect(ui->pushButton_PlusSubtact, SIGNAL(released()), this,SLOT(unary_operation_pressed()));
    connect(ui->pushButton_percentage, SIGNAL(released()), this,SLOT(unary_operation_pressed()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digit_pressed()
{
    QPushButton * button = (QPushButton*)sender();

    double labelNumber;
    QString newLabel;

    labelNumber = (ui->label_result->text() + button->text()).toDouble();

    newLabel = QString::number(labelNumber,'g',15);

    ui->label_result->setText(newLabel);


}



void MainWindow::on_pushButton_point_released()
{
    ui->label_result->setText(ui->label_result->text()+".");
}

void MainWindow::unary_operation_pressed()
{
    QPushButton * button = (QPushButton*) sender();
    double labelNumber;
    QString newLabel;

    if (button->text() == "+/-")
    {
        labelNumber = ui->label_result->text().toDouble();
        labelNumber = labelNumber * -1;
        newLabel = QString::number(labelNumber,'g',15);
        ui->label_result->setText(newLabel);
    }

    if (button->text() == "%")
    {
        labelNumber = ui->label_result->text().toDouble();
        labelNumber = labelNumber * 0.01;
        newLabel = QString::number(labelNumber,'g',15);
        ui->label_result->setText(newLabel);
    }
}

void MainWindow::on__Clear_released()
{

}

void MainWindow::binary_operation_pressed()
{
    QPushButton * button = (QPushButton*) sender();

}
