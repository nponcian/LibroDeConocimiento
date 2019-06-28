#include "CoderByte/Challenges/EasyDifficulty/FirstFactorial.hpp"

#include "Utilities/Logger.hpp"
#include "Utilities/UserInputHandler.hpp"

namespace src::coderbyte::challenges::easy
{
namespace
{

utilities::Logger logger("FirstFactorial");

int firstFactorial(int num)
{
    // code goes here
    int result = 1;
    for (; num > 0; num--)
    {
        result = result * num;
    }
    return result;
}

} // namespace

const std::string FirstFactorial::CHALLENGE_NAME_ = "FirstFactorial";

FirstFactorial::FirstFactorial()
{
}

std::string FirstFactorial::name() const
{
    return CHALLENGE_NAME_;
}

void FirstFactorial::run()
{
    displayProblem();
    auto input = utilities::getUserInputIntegralOrFloating<int>();
    auto result = firstFactorial(input);
    logger.print(result);
}

void FirstFactorial::displayProblem() const
{
    logger.print("Have the function FirstFactorial(num) take the num parameter being passed and return the factorial of it.");
    logger.print("For example: if num = 4, then your program should return (4 * 3 * 2 * 1) = 24.");
    logger.print("For the test cases, the range will be between 1 and 18 and the input will always be an integer.");
}

} // namespace src::coderbyte::challenges::easy