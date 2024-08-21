#ifndef CACULATOR_H
#define CACULATOR_H

#include <string>
#include <vector>

class Caculator
{
    std::string expression;
    std::vector<char> sign;
    int numberOfSign;
    int numberOfNumber;
    std::vector<std::string> number;


    std::vector<char> operatorVector();
    std::vector<std::string> numberVector();


public:
    Caculator(std::string a);
    ~Caculator();

    double timesEvaluate(int indexOfTimes);
    double divideEvaluate(int indexOfDivide);
    double plusEvaluate(int indexOfPlus);
    double minusEvaluate(int indexOfMinus);


    void firstEvaluate();
    void secondEvaluate();
    void thirdEvaluate();
    void fourthEvaluate();

    std::string mainEvaluate();

};

#endif // CACULATOR_H
