#include <climits>
#include <iostream>
#include <stdexcept>
#include <string>
#include <sstream>

#include "cs50.h"

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
 * Reads a line of text from standard input and returns the equivalent
 * char; if text does not represent a char, user is prompted to retry.
 * If eof or input stream corrupt (failed to read into string) returns
 * CHAR_MAX.
 */
char get_char()
{
    while (true)
    {
        std::string str;

        // attempt to read string input, on bad input return CHAR_MAX
        try
        {
            // a bool to handle EOF, passed to get_string by address
            bool eof;
            str = get_string(&eof);
            
            // if EOF was read we return our sentinel value here 
            if (eof)
            {
                return CHAR_MAX;
            }
        }
        catch (const std::domain_error& e)
        {
            return CHAR_MAX;
        }

        // return 1st char of str only if single char of input
        if (str.size() == 1)
        {
            return str[0];
        }
        
        // we're here if input was not exactly one char + newline
        std::cout << "Retry: ";
    }
}

/**
 * TODO
 */
double get_double()
{
    /**
    * TODO
    */
    return 0.0;
}

/**
 * TODO
 */
float get_float(void)
{
    // TODO
    return 0.0;
}

/**
 * Reads a line of text from standard input and returns the int value of the
 * string. If text does not represent an int user is prompted to retry. If eof
 * or input stream corrupt (failed to read into string) or int is out of range
 * returns INT_MAX.
 */
int get_int()
{
    // attempt to take an int from the user
    while (true)
    {
        std::string str;

        // attempt to read string input, on bad input return INT_MAX
        try
        {
            // a bool to handle EOF, passed to get_string by address
            bool eof;
            str = get_string(&eof);
            
            // if EOF was read we return our sentinel value here 
            if (eof)
            {
                return INT_MAX;
            }
        }
        catch (const std::runtime_error& e)
        {
            return INT_MAX;
        }

        // check if input has no whitespace at beginning
        if (str.length() > 0 && !isspace(str[0]))
        {
            std::istringstream iss(str);
            int ret;

            // return if iss successfully read into an int and iss exhausted
            if (iss >> ret && iss.eof())
            {
                return ret;
            }
        }

        // if we're here the input was not ok so reprompt
        std::cout << "Retry: ";
    }
}

/**
 * Reads a line of text from standard input and returns the equivalent long
 * long int; if string does not represent a long long int, user is prompted to
 * retry. If eof or input stream corrupt (failed to read into string) or out of
 * range returns LLONG_MAX.
 */
long long get_long_long()
{
    // attempt to take an int from the user
    while (true)
    {
        std::string str;

        // attempt to read string input, on bad input return LLONG_MAX
        try
        {
            // a bool to handle EOF, passed to get_string by address
            bool eof;
            str = get_string(&eof);
            
            // if EOF was read we return our sentinel value here 
            if (eof)
            {
                return LLONG_MAX;
            }
        }
        catch (const std::runtime_error& e)
        {
            return LLONG_MAX;
        }

        // check if there's input with no whitespace at the beginning
        if (str.length() > 0 && !isspace(str[0]))
        {
            std::istringstream iss(str);
            long long ret;

            // return when iss successfully read into long long & iss exhausted
            if (iss >> ret && iss.eof())
            {
                return ret;
            }
        }

        // if we're here the input was not ok so reprompt
        std::cout << "Retry: ";
    }
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
        if (is_eof)
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
    if (is_eof)
    { 
        *is_eof = false;
    }
    return str;
}

}
