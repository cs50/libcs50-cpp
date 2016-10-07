#include <string>

namespace cs50
{

/**
 * TODO
 */
void eprintf();

/**
 * Reads a line of text from standard input and returns the equivalent
 * char; if text does not represent a char, user is prompted to retry.
 * If eof or input stream corrupt (failed to read into string) returns
 * CHAR_MAX.
 */
char get_char();

/**
 * TODO
 */
double get_double();

/**
 * TODO
 */
float get_float();

/**
 * Reads a line of text from standard input and returns the equivalent
 * char; if text does not represent a char, user is prompted to retry.
 * If eof or input stream corrupt (failed to read into string) returns
 * INT_MAX.
 */
int get_int();

/**
 * Reads a line of text from standard input and returns the equivalent
 * char; if text does not represent a char, user is prompted to retry.
 * If eof or input stream corrupt (failed to read into string) returns
 * INT_MAX.
 */
long long get_long_long();

/**
 * reads a line of text from standard input and returns it as std::string. If
 * input is invalid it returns an empty std::string.
 */
std::string get_string();

}
