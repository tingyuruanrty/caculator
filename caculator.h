#ifndef CACULATOR_H
#define CACULATOR_H

#include <string>
#include <vector>

class Caculator
{
    std::string expression;
    std::vector<char> sign;
    std::vector<int> signPosition;
    std::vector<std::string> number;

    std::string getExpression(std::string a);

public:
    Caculator(std::string a);
    ~Caculator();

    double timesEvaluate(int indexOfTimes);
    double divideEvaluate(int indexOfDivide);
    double plusEvaluate(int indexOfPlus);
    double minusEvaluate(int indexOfMinus);

    void firstEvaluate();
    void secondEvaluate();

    std::string mainEvaluate();
};

#endif // CACULATOR_H
