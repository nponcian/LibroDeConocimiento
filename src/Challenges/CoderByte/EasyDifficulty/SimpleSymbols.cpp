#include <Challenges/CoderByte/EasyDifficulty/SimpleSymbols.hpp>

#include <Common/Logger.hpp>
#include <Common/UserInputHandler.hpp>

namespace src::challenges::coderbyte::easy
{
namespace
{

common::Logger logger("SimpleSymbols");

bool isLetter(const char ch)
{
    return (ch >= 'A' && ch <= 'Z') ||
            (ch >= 'a' && ch <= 'z');
}

bool isValidStringIndex(const std::string& str, const int index)
{
    int strSize = str.size();
    return index >= 0 && index < strSize;
}

std::string simpleSymbols(const std::string& str)
{
    // code goes here
    std::string status = "false";
    for (unsigned ctr = 0; ctr < str.size(); ctr++)
    {
        if (!isLetter(str.at(ctr))) continue;

        int left = ctr - 1;
        int right = ctr + 1;
        if (isValidStringIndex(str, left) && isValidStringIndex(str, right) &&
            str.at(left) == '+' && str.at(right) == '+')
        {
            status = "true";
        }
        else
        {
            status = "false";
            break;
        }
    }
    return status;
}

} // namespace

const std::string SimpleSymbols::CHALLENGE_NAME_ = "SimpleSymbols";

SimpleSymbols::SimpleSymbols()
{
}

std::string SimpleSymbols::name() const
{
    return CHALLENGE_NAME_;
}

common::Result SimpleSymbols::run(std::istream& inputStream)
{
    displayProblem();
    auto input = common::getUserInputString(inputStream);
    auto result = simpleSymbols(input);
    logger.print(result);

    result_.set(result);
    return result_;
}

void SimpleSymbols::displayProblem() const
{
    logger.print("Have the function SimpleSymbols(str) take the str parameter being passed and determine if it is an acceptable sequence by either returning the string true or false.");
    logger.print("The str parameter will be composed of + and = symbols with several letters between them (ie. ++d+===+c++==a) and for the string to be true each letter must be surrounded by a + symbol.");
    logger.print("So the string to the left would be false. The string will not be empty and will have at least one letter.");
}

} // namespace src::challenges::coderbyte::easy
