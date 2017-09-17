#pragma once
#include "EquationParser.hpp"
#include "EquationVerifier.hpp"
#include <algorithm>
#include <exception>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

class Calculator
{
public:
    Calculator() = default;
    ~Calculator() = default;
    int count(std::string equation);

private:
    bool isOneNumber(const std::string& equation);
    int calculate(const std::vector<std::string>& equationRPN);
    bool isFuncChar(const char& toCheck) const;
    int add(const int& left, const int& right) const;
    int subtraction(const int& left, const int& right) const;
    int division(const int& left, const int& right) const;
    int multiplication(const int& left, const int& right) const;
    void calculateMathSymbol(const char& current, std::stack<std::string>& RPNCalculation);

    EquationParser parser;
    EquationVerifier verifer;
};
