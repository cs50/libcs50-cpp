#include <iostream>
#include <string>
#include <climits>

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
 * NOTE perhaps state shouldn't be cleared in case of bad bit?
 * NOTE perhaps error should be thrown instead?
 */
char get_char()
{
    while (true)
    {
        std::string str;
        std::getline(std::cin, str);

        // if eof, failbit or badbit clear state and return CHAR_MAX
        if (std::cin.eof() || std::cin.fail())
        {
            std::cin.clear();
            return CHAR_MAX;
        }

        // return 1st char of s only if single char of input 
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
double get_double(void)
{
    // TODO
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
 * Reads a line of text from standard input and returns the equivalent
 * char; if text does not represent a char, user is prompted to retry.
 * If eof or input stream corrupt (failed to read into string) returns
 * INT_MAX.
 * NOTE perhaps state shouldn't be cleared in case of bad bit?
 * NOTE perhaps error should be thrown instead?
 * NOTE using C++11 range-based for loop and stoi standard library function
 * which should be replaced if compiling without C++11 flag
 * NOTE stoi will throw an std::out_of_range error, we just return INT_MAX
 * and prompt for a retry, perhaps cerr-ing a message about out of range
 * before reprompting would be more appropriate 
 */
int get_int()
{
    // attempt to take an int from the user
    while (true)
    {
        std::string str;
        std::getline(std::cin, str);

        // if eof, failbit or badbit clear state and return INT_MAX
        if (std::cin.eof() || std::cin.fail())
        {
            std::cin.clear();
            return INT_MAX;
        }

        // check if input is a valid integral number (digits only)
        bool validInput = true;
        // NOTE - this is a >= C++11 for loop
        for (auto i : str)
        {
            if (!isdigit(i))
            {
                validInput = false;
                break;
            }
        }

        // a C++97/C++03 for loop equivalent to above using iterators
        /*
        for (std::string::const_iterator i = str.begin(); i != str.end(); ++i)
        {
            if(!isdigit(*i))
            {
                validInput = false;
                break; 
            }
        }
        */

        // on correct input convert string to int (stoi is a C++11 function)
        if (validInput && str.size() > 0)
        {
            try
            {
                return std::stoi(str);
            }
            // in case of value exceeding int size
            catch (const std::exception&)
            {
                return INT_MAX;
            }
        }

        // if we're here the input was not ok so reprompt
        std::cout << "Retry: ";

    }
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
