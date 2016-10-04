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
char get_char(void);

/**
 * TODO
 */
double get_double(void);

/**
 * TODO
 */
float get_float(void);

/**
 * Reads a line of text from standard input and returns the equivalent
 * char; if text does not represent a char, user is prompted to retry.
 * If eof or input stream corrupt (failed to read into string) returns
 * INT_MAX.
 */
int get_int(void);

/**
 * Reads a line of text from standard input and returns the equivalent
 * char; if text does not represent a char, user is prompted to retry.
 * If eof or input stream corrupt (failed to read into string) returns
 * INT_MAX.
 */
long long get_long_long(void);

/**
 * TODO
 */
std::string get_string(void);

}
