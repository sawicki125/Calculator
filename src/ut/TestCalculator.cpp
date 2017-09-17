#include "../Calculator.hpp"
#include "gtest/gtest.h"

namespace testData
{
const std::string simpleInput = "2";
const std::string simpleInputNegative = "-3";
const std::string simpleInputBrackets = "(10)";
const std::string simpleInputNegativeWithBrackets = "(-12)";
const std::string simpleInputWithPlus = "+3";
const std::string simpleEquation = "4+2";
const std::string simpleEquationForSubsAndAdds = "4+2+3-12+1";
const std::string equation = "1*(-2+4)/2";
const std::string equationNumberTwo = "(-2+5)*12+14/7";
const std::string simpleEquationMultiplication = "2*3*4*12*4";
const std::string simpleEquationDivision = "120/3/2/5";
const std::string simpleEquationMultiplicationAndDivision = "3*4/2*12/7";

const std::string badInputDivisionByZero = "12+4*3+2/0";

const std::string programingTaskDocEq1 = "(1+2+3+(4+5+6+7+8+9)*5)/2";
const std::string programingTaskDocEq2 = "(1+2+3++(4+5+6+7+8+9)*5)/2";
const std::string programingTaskDocEq3 = "+5+2";
const std::string programingTaskDocEq4 = "7--2";
const std::string programingTaskDocEq5 = "7-(-2)";
const std::string programingTaskDocEq6 = "(5)";
const std::string programingTaskDocEq7 = "12";
}

class TestCalculator : public ::testing::Test
{
public:
    TestCalculator() = default;

protected:
    Calculator sut;
};

TEST_F(TestCalculator, returns_passed_number_when_is_solo_given)
{
    ASSERT_EQ(sut.count(testData::simpleInput), 2);
}

TEST_F(TestCalculator, returns_passed_number_when_is_solo_given_with_brackets)
{
    ASSERT_EQ(sut.count(testData::simpleInputBrackets), 10);
}

TEST_F(TestCalculator, returns_number_given_when_solo_number_is_passed_with_plus)
{
    ASSERT_EQ(sut.count(testData::simpleInputWithPlus), 3);
}

TEST_F(TestCalculator, returns_number_given_when_solo_negative_number_is_passed)
{
    ASSERT_EQ(sut.count(testData::simpleInputNegative), -3);
}

TEST_F(TestCalculator, returns_number_given_when_solo_negative_number_is_passed_in_brackets)
{
    ASSERT_EQ(sut.count(testData::simpleInputNegativeWithBrackets), -12);
}

TEST_F(TestCalculator, adding_and_subtraction)
{
    ASSERT_EQ(sut.count(testData::simpleEquation), 6);
}

TEST_F(TestCalculator, adding_and_subtraction_smple_Equation)
{
    ASSERT_EQ(sut.count(testData::simpleEquationForSubsAndAdds), -2);
}

TEST_F(TestCalculator, multiplication)
{
    ASSERT_EQ(sut.count(testData::simpleEquationMultiplication), 1152);
}

TEST_F(TestCalculator, division)
{
    ASSERT_EQ(sut.count(testData::simpleEquationDivision), 4);
}

TEST_F(TestCalculator, this_test_checks_case_with_division_by_zero)
{
    ASSERT_THROW(sut.count(testData::badInputDivisionByZero), std::invalid_argument);
}

TEST_F(TestCalculator, multiplication_and_division)
{
    ASSERT_EQ(sut.count(testData::simpleEquationMultiplicationAndDivision), 10);
}

TEST_F(TestCalculator, simple_full_Equation_multiplication_division_adding_sustraction_and_brackets)
{
    ASSERT_EQ(sut.count(testData::equation), 1);
}

TEST_F(TestCalculator, full_Equation_multiplication_division_adding_sustraction_and_brackets)
{
    ASSERT_EQ(sut.count(testData::equationNumberTwo), 38);
}

TEST_F(TestCalculator, testcases_from_programing_task_doc_one)
{
    ASSERT_EQ(sut.count(testData::programingTaskDocEq1), 100);
}

TEST_F(TestCalculator, testcases_from_programing_task_doc_two)
{
    ASSERT_THROW(sut.count(testData::programingTaskDocEq2), std::invalid_argument);
}

TEST_F(TestCalculator, testcases_from_programing_task_doc_three)
{
    ASSERT_EQ(sut.count(testData::programingTaskDocEq3), 7);
}

TEST_F(TestCalculator, testcases_from_programing_task_doc_four)
{
    ASSERT_THROW(sut.count(testData::programingTaskDocEq4), std::invalid_argument);
}

TEST_F(TestCalculator, testcases_from_programing_task_doc_five)
{
    ASSERT_EQ(sut.count(testData::programingTaskDocEq5), 9);
}

TEST_F(TestCalculator, testcases_from_programing_task_doc_six)
{
    ASSERT_EQ(sut.count(testData::programingTaskDocEq6), 5);
}

TEST_F(TestCalculator, testcases_from_programing_task_doc_seven)
{
    ASSERT_EQ(sut.count(testData::programingTaskDocEq7), 12);
}
