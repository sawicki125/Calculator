#include "EquationParser.hpp"

std::vector<std::string> EquationParser::cutInPieces(std::string myEquation)
{
    std::vector<std::string> cutInPiecesEq;
    specialFirstEquationFunc(myEquation, cutInPiecesEq);
    std::string toPutBack = "";

    while(!myEquation.empty())
    {
        char frontToCut = myEquation.front();
        if(isDigit(frontToCut))
        {
            toPutBack.push_back(frontToCut);
            myEquation.erase(myEquation.begin());
            if(myEquation.empty())
            {
                cutInPiecesEq.push_back(toPutBack);
            }
        }
        else if(toPutBack.empty())
        {
            addFuncToVecEq(frontToCut, cutInPiecesEq);
            myEquation.erase(myEquation.begin());
            bracketThenNegative(myEquation, frontToCut, cutInPiecesEq);
        }
        else
        {
            cutInPiecesEq.push_back(toPutBack);
            toPutBack = "";
            addFuncToVecEq(frontToCut, cutInPiecesEq);
            myEquation.erase(myEquation.begin());
            bracketThenNegative(myEquation, frontToCut, cutInPiecesEq);
        }
    }
    return cutInPiecesEq;
}

void EquationParser::specialFirstEquationFunc(std::string& myEquation, std::vector<std::string>& cutInPiecesEq)
{
    if(myEquation.at(0) == '-')
    {
        cutInPiecesEq.emplace_back("0");
        cutInPiecesEq.emplace_back("-");
        myEquation.erase(myEquation.begin());
    }
}

void EquationParser::addFuncToVecEq(char frontToCut, std::vector<std::string>& cutInPiecesEq)
{
    std::string addingString(1, frontToCut);
    cutInPiecesEq.push_back(addingString);
}

void EquationParser::bracketThenNegative(std::string& myEquation, char frontToCut, std::vector<std::string>& cutInPiecesEq)
{
    if(frontToCut == '(' && myEquation.front() == '-')
    {
        cutInPiecesEq.emplace_back("0");
    }
}

bool EquationParser::isDigit(const char& frontToCut) const
{
    return (frontToCut >= 48 && frontToCut <= 57);
}

std::vector<std::string> EquationParser::changeSyntaxToRPN(std::vector<std::string> const& cutInPiecesEq)
{
    std::vector<std::string> equationRPN;
    std::stack<std::string> symbolsConversionHolder;
    for(auto current : cutInPiecesEq)
    {
        if(!isFuncChar(current.front()))
        {
            equationRPN.emplace_back(current);
        }
        else if(current.front() == '(')
        {
            symbolsConversionHolder.push(current);
        }
        else if(current.front() == ')')
        {
            closingBracketSituationRPNConversion(equationRPN, symbolsConversionHolder);
        }
        else
        {
            if(current.front() == '+' || current.front() == '-')
            {
                addAndSubtractionSituationRPNConversion(equationRPN, symbolsConversionHolder, current);
            }
            else
            {
                divisionAndMultipleSituationRPNConversion(equationRPN, symbolsConversionHolder, current);
            }
        }
    }

    while(!symbolsConversionHolder.empty())
    {
        equationRPN.emplace_back(symbolsConversionHolder.top());
        symbolsConversionHolder.pop();
    }
    return equationRPN;
}

void EquationParser::closingBracketSituationRPNConversion(std::vector<std::string>& equationRPN, std::stack<std::string>& symbolsConversionHolder)
{
    if(equationRPN.empty() || symbolsConversionHolder.empty())
    {
        return;
    }
    while(symbolsConversionHolder.top().front() != '(')
    {
        equationRPN.emplace_back(symbolsConversionHolder.top());
        symbolsConversionHolder.pop();
    }
    symbolsConversionHolder.pop();
}

void EquationParser::divisionAndMultipleSituationRPNConversion(std::vector<std::string>& equationRPN,
                                                               std::stack<std::string>& symbolsConversionHolder, std::string current)
{
    while(!symbolsConversionHolder.empty())
    {
        auto frontChar = symbolsConversionHolder.top().front();
        if(frontChar != '(' && (frontChar == '/' || frontChar == '*'))
        {
            equationRPN.emplace_back(symbolsConversionHolder.top());
            symbolsConversionHolder.pop();
            continue;
        }
        break;
    }
    symbolsConversionHolder.push(current);
}

void EquationParser::addAndSubtractionSituationRPNConversion(std::vector<std::string>& equationRPN,
                                                             std::stack<std::string>& symbolsConversionHolder, std::string current)
{
    while(!symbolsConversionHolder.empty() && symbolsConversionHolder.top().front() != '(')
    {
        equationRPN.emplace_back(symbolsConversionHolder.top());
        symbolsConversionHolder.pop();
    }
    symbolsConversionHolder.push(current);
}

bool EquationParser::isFuncChar(char const& toCheck) const
{
    return (toCheck == '+' || toCheck == '-' || toCheck == '/' || toCheck == '*' || toCheck == '(' || toCheck == ')');
}
