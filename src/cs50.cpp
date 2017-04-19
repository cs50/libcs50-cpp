#include <iostream>
#include <string>

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
char get_char(const std::string& prompt = std::string())
{
    // TODO
    return '\0';
}

/**
 * TODO
 */
double get_double(const std::string& prompt = std::string())
{
    // TODO
    return 0.0;
}

/**
 * TODO
 */
float get_float(const std::string& prompt = std::string())
{
    // TODO
    return 0.0;
}

/**
 * TODO
 */
int get_int(const std::string& prompt = std::string())
{
    // TODO
    return 0;
}

/**
 * TODO
 */
long long get_long_long(const std::string& prompt = std::string())
{
    // TODO
    return 0;
}

/**
 * TODO
 */
std::string get_string(const std::string& prompt = std::string())
{
    std::string s;
    std::getline(std::cin, s);
    return s;
}

}
