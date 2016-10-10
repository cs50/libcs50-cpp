#include <cfloat>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>

#include "cs50.h"

namespace cs50
{

/** static variable which will call the constructor before 
 * execution enters main.
*/
static BeforeMain init;

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
 * Reads a line of text from standard input and returns the equivalent
 * double as precisely as possible; if text does not represent a
 * double or if value would cause underflow or overflow, user is
 * prompted to retry. If line can't be read, returns DBL_MAX.
 */
double get_double(void)
{
    // attempt to take a double from the user
    while (true)
    {
        std::string str;
        // if eof or error return DBL_MAX
        try
        {
            str = get_string();
        }
        catch (const std::domain_error& e)
        {
            return DBL_MAX;
        }
        // validate input
        if (str.length() > 0 && !isspace(str[0]))
        {
            // load string into a stringstream
            std::istringstream is(str);
            double d;

            // if is successfully read into an double we return it
            if (is >> d && is.eof())
            {
                // disallow hexadecimals and exponents
                if (strcspn(str.c_str(), "XxEePp") == str.length())
                {
                    return d;
                }
            }
        }
        // if we're here the input was not ok so reprompt
        std::cout << "Retry: ";
    }
}

/**
 * Reads a line of text from standard input and returns the equivalent
 * float as precisely as possible; if text does not represent a
 * float or if value would cause underflow or overflow, user is
 * prompted to retry. If line can't be read, returns FLT_MAX.
 */
float get_float(void)
{
    // attempt to take a double from the user
    while (true)
    {
        std::string str;
        // if eof or error return FLT_MAX
        try
        {
            str = get_string();
        }
        catch (const std::domain_error& e)
        {
            return FLT_MAX;
        }
        // validate input
        if (str.length() > 0 && !isspace(str[0]))
        {
            // load string into a stringstream
            std::istringstream is(str);
            float f;

            // if is successfully read into a float we return it
            if (is >> f && is.eof())
            {
                // disallow hexadecimals and exponents
                if (strcspn(str.c_str(), "XxEePp") == str.length())
                {
                    return f;
                }
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
 * reads a line of text from standard input and returns it as std::string. If
 * input stream goes bad (should never happen barring hardware issues) throws
 * std::runtime_error object. If input is invalid (e.g. EOF etc)
 * std::domain_error exception is thrown.
 */
std::string get_string(void)
{
    // TODO: decide whether to return string or c_str
    std::string str;

    // attempt to read string input into str
    std::getline(std::cin, str);

    // check if input stream in bad state (hardware failure?)
    if (std::cin.bad())
    {
        // if we're here we can't recover the cin stream
        // we only get here in case of catastrophic error so throw
        throw (std::runtime_error("cs50::get_string: error reading input"));
    }

    if (std::cin.eof() || std::cin.fail())
    {
        // reset cin flags, enabling further input
        std::cin.clear();

        // throw exception on bad input
        throw std::domain_error("cs50::get_string: bad input");
    }

    // if we're here all is ok so we return the input
    return str;
}
}
