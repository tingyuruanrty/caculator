#include "caculator.h"

std::string Caculator::getExpression(std::string a){
    if(a[0]=='-'){
        return a="0"+a;
    }else{
        return a;
    }
}

Caculator::Caculator(std::string a)
    :expression(getExpression(a))
{
    std::string currentNumber;
    for(int i = 0;i<expression.size();++i){
        if(expression[i]=='*'||expression[i]=='/'||expression[i]=='+'||expression[i]=='-'){
            sign.push_back(expression[i]);
            signPosition.push_back(i);
            number.push_back(currentNumber);
            currentNumber=expression[i+1];
            i=i+1;
        }else{
            currentNumber+=expression[i];
        }
    }
    number.push_back(currentNumber);
}

double Caculator::timesEvaluate(int indexOfTimes){
    return std::stod(number[indexOfTimes]) * std::stod(number[indexOfTimes+1]);
}

double Caculator::divideEvaluate(int indexOfDivide){
    return std::stod(number[indexOfDivide]) / std::stod(number[indexOfDivide+1]);
}

double Caculator::plusEvaluate(int indexOfPlus){
    return std::stod(number[indexOfPlus]) + std::stod(number[indexOfPlus+1]);
}

double Caculator::minusEvaluate(int indexOfMinus){
    return std::stod(number[indexOfMinus]) - std::stod(number[indexOfMinus+1]);
}

void Caculator::firstEvaluate(){
    int accmulator =0;
    for(int i = 0;i<sign.size();++i){

        if(sign[i]=='*'){
            number[i]=std::to_string(timesEvaluate(i));
            for(int j=i+1;j<number.size()-1;++j){
                number[j]=number[j+1];
                sign[j-1]=sign[j];
            }
            number.pop_back();
            sign.pop_back();
            ++accmulator;
            i-=accmulator;
        }

        if(sign[i]=='/'){
            number[i]=std::to_string(divideEvaluate(i));
            for(int j=i+1;j<number.size()-1;++j){
                number[j]=number[j+1];
                sign[j-1]=sign[j];
            }
            number.pop_back();
            sign.pop_back();
            ++accmulator;
            i-=accmulator;
        }
    }
}

void Caculator::secondEvaluate(){
    int accmulator =0;
    for(int i = 0;i<sign.size();++i){
        if(sign[i]=='+'){
            number[i]=std::to_string(plusEvaluate(i));
            for(int j=i+1;j<number.size()-1;++j){
                number[j]=number[j+1];
                sign[j-1]=sign[j];
            }
            number.pop_back();
            sign.pop_back();
            ++accmulator;
            i-=accmulator;
        }
        if(sign[i]=='-'){
            number[i]=std::to_string(minusEvaluate(i));
            for(int j=i+1;j<number.size()-1;++j){
                number[j]=number[j+1];
                sign[j-1]=sign[j];
            }
            number.pop_back();
            sign.pop_back();
            ++accmulator;
            i-=accmulator;
        }
    }
}

std::string Caculator::mainEvaluate(){
    firstEvaluate();
    secondEvaluate();
    return number[0].erase(number[0].find_last_not_of('0')+1,std::string::npos);
}

Caculator::~Caculator()
{}
