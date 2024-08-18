#include "caculator.h"

Caculator::Caculator(std::string a)
    :expression(a)
{
    for(int i = 0;i<expression.size();++i){
        if( expression[i]!='+'&&
            expression[i]!='-'&&
            expression[i]!='*'&&
            expression[i]!='/')
        {
            number.push_back(expression[i]-'0');
        }else
        {
            sign.push_back(expression[i]);
        }
    }
}

std::string Caculator::evaluate(){
    std::string answer;
    for(int i=0;i<this->sign.size();++i){
        if(sign[i]=='+'){
            number[i+1]=number[i]+number[i+1];
        }
        if(sign[i]=='-'){
            number[i+1]=number[i]-number[i+1];
        }
        if(sign[i]=='*'){
            number[i+1]=number[i]*number[i+1];
        }
        if(sign[i]=='/'){
            number[i+1]=number[i]/number[i+1];
        }
    }
    return answer = std::to_string(number.back());
}

Caculator::~Caculator()
{}
