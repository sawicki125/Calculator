#include "EquationVerifier.hpp"

void EquationVerifier::validate(const std::vector<std::string>& cutInPiecesEq)
{
    int openBrackets = 0;
    int closeBrackets = 0;
    for(auto current : cutInPiecesEq)
    {
        try
        {
            std::stoi(current);
        }
        catch(std::out_of_range ex)
        {
            throw std::out_of_range("Bad input: Too big number");
        }
        catch(std::invalid_argument ex)
        {
            char caughtNotNumber = current.front();
            if(!isFuncChar(caughtNotNumber))
            {
                throw std::invalid_argument("Bad input: Not math equation symbol occurred");
            }
            else if(caughtNotNumber == '(')
            {
                openBrackets++;
            }
            else if(caughtNotNumber == ')')
            {
                closeBrackets++;
                if(closeBrackets > openBrackets)
                {
                    throw std::invalid_argument("Bad input: Wrong using of brackets");
                }
            }
        }
    }
    if(openBrackets != closeBrackets)
    {
        throw std::invalid_argument("Bad input: Wrong number of brackets");
    }
    checkSyntax(cutInPiecesEq);
}

void EquationVerifier::checkSyntax(const std::vector<std::string>& cutInPiecesEq)
{
    if(isMathSymbol(cutInPiecesEq.at(0).front()))
    {
        throw std::invalid_argument("Bad input: Double math symbols");
    }

    std::string next = "";

    for(auto current = cutInPiecesEq.begin(); current != cutInPiecesEq.end(); ++current)
    {
        if(current != --cutInPiecesEq.end())
        {
            next = (++current)->front();
            current--;
        }
        else
        {
            next = "";
        }
        if(isMathSymbol(current->front()))
        {
            if(current == --cutInPiecesEq.end() || (!next.empty() && (isMathSymbol(next.front()) || next.front() == ')')))
            {
                throw std::invalid_argument("Bad input: Wrong syntax - math symbol or bracket after math symbol");
            }
        }
        else if(current->front() == '(')
        {
            if(!next.empty() && (next.front() == ')' || isMathSymbol(next.front())))
            {
                throw std::invalid_argument("Bad input: Wrong syntax - empty brackets");
            }
        }
        else if(current->front() == ')')
        {
            if(!next.empty() && isDigit(next.front()))
            {
                throw std::invalid_argument("Bad input: Wrong syntax - digit after closing bracket ");
            }
        }
        else
        {
            if((!next.empty()) && next.front() == '(')
            {
                throw std::invalid_argument("Bad input: Wrong syntax - open bracket after digit");
            }
        }
    }
}

bool EquationVerifier::isFuncChar(const char& toCheck) const
{
    return (toCheck == '+' || toCheck == '-' || toCheck == '/' || toCheck == '*' || toCheck == '(' || toCheck == ')');
}

bool EquationVerifier::isMathSymbol(const char& toCheck) const
{
    return (toCheck == '+' || toCheck == '-' || toCheck == '/' || toCheck == '*');
}

bool EquationVerifier::isDigit(const char& frontToCut) const
{
    return (frontToCut >= '0' && frontToCut <= '9');
}
