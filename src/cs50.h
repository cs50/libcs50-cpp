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
 * Leading and trailing whitespace is ignored. If input stream
 * corrupt (failed to read into string) returns CHAR_MAX.
 * NOTE perhaps state shouldn't be cleared in case of bad bit?
 * NOTE perhaps error should be thrown instead?
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
 * TODO
 */
int get_int(void);

/**
 * TODO
 */
long long get_long_long(void);

/**
 * TODO
 */
std::string get_string(void);

}
