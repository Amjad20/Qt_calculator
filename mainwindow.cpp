#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QObject>
#include <QDebug>
#include <QKeyEvent>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //connect(ui->pushButton_0, &QPushButton::clicked, ui->label, MainWindow::on_pushButton_0_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_0_clicked()
{
    if(waitingForOperand)
    {
        ui->label->setText("0");
        waitingForOperand = false;
    }

    if(ui->label->text() != "0")
    {
        ui->label->setText(ui->label->text() + "0");
    }
}


void MainWindow::on_pushButton_1_clicked()
{
    if(waitingForOperand)
    {
        ui->label->clear();
        waitingForOperand = false;
    }

    if(ui->label->text() == "0")
    {
        ui->label->setText("1");
    }
    else
    {
        ui->label->setText(ui->label->text() + "1");
    }
}


void MainWindow::on_pushButton_2_clicked()
{
    if(waitingForOperand)
    {
        ui->label->clear();
        waitingForOperand = false;
    }

    if(ui->label->text() == "0")
    {
        ui->label->setText("2");
    }
    else
    {
        ui->label->setText(ui->label->text() + "2");
    }
}


void MainWindow::on_pushButton_3_clicked()
{
    if(waitingForOperand)
    {
        ui->label->clear();
        waitingForOperand = false;
    }

    if(ui->label->text() == "0")
    {
        ui->label->setText("3");
    }
    else
    {
        ui->label->setText(ui->label->text() + "3");
    }
}


void MainWindow::on_pushButton_4_clicked()
{
    if(waitingForOperand)
    {
        ui->label->clear();
        waitingForOperand = false;
    }

    if(ui->label->text() == "0")
    {
        ui->label->setText("4");
    }
    else
    {
        ui->label->setText(ui->label->text() + "4");
    }
}


void MainWindow::on_pushButton_5_clicked()
{
    if(waitingForOperand)
    {
        ui->label->clear();
        waitingForOperand = false;
    }

    if(ui->label->text() == "0")
    {
        ui->label->setText("5");
    }
    else
    {
        ui->label->setText(ui->label->text() + "5");
    }
}


void MainWindow::on_pushButton_6_clicked()
{
    if(waitingForOperand)
    {
        ui->label->clear();
        waitingForOperand = false;
    }

    if(ui->label->text() == "0")
    {
        ui->label->setText("6");
    }
    else
    {
        ui->label->setText(ui->label->text() + "6");
    }
}


void MainWindow::on_pushButton_7_clicked()
{
    if(waitingForOperand)
    {
        ui->label->clear();
        waitingForOperand = false;
    }

    if(ui->label->text() == "0")
    {
        ui->label->setText("7");
    }
    else
    {
        ui->label->setText(ui->label->text() + "7");
    }
}


void MainWindow::on_pushButton_8_clicked()
{
    if(waitingForOperand)
    {
        ui->label->clear();
        waitingForOperand = false;
    }

    if(ui->label->text() == "0")
    {
        ui->label->setText("8");
    }
    else
    {
        ui->label->setText(ui->label->text() + "8");
    }
}


void MainWindow::on_pushButton_9_clicked()
{
    if(waitingForOperand)
    {
        ui->label->clear();
        waitingForOperand = false;
    }

    if(ui->label->text() == "0")
    {
        ui->label->setText("9");
    }
    else
    {
        ui->label->setText(ui->label->text() + "9");
    }
}


void MainWindow::on_pushButton_decimal_clicked()
{
    if(waitingForOperand)
    {
        ui->label->setText("0");
        waitingForOperand = false;
    }

    if(!ui->label->text().contains('.'))
        ui->label->setText(ui->label->text() + tr("."));
}


void MainWindow::on_pushButton_clear_clicked()
{
    ui->label->setText("0");
    last_operand = 0;
    continue_operation = false;
}


void MainWindow::on_pushButton_plusminus_clicked()
{
    if(!ui->label->text().contains('-') && ui->label->text() != "0")
        ui->label->setText(ui->label->text().prepend("-"));
    else
        ui->label->setText(ui->label->text().remove("-"));

    last_operand = ui->label->text().toDouble();
}


void MainWindow::on_pushButton_percent_clicked()
{
    double currentValue = ui->label->text().toDouble();
    double percentageValue = currentValue / 100.0;
    ui->label->setText(QString::number(percentageValue));
}


