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

        // if eof, failbit or badbit clear state and return 0
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
double get_double()
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
