#include "../EquationVerifier.hpp"
#include <gtest/gtest.h>

namespace testData
{
const std::vector<std::string> badInputDivisionByZero = {"123", "/", "0"};
const std::vector<std::string> badInputNotSizeOfInt = {"2147483648"};
const std::vector<std::string> badInputNotSizeOfIntNegative = {"-2147483649"};
const std::vector<std::string> badInputWords = {"JaceklubiAle"};
const std::vector<std::string> badInputTwoAdds = {"3", "+", "+", "2", "-", "2"};
const std::vector<std::string> badInputNoBracket = {"3", "+", "2", "+", "1", "+", "(", "12", "-", "3"};
const std::vector<std::string> badInput = {"2", "+", "*", "-", "3"};
const std::vector<std::string> badInputWrongUseOfChar = {"3", "#", "2", "*", "3", "+", "1"};
const std::vector<std::string> badInputTwoSubtractions = {"3", "+", "2", "-", "-", "2"};
const std::vector<std::string> badInputSubtractionAfterEnd = {"3", "+", "2", "-"};
const std::vector<std::string> badInputClosingBracketTooFast = {"2", "+", ")", "-", "1"};
const std::vector<std::string> badInputBracketAfterDigit = {"2", "(", "2", "+", "3", ")"};
const std::vector<std::string> badInputAddingAfterOpenBracket = {"2", "+", "(", "+", "1", "+", "2", ")"};
const std::vector<std::string> badInputDigitAfterClosingBracket = {"2", "+", "(", "1", "-", "1", ")", "2"};
const std::vector<std::string> badInputNoInputInBrackets = {"2", "+", "(", "1", "+", "3", "+", ")"};
const std::vector<std::string> badInputAddingBeforeClosingBracket = {"2", "+", "(", ")"};
}

class TestEquationVerifier : public ::testing::Test
{
public:
    TestEquationVerifier() = default;

protected:
    EquationVerifier sut;
};

TEST_F(TestEquationVerifier, verify_input_max_int)
{
    ASSERT_THROW(sut.validate(testData::badInputNotSizeOfInt), std::out_of_range);
}

TEST_F(TestEquationVerifier, verify_input_min_int)
{
    ASSERT_THROW(sut.validate(testData::badInputNotSizeOfIntNegative), std::out_of_range);
}

TEST_F(TestEquationVerifier, this_test_verify_bad_inputs_wrong_use_of_char)
{
    ASSERT_THROW(sut.validate(testData::badInputWrongUseOfChar), std::invalid_argument);
}

TEST_F(TestEquationVerifier, this_test_verify_bad_inputs_words)
{
    ASSERT_THROW(sut.validate(testData::badInputWords), std::invalid_argument);
}

TEST_F(TestEquationVerifier, this_test_verify_bad_inputs_two_adds)
{
    ASSERT_THROW(sut.validate(testData::badInputTwoAdds), std::invalid_argument);
}

TEST_F(TestEquationVerifier, this_test_verify_bad_inputs_two_subtractions)
{
    ASSERT_THROW(sut.validate(testData::badInputTwoSubtractions), std::invalid_argument);
}

TEST_F(TestEquationVerifier, this_test_verify_bad_inputs_subtraction_after_end)
{
    ASSERT_THROW(sut.validate(testData::badInputSubtractionAfterEnd), std::invalid_argument);
}

TEST_F(TestEquationVerifier, this_test_verify_bad_inputs_no_bracket)
{
    ASSERT_THROW(sut.validate(testData::badInputNoBracket), std::invalid_argument);
}

TEST_F(TestEquationVerifier, this_test_verify_bad_inputs_addind_after_open_bracket)
{
    ASSERT_THROW(sut.validate(testData::badInputAddingAfterOpenBracket), std::invalid_argument);
}

TEST_F(TestEquationVerifier, this_test_verify_bad_inputs_adding_before_closing_bracket)
{
    ASSERT_THROW(sut.validate(testData::badInputAddingBeforeClosingBracket), std::invalid_argument);
}

TEST_F(TestEquationVerifier, this_test_verify_bad_input_bracket_after_digit)
{
    ASSERT_THROW(sut.validate(testData::badInputBracketAfterDigit), std::invalid_argument);
}

TEST_F(TestEquationVerifier, this_test_verify_bad_inputs_closing_bracket_too_fast)
{
    ASSERT_THROW(sut.validate(testData::badInputClosingBracketTooFast), std::invalid_argument);
}

TEST_F(TestEquationVerifier, this_test_verify_bad_inputs_no_input_in_brackets)
{
    ASSERT_THROW(sut.validate(testData::badInputNoInputInBrackets), std::invalid_argument);
}

TEST_F(TestEquationVerifier, this_test_verify_bad_inputs_digit_after_closing_bracket)
{
    ASSERT_THROW(sut.validate(testData::badInputDigitAfterClosingBracket), std::invalid_argument);
}

TEST_F(TestEquationVerifier, this_test_verify_bad_input)
{
    ASSERT_THROW(sut.validate(testData::badInput), std::invalid_argument);
}