#include <CoderByte/Challenges/EasyDifficulty/LetterCapitalize.hpp>

#include <Common/Logger.hpp>
#include <Common/UserInputHandler.hpp>

namespace src::coderbyte::challenges::easy
{
namespace
{

common::Logger logger("LetterCapitalize");

bool isCharSmallLetter(const char ch)
{
    return ch >= 'a' && ch <= 'z';
}

void convertToSmallLetter(char& ch)
{
    ch = ch - 32;
}

std::string letterCapitalize(std::string str)
{
    // code goes here
    for (unsigned ctr = 0; ctr < str.size(); ctr++)
    {
        if (ctr != 0 && str[ctr-1] != ' ') continue;
        if (isCharSmallLetter(str[ctr]))
        {
            convertToSmallLetter(str[ctr]);
        }
    }
    return str;
}

} // namespace

const std::string LetterCapitalize::CHALLENGE_NAME_ = "LetterCapitalize";

LetterCapitalize::LetterCapitalize()
{
}

std::string LetterCapitalize::name() const
{
    return CHALLENGE_NAME_;
}

void LetterCapitalize::run()
{
    displayProblem();
    auto input = common::getUserInputString();
    auto result = letterCapitalize(input);
    logger.print(result);
}

void LetterCapitalize::displayProblem() const
{
    logger.print("Have the function LetterCapitalize(str) take the str parameter being passed and capitalize the first letter of each word.");
    logger.print("Words will be separated by only one space.");
}

} // namespace src::coderbyte::challenges::easy
