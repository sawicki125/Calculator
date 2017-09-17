#include "Calculator.hpp"

int Calculator::count(std::string equation)
{
    std::vector<std::string> cutInPiecesEq;
    std::vector<std::string> equationRPN;

    equation.erase(std::remove_if(equation.begin(), equation.end(), isspace), equation.end());

    if(equation.front() == '+')
    {
        equation.erase(equation.begin());
    }
    if(equation.empty())
    {
        throw std::invalid_argument("Empty text value");
    }
    else if(isOneNumber(equation))
    {
        return std::stoi(equation);
    }

    cutInPiecesEq = parser.cutInPieces(equation);
    verifer.validate(cutInPiecesEq);
    equationRPN = parser.changeSyntaxToRPN(cutInPiecesEq);

    return calculate(equationRPN);
}

bool Calculator::isOneNumber(const std::string& equation)
{
    if(equation.at(0) == '+')
    {
        int equationToInt = std::stoi(equation);
        std::string strToCompare = std::to_string(equationToInt);
        strToCompare = "+" + strToCompare;
        return strToCompare == equation;
    }
    try
    {
        int equationToInt = std::stoi(equation);
        return std::to_string(equationToInt) == equation;
    }
    catch(std::invalid_argument)
    {
        return false;
    }
    catch(std::out_of_range)
    {
        return false;
    }
}

bool Calculator::isFuncChar(const char& toCheck) const
{
    return (toCheck == '+' || toCheck == '-' || toCheck == '/' || toCheck == '*' || toCheck == '(' || toCheck == ')');
}

int Calculator::add(const int& left, const int& right) const
{
    return left + right;
}

int Calculator::subtraction(const int& left, const int& right) const
{
    return left - right;
}

int Calculator::multiplication(const int& left, const int& right) const
{
    return left * right;
}

int Calculator::division(const int& left, const int& right) const
{
    return right == 0 ? throw std::invalid_argument("Division by 0") : left / right;
}

int Calculator::calculate(const std::vector<std::string>& equationRPN)
{
    std::stack<std::string> RPNCalculation;
    for(auto current : equationRPN)
    {
        if(isFuncChar(current.front()))
        {
            calculateMathSymbol(current.front(), RPNCalculation);
        }
        else
        {
            RPNCalculation.push(current);
        }
    }
    return RPNCalculation.empty() ? 0 : std::stoi(RPNCalculation.top());
}

void Calculator::calculateMathSymbol(const char& current, std::stack<std::string>& RPNCalculation)
{

    int outputOfEq;
    int right = std::stoi(RPNCalculation.top());
    RPNCalculation.pop();
    int left = std::stoi(RPNCalculation.top());
    RPNCalculation.pop();
    switch(current)
    {
    case '+':
        outputOfEq = add(left, right);
        break;
    case '-':
        outputOfEq = subtraction(left, right);
        break;
    case '/':
        outputOfEq = division(left, right);
        break;
    case '*':
        outputOfEq = multiplication(left, right);
        break;
    default:
        throw std::invalid_argument(std::string(1, current));
    }
    RPNCalculation.push(std::to_string(outputOfEq));
}
