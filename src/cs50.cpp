#include <cerrno>
#include <cfloat>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iostream>
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
        std::string str = get_string();

        // if eof, failbit or badbit return DOUBLE_MAX
        if (str[0] == '\0')
        {
            return DBL_MAX;
        }

        // validate input 
        if(!isspace(str[0])) 
        {
            char* tail;
            errno = 0;
            double d = strtod(str.c_str(), &tail);
            if (errno == 0 && *tail == '\0' && d > DBL_MIN && d < DBL_MAX)
            {
                // disallow hexadecimal and exponents
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
        std::string str = get_string();

        // if eof, failbit or badbit return DOUBLE_MAX
        if (str[0] == '\0')
        {
            return FLT_MAX;
        }

        // validate input 
        if(!isspace(str[0])) 
        {
            char* tail;
            errno = 0;
            float f = strtod(str.c_str(), &tail);
            if (errno == 0 && *tail == '\0' && f > FLT_MIN && f < FLT_MAX)
            {
                // disallow hexadecimal and exponents
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
    // TODO: check for failure
    // TODO: decide whether to return string or c_str
    std::string s;
    std::getline(std::cin, s);
    return s;
}

}
