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

    connect(ui->mainLineEdit,&QLineEdit::returnPressed,this,&Widget::on_equalButton_clicked);
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
    expression=ui->mainLineEdit->text();
    std::string answerHolder;
    std::string stringExpression=expression.toStdString();

    if(stringExpression.find('(')!=std::string::npos)
    {

        int start=0;
        int end=0;
        for(int i = 0; i< stringExpression.size();++i){
            if(stringExpression[i]=='('){
                start = i;
            }
            if(stringExpression[i]==')'){
                end = i;
                break;
            }
        }

    Caculator resultOfParentheses(stringExpression.substr(start+1,end-(start+1)));
    std::string parentheses =resultOfParentheses.mainEvaluate();
    stringExpression.replace(start,end-start+1,parentheses);

    }

    Caculator result(stringExpression);
    answerHolder=result.mainEvaluate();

    if(answerHolder.back()=='.'){
        answerHolder.pop_back();
    }

    expression=QString::fromStdString(answerHolder);
    ui->mainLineEdit->setText(expression);

}


void Widget::on_periodButton_clicked()
{
    expression+=".";
    ui->mainLineEdit->setText(expression);
}

void Widget::keyPressEvent(QKeyEvent* k){
    if(k->key()==Qt::Key_0){
        on_zeroButton_clicked();
    }
    if(k->key()==Qt::Key_1){
        on_oneButton_clicked();
    }
    if(k->key()==Qt::Key_2){
        on_twoButton_clicked();
    }
    if(k->key()==Qt::Key_3){
        on_threeButton_clicked();
    }
    if(k->key()==Qt::Key_4){
        on_fourButton_clicked();
    }
    if(k->key()==Qt::Key_5){
        on_fiveButton_clicked();
    }
    if(k->key()==Qt::Key_6){
        on_sixButton_clicked();
    }
    if(k->key()==Qt::Key_7){
        on_sevenButton_clicked();
    }
    if(k->key()==Qt::Key_8){
        on_eightButton_clicked();
    }
    if(k->key()==Qt::Key_9){
        on_nineButton_clicked();
    }
    if(k->key()==Qt::Key_Period){
        on_periodButton_clicked();
    }
    if(k->key()==Qt::Key_ParenLeft){
        on_leftParentheseButton_clicked();
    }
    if(k->key()==Qt::Key_ParenRight){
        on_rightParentheseButton_clicked();
    }
    if(k->key()==Qt::Key_Plus){
        on_plusButton_clicked();
    }
    if(k->key()==Qt::Key_Minus){
        on_minusButton_clicked();
    }
    if(k->key()==Qt::Key_Asterisk){
        on_timeButton_clicked();
    }
    if(k->key()==Qt::Key_Slash){
        on_divideButton_clicked();
    }
    if(k->key()==Qt::Key_Enter){
        on_equalButton_clicked();
    }
    if(k->key()==Qt::Key_Equal){
        on_equalButton_clicked();
    }
    if(k->key()==Qt::Key_C){
        on_clearButton_clicked();
    }
    if(k->key()==Qt::Key_Backspace){
        on_backSpaceButton_clicked();
    }
}
