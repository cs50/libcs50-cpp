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
float get_float(void);

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
 * reads a line of text from standard input and returns it as std::string. It
 * takes an optional bool pointer argument to signify EOF to the caller.
 * is_eof's default argument is NULL.
 * If input stream goes bad or read fails (should never happen barring hardware 
 * issues) throws std::runtime_error object. If EOF is read returns empty
 * string after setting the guard bool to true if applicable 
 */
std::string get_string(bool *is_eof = NULL);

}
