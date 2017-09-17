#include "../EquationParser.hpp"
#include <gtest/gtest.h>

namespace testData
{
const std::string simpleEquation = "(1+2)/2-4";
const std::string equation = "2-3/(5*6)+10";
const std::vector<std::string> equationAfterCutting = {"2", "-", "3", "/", "(", "5", "*", "6", ")", "+", "10"};
const std::vector<std::string> equationAfterRPNConversion = {"2", "3", "5", "6", "*", "/", "-", "10", "+"};
const std::vector<std::string> simpleEquationAfterCutting = {"(", "1", "+", "2", ")", "/", "2", "-", "4"};
const std::vector<std::string> simpleEquationAfterRPNConversion = {"1", "2", "+", "2", "/", "4", "-"};
}

class TestEquationParser : public ::testing::Test
{
public:
    TestEquationParser() = default;

protected:
    EquationParser sut;
};

TEST_F(TestEquationParser, cut_simple_equation)
{
    ASSERT_EQ(sut.cutInPieces(testData::simpleEquation), testData::simpleEquationAfterCutting);
}

TEST_F(TestEquationParser, parse_to_RPN_simple_eqution)
{
    ASSERT_EQ(sut.changeSyntaxToRPN(testData::simpleEquationAfterCutting), testData::simpleEquationAfterRPNConversion);
}

TEST_F(TestEquationParser, cut_equation)
{
    ASSERT_EQ(sut.cutInPieces(testData::equation), testData::equationAfterCutting);
}

TEST_F(TestEquationParser, parse_to_RPN_equation)
{
    ASSERT_EQ(sut.changeSyntaxToRPN(testData::equationAfterCutting), testData::equationAfterRPNConversion);
}