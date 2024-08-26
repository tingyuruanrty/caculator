#include "caculator.h"

std::vector<char> Caculator::operatorVector(){
    std::vector<char> returnVector;
    //for(int i=0;i<expression.size();++i){
    //    if(expression[i]=='+'){
    //        returnVector.push_back(expression[i]);
    //    }
    //    if(expression[i]=='-'){
    //        returnVector.push_back(expression[i]);
    //    }
    //    if(expression[i]=='*'){
    //        returnVector.push_back(expression[i]);
    //    }
    //    if(expression[i]=='/'){
    //        returnVector.push_back(expression[i]);
    //    }
    //}
    //return returnVector;


    int i =0;
    while(i<expression.size()){
        if(expression[i]=='+'||expression[i]=='-'||expression[i]=='*'||expression[i]=='/'){
            returnVector.push_back(expression[i]);

            //signPosition.push_back(i);

            i+=2;
        }else{
            ++i;
        }
    }
    return returnVector;
}

std::vector<int> Caculator::getSignPosition(){
    std::vector<int> returnVector(numberOfSign);
    int accmulator =0;
    int index =0;
    //for(int i =0;i<expression.size();++i){
    //    if(expression[i]==sign[index]){
    //        returnVector[index]=i;
    //        ++index;
    //        if(index ==sign.size()){
    //
    //        }
    //    }
    //}
    while(index<sign.size()){
        if(expression[accmulator]==sign[index]){
            signPosition[index]=accmulator;
            ++index;
        }
        ++accmulator;
    }

    return returnVector;
}

std::vector<std::string> Caculator::numberVector(){
    int index=0;
    std::vector<std::string> returnVector;
    returnVector.resize(numberOfNumber);

    for(int i=0;i<expression.size();++i){
        if(i==signPosition[index]){
            ++index;
        }else{
            returnVector[index]+=expression[i];
        }
    }
    return returnVector;
}

std::string Caculator::getExpression(std::string a){
    if(a[0]=='-'){
        return a="0"+a;
    }else{
        return a;
    }
}

Caculator::Caculator(std::string a)
    :expression(getExpression(a))
    ,sign(operatorVector())
    ,numberOfSign(sign.size())
    ,signPosition(getSignPosition())
    ,numberOfNumber(numberOfSign+1)
    ,number(numberVector())
{}

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
    }
}

void Caculator::secondEvaluate(){
    int accmulator =0;
    for(int i = 0;i<sign.size();++i){
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

void Caculator::thirdEvaluate(){
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
    }
}

void Caculator::fourthEvaluate(){
    int accmulator =0;
    for(int i = 0;i<sign.size();++i){
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
    thirdEvaluate();
    fourthEvaluate();
    return number[0].erase(number[0].find_last_not_of('0')+1,std::string::npos);
}

Caculator::~Caculator()
{}
