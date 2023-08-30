#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    double last_operand;  //last operation from one operand
    bool waitingForOperand;  //waiting for the next operand flag
    bool continue_operation;  //continuous operation when equal sign isn't called but the arithmatic operations itself
    enum operation{add, sub, mul, div};
    uint8_t operation_called;

private slots:
    void on_pushButton_0_clicked();
    void on_pushButton_1_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_7_clicked();
    void on_pushButton_8_clicked();
    void on_pushButton_9_clicked();
    void on_pushButton_decimal_clicked();
    void on_pushButton_clear_clicked();
    void on_pushButton_plusminus_clicked();
    void on_pushButton_percent_clicked();
    void on_pushButton_add_clicked();
    void on_pushButton_equal_clicked();
    void on_pushButton_minus_clicked();
    void on_pushButton_multiply_clicked();
    void on_pushButton_divide_clicked();
    void keyboard_backspace_clicked();

protected:
    void keyPressEvent(QKeyEvent *event) override;
};


#endif // MAINWINDOW_H
