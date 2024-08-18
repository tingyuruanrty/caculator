#include "widget.h"
#include "caculator.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setWindowTitle("caculator");
    QFont f("SimSun",20);
    ui->mainLineEdit->setFont(f);

    QIcon a("C:\\Users\\tingy\\Desktop\\c++\\qtprojects\\caculator\\arrow.png");
    ui->backSpaceButton->setIcon(a);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_oneButton_clicked()
{
    expression+="1";
    ui->mainLineEdit->setText(expression);
}


void Widget::on_twoButton_clicked()
{
    expression+="2";
    ui->mainLineEdit->setText(expression);
}


void Widget::on_threeButton_clicked()
{
    expression+="3";
    ui->mainLineEdit->setText(expression);
}


void Widget::on_fourButton_clicked()
{
    expression+="4";
    ui->mainLineEdit->setText(expression);
}


void Widget::on_fiveButton_clicked()
{
    expression+="5";
    ui->mainLineEdit->setText(expression);
}


void Widget::on_sixButton_clicked()
{
    expression+="6";
    ui->mainLineEdit->setText(expression);
}


void Widget::on_sevenButton_clicked()
{
    expression+="7";
    ui->mainLineEdit->setText(expression);
}


void Widget::on_eightButton_clicked()
{
    expression+="8";
    ui->mainLineEdit->setText(expression);
}


void Widget::on_nineButton_clicked()
{
    expression+="9";
    ui->mainLineEdit->setText(expression);
}


void Widget::on_leftParentheseButton_clicked()
{
    expression+="(";
    ui->mainLineEdit->setText(expression);
}


void Widget::on_rightParentheseButton_clicked()
{
    expression+=")";
    ui->mainLineEdit->setText(expression);
}


void Widget::on_plusButton_clicked()
{
    expression+="+";
    ui->mainLineEdit->setText(expression);
}


void Widget::on_minusButton_clicked()
{
    expression+="-";
    ui->mainLineEdit->setText(expression);
}


void Widget::on_timeButton_clicked()
{
    expression+="*";
    ui->mainLineEdit->setText(expression);
}


void Widget::on_divideButton_clicked()
{
    expression+="/";
    ui->mainLineEdit->setText(expression);
}


void Widget::on_zeroButton_clicked()
{
    expression+="0";
    ui->mainLineEdit->setText(expression);
}


void Widget::on_clearButton_clicked()
{
    expression="";
    ui->mainLineEdit->setText(expression);
}


void Widget::on_backSpaceButton_clicked()
{
    expression.chop(1);
    ui->mainLineEdit->setText(expression);
}


void Widget::on_equalButton_clicked()
{
    Caculator a(expression.toStdString());

    expression=QString::fromStdString(a.evaluate());
    ui->mainLineEdit->setText(expression);
}

