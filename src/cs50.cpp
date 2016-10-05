#include <iostream>
#include <string>
#include "cs50.h"
#include <regex>
#include <cfloat>

namespace cs50
{

/**
 * TODO
 */
void eprintf()
{
    // TODO
}

/**
 * TODO
 */
char get_char(void)
{
    // TODO
    return '\0';
}

/**
 * Reads a line of text from stdin via get_string(). 
 * Uses regex to match float pattern. If success, returns the input converted to a float. 
 * If input doesn't match pattern, prompts user to retry. 
 * If error stream, returns FLT_MAX
 */
double get_double(void)
{
    // attempt to take a double from the user
    while (true)
    {
        std::string str = get_string();

        // if eof, failbit or badbit clear state and return DOUBLE_MAX
        if (std::cin.eof() || std::cin.fail())
        {
            std::cin.clear();
            return DBL_MAX;
        }

        // regex for [optional] + or - sign, followed by one of the following: either a number followed by floating point and [optional] digits, or an [optional] number followed by floating point and digits, or any number
 
       std::regex re("(\\+|-)?\\d*(\\.\\d*)?");

        // on matching input attempt to convert string to double
        if (std::regex_match(str, re))
        {
            try
            {
                return std::stod(str);
            }
            // in case of value exceeding double size do nothing and reprompt
            catch (const std::exception&)
            {
                ;
            }
        }

        // if we're here the input was not ok so reprompt
        std::cout << "Retry: ";

    }

}

/**
 * Reads a line of text from stdin via get_string(). 
 * Uses regex to match float pattern. If success, returns the input converted to a float. 
 * If input doesn't match pattern, prompts user to retry. 
 * If error stream, returns FLT_MAX
 */
float get_float(void)
{
    // attempt to take a float from the user
    while (true)
    {
        std::string str = get_string();

        // if eof, failbit or badbit clear state and return FLT_MAX
        if (std::cin.eof() || std::cin.fail())
        {
            std::cin.clear();
            return FLT_MAX;
        }

        // regex for [optional] + or - sign, followed by one of the following: either a number followed by floating point and [optional] digits, or an [optional] number followed by floating point and digits, or any number
        std::regex re("(\\+|-)?\\d*(\\.\\d*)?");

        // on matching input attempt to convert string to float
        if (std::regex_match(str, re))
        {
            try
            {
                return std::stof(str);
            }
            // in case of value exceeding float size do nothing and reprompt
            catch (const std::exception&)
            {
                ;
            }
        }

        // if we're here the input was not ok so reprompt
        std::cout << "Retry: ";

    }
}

/**
 * TODO
 */
int get_int(void)
{
    // TODO
    return 0;
}

/**
 * TODO
 */
long long get_long_long(void)
{
    // TODO
    return 0;
}

/**
 * TODO
 */
std::string get_string(void)
{
    // TODO: check for failure
    // TODO: decide whether to return string or c_str
    std::string s;
    std::getline(std::cin, s);
    return s;
}

}


