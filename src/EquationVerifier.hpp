#pragma once
#include <iostream>
#include <vector>

class EquationVerifier
{
public:
    EquationVerifier() = default;
    void validate(const std::vector<std::string>& cutInPiecesEq);

private:
    void checkSyntax(const std::vector<std::string>& cutInPiecesEq);
    bool isFuncChar(const char& toCheck) const;
    bool isMathSymbol(const char& toCheck) const;
    bool isDigit(const char& frontToCut) const;
};
