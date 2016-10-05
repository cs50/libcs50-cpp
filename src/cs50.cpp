#include <climits>
#include <iostream>
#include <regex>
#include <string>

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
        std::string str = get_string();

        // if eof, failbit or badbit clear state and return CHAR_MAX
        if (std::cin.eof() || std::cin.fail())
        {
            std::cin.clear();
            return CHAR_MAX;
        }

        // return 1st char of str only if single char of input 
        else if (str.size() == 1)
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
        std::string str = get_string();

        // if eof, failbit or badbit clear state and return INT_MAX
        if (std::cin.eof() || std::cin.fail())
        {
            std::cin.clear();
            return INT_MAX;
        }

        // regex for 0 or 1 + or -, followed by one or more digits
        std::regex re("[+-]?\\d+");

        // on digits-only input attempt to convert string to int
        if (std::regex_match(str, re))
        {
            try
            {
                return std::stoi(str);
            }
            // in case of value exceeding int size do nothing and reprompt
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
 * Reads a line of text from standard input and returns the equivalent long
 * long int; if string does not represent a long long int, user is prompted to
 * retry. If eof or input stream corrupt (failed to read into string) or int
 * out of range returns LLONG_MAX.
 */
long long get_long_long()
{
    while (true)
    {
        std::string str = get_string();

        // if eof, failbit or badbit clear state and return LLONG_MAX
        if (std::cin.eof() || std::cin.fail())
        {
            std::cin.clear();
            return LLONG_MAX;
        }

        // regex for 0 or 1 + or -, followed by one or more digits
        std::regex re("[+-]?\\d+");

        // on digits-only input attempt to convert string to long long int
        if (std::regex_match(str, re))
        {
            try
            {
                return std::stoll(str);
            }
            // in case of value exceeding int size do nothing and reprompt
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
std::string get_string(void)
{
    // TODO: check for failure
    // TODO: decide whether to return string or c_str
    std::string s;

    // attempt to read string input into s, report error if failed
    try
    {
        std::getline(std::cin, s);
        while (true) {
            s += s;
        }
    }
    catch (const std::exception& e)
    {
        // report error and rethrow in case someone's handling it downstream
        std::cerr << e.what() << std::endl;
        throw e;
    }

    // check if input stream in bad state (hardware failure?)
    if (std::cin.bad())
    {
        // NOTE - stream not cleared here for eof/fail checks downstream
        // if we're here we can't recover the cin stream
        std::cerr << "cs50 get_string error: cannot read input!\n";
        // we only get here in case of catastrophic error so throw
        throw (std::runtime_error("error reading input"));
    }

    return s;
}

}
