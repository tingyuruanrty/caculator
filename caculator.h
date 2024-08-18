#ifndef CACULATOR_H
#define CACULATOR_H

#include <string>
#include <vector>

class Caculator
{
    std::string expression;
    std::vector<int> number;
    std::vector<char> sign;


public:
    Caculator(std::string a);
    ~Caculator();

    std::string evaluate();

};

#endif // CACULATOR_H
