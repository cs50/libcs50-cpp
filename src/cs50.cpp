#include <cfloat>
#include <cstdlib>
#include <cstring>
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
 * prompted to retry. If line can't be read or EOF, returns DBL_MAX.
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
            // a bool to handle EOF, passed to get_string by address
            bool eof;
            str = get_string(&eof);
            // if EOF was read we return our sentinel value here 
            if (eof)
            {
                return DBL_MAX;
            }
        }
        catch (const std::runtime_error&)
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
 * prompted to retry. If line can't be read or EOF, returns FLT_MAX.
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
            // a bool to handle EOF, passed to get_string by address
            bool eof;
            str = get_string(&eof);
            // if EOF was read we return our sentinel value here 
            if (eof)
            {
                return FLT_MAX;
            }
        }
        catch (const std::runtime_error&)
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
 * reads a line of text from standard input and returns it as std::string. It
 * takes an optional bool pointer argument to signify EOF to the caller.
 * is_eof's default argument is NULL (set in the header).
 * If input stream goes bad or read fails (should never happen barring hardware 
 * issues) throws std::runtime_error object. If EOF is read returns empty
 * string after setting the guard bool to true if applicable 
 */
std::string get_string(bool *is_eof)
{
    std::string str;

    // attempt to read string input into str
    std::getline(std::cin, str);

    // handle EOF, input fail and bad input, clear cin error flags
    if (std::cin.eof())
    {
        // reset cin flags to enable further input
        std::cin.clear();

        // if is_eof was passed to function set bool to true on EOF
        if (is_eof != NULL)
        {
            *is_eof = true;
        }
        return std::string();
    }
    else if (std::cin.fail())
    {
        // reset cin flags to enable further input
        std::cin.clear();

        // throw exception on bad input
        throw std::runtime_error("cs50::get_string: error reading input");
    }
    else if (std::cin.bad())
    {
        // if we're here we can't recover the cin stream
        // we only get here in case of catastrophic error so throw
        throw std::runtime_error("cs50::get_string: error reading input");
    }

    // if we're here all is ok so we set the bool, if passed, and return
    if (is_eof != NULL)
    { 
        *is_eof = false;
    }
    return str;
}
}