void MainWindow::on_pushButton_add_clicked()
{
    double result = 0;
    double operand = ui->label->text().toDouble();
    if(!waitingForOperand && continue_operation == true)
    {
        if(operation_called == add)
            result = last_operand + operand;
        if(operation_called == sub)
            result = last_operand - operand;
        if(operation_called == mul)
            result = last_operand * operand;
        if(operation_called == div)
            result = last_operand / operand;
        ui->label->setText(QString::number(result));
    }

    last_operand = ui->label->text().toDouble();
    waitingForOperand = true;
    continue_operation = true;
    operation_called = add;
}


void MainWindow::on_pushButton_equal_clicked()
{
    double result = 0;
    double operand = ui->label->text().toDouble();
    if(operation_called == add)
        result = last_operand + operand;
    if(operation_called == sub)
        result = last_operand - operand;
    if(operation_called == mul)
        result = last_operand * operand;
    if(operation_called == div)
        result = last_operand / operand;
    ui->label->setText(QString::number(result));
    last_operand = 0;
    waitingForOperand = true;
    continue_operation = false;
}


void MainWindow::on_pushButton_minus_clicked()
{
    double result = 0;
    double operand = ui->label->text().toDouble();
    if(!waitingForOperand && continue_operation == true)
    {
        if(operation_called == add)
            result = last_operand + operand;
        if(operation_called == sub)
            result = last_operand - operand;
        if(operation_called == mul)
            result = last_operand * operand;
        if(operation_called == div)
            result = last_operand / operand;
        ui->label->setText(QString::number(result));
    }

    last_operand = ui->label->text().toDouble();
    waitingForOperand = true;
    continue_operation = true;
    operation_called = sub;
}


void MainWindow::on_pushButton_multiply_clicked()
{
    double result = 0;
    double operand = ui->label->text().toDouble();
    if(!waitingForOperand && continue_operation == true)
    {
        if(operation_called == add)
            result = last_operand + operand;
        if(operation_called == sub)
            result = last_operand - operand;
        if(operation_called == mul)
            result = last_operand * operand;
        if(operation_called == div)
            result = last_operand / operand;
        ui->label->setText(QString::number(result));
    }

    last_operand = ui->label->text().toDouble();
    waitingForOperand = true;
    continue_operation = true;
    operation_called = mul;
}


void MainWindow::on_pushButton_divide_clicked()
{
    double result = 0;
    double operand = ui->label->text().toDouble();
    if(!waitingForOperand && continue_operation == true)
    {
        if(operation_called == add)
            result = last_operand + operand;
        if(operation_called == sub)
            result = last_operand - operand;
        if(operation_called == mul)
            result = last_operand * operand;
        if(operation_called == div)
            result = last_operand / operand;
        ui->label->setText(QString::number(result));
    }

    last_operand = ui->label->text().toDouble();
    waitingForOperand = true;
    continue_operation = true;
    operation_called = div;
}

void MainWindow::keyboard_backspace_clicked()
{
    if(waitingForOperand)
        return;

    QString text = ui->label->text();
    text.chop(1);
    if(text.isEmpty())
    {
        text = '0';
        waitingForOperand = true;
    }
    ui->label->setText(text);
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    switch(event->key())
    {
    case Qt::Key_0:
        on_pushButton_0_clicked();
        break;
    case Qt::Key_1:
        on_pushButton_1_clicked();
        break;
    case Qt::Key_2:
        on_pushButton_2_clicked();
        break;
    case Qt::Key_3:
        on_pushButton_3_clicked();
        break;
    case Qt::Key_4:
        on_pushButton_4_clicked();
        break;
    case Qt::Key_5:
        on_pushButton_5_clicked();
        break;
    case Qt::Key_6:
        on_pushButton_6_clicked();
        break;
    case Qt::Key_7:
        on_pushButton_7_clicked();
        break;
    case Qt::Key_8:
        on_pushButton_8_clicked();
        break;
    case Qt::Key_9:
        on_pushButton_9_clicked();
        break;
    case Qt::Key_Plus:
        on_pushButton_add_clicked();
        break;
    case Qt::Key_Minus:
        on_pushButton_minus_clicked();
        break;
    case Qt::Key_Asterisk:
        on_pushButton_multiply_clicked();
        break;
    case Qt::Key_Slash:
        on_pushButton_divide_clicked();
        break;
    case Qt::Key_Enter:
        on_pushButton_equal_clicked();
        break;
    case Qt::Key_Period:
        on_pushButton_decimal_clicked();
        break;
    case Qt::Key_Delete:
        on_pushButton_clear_clicked();
        break;
    case Qt::Key_Backspace:
        keyboard_backspace_clicked();
        break;
    default:
        break;
    }
}

