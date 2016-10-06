#include <cerrno>
#include <cfloat>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>

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
 * Reads a line of text from standard input and returns it as a std::string;
 * The function is used internally for reading input and handling console input
 * stream errors. If eof or input stream corrupt (failed to read into string).
 * The argument passed to bool *ok is used to check for eof or bad string input
 * so it's set to false when read fails or is in eof state, and set to true
 * otherwise.
 */
std::string read_input(bool *ok)
{
    std::string str;

    // attempt to read string input into s
    std::getline(std::cin, str);

    // check if input stream in bad state (hardware failure?)
    if (std::cin.bad())
    {
        // if we're here we can't recover the cin stream
        // we only get here in case of catastrophic error so throw
        throw (std::runtime_error("cs50::input_string: error reading input"));
    }

    if (std::cin.eof() || std::cin.fail())
    {
        // report bad string input via side-effect and clear cin flags
        *ok = false;
        std::cin.clear();
        return std::string();
    }

    // if we're here all is ok so we set sentinel to true and return the input
    *ok = true;
    return str;
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
        bool valid;
        std::string str = read_input(&valid);
        // if eof or error return DBL_MAX
        if(!valid)
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
        bool valid;
        std::string str = read_input(&valid);
        // if eof or error, return FLT_MAX
        if(!valid)
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
 * TODO
 */
std::string get_string(void)
{
    // TODO: decide whether to return string or c_str
    bool valid;
    std::string s = read_input(&valid);

    // return empty string on invalid input
    if (valid == false)
    {
        return std::string();
    }
    return s;
}
}
