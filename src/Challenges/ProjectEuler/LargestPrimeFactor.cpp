#include <Challenges/ProjectEuler/LargestPrimeFactor.hpp>

#include <Common/Logger.hpp>
#include <Common/UserInputHandler.hpp>

namespace src::challenges::euler
{
namespace
{

common::Logger logger("LargestPrimeFactor");

bool isPrime(long number) // 100 ... 50 ... 33
{
    long limit = number;

    for (long ctr = 2; ctr <= limit; ctr++)
    {
        if (number % ctr == 0) return false;
        limit = number / ctr;
    }
    return true;
}

long largestPrimeFactor(long number)
{
    long limit = number;
    long largestPrime = 0;

    for (long multiplicand = 2; multiplicand <= limit; multiplicand++)
    {
        long multiplier = number / multiplicand; // 391 / 17 = 23 ===== 17 * 23 // 112
        if (number % multiplicand == 0) // 20 % 5 = 102 / 6 = 17     20 / 5 = 4    21 / 3
        {
            if (isPrime(multiplier) && multiplier > multiplicand)
            {
                return multiplier;
            }
            else if (isPrime(multiplicand))
            {
                largestPrime = multiplicand;
            }
        }
        limit = multiplier;
    }

    return largestPrime;
}

} // namespace

const std::string LargestPrimeFactor::CHALLENGE_NAME_ = "LargestPrimeFactor";

LargestPrimeFactor::LargestPrimeFactor()
{
}

std::string LargestPrimeFactor::name() const
{
    return CHALLENGE_NAME_;
}

common::Result LargestPrimeFactor::run(std::istream& inputStream)
{
    displayProblem();
    auto input = common::getUserInputIntegralOrFloating<long>(inputStream);
    auto result = largestPrimeFactor(input);
    logger.print(result);

    result_.set(result);
    return result_;
}

void LargestPrimeFactor::displayProblem() const
{
    logger.print("The prime factors of 13195 are 5, 7, 13 and 29.");
    logger.print("What is the largest prime factor of the number 600851475143 ?");
}

} // namespace src::challenges::euler
