#pragma once
#include <iostream>
#include <stack>
#include <vector>

class EquationParser
{
public:
    EquationParser() = default;
    std::vector<std::string> cutInPieces(std::string myEquation);
    std::vector<std::string> changeSyntaxToRPN(std::vector<std::string> const& cutInPiecesEq);

private:
    void specialFirstEquationFunc(std::string& myEquation, std::vector<std::string>& cutInPiecesEq);
    void addFuncToVecEq(char frontToCut, std::vector<std::string>& cutInPiecesEq);
    void bracketThenNegative(std::string& myEquation, char frontToCut, std::vector<std::string>& cutInPiecesEq);
    bool isDigit(const char& frontToCut) const;

    void addAndSubtractionSituationRPNConversion(std::vector<std::string>& equationRPN, std::stack<std::string>& symbolsConversionHolder,
                                                 std::string current);
    void divisionAndMultipleSituationRPNConversion(std::vector<std::string>& equationRPN, std::stack<std::string>& symbolsConversionHolder,
                                                   std::string current);
    void closingBracketSituationRPNConversion(std::vector<std::string>& equationRPN, std::stack<std::string>& symbolsConversionHolder);
    bool isFuncChar(const char& toCheck) const;
};
