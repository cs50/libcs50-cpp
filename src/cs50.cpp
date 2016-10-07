#include <climits>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>

#include "cs50.h"

namespace cs50
{

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
        // sentinel bool, false on EOF or failed reading of input
        bool valid;
        std::string str = read_input(&valid);

        // on EOF, bad string input
        if (valid == false)
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
float get_float()
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
        bool valid;
        std::string str = read_input(&valid);

        // on bad string input (EOF)
        if (!valid)
        {
            return INT_MAX;
        }

        // check if there's input with no whitespace at beginning
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
        bool valid;
        std::string str = read_input(&valid);

        // on bad string input (EOF)
        if (!valid)
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
 * reads a line of text from standard input and returns it as std::string. If
 * input is invalid it returns an empty std::string.
 */
std::string get_string()
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
