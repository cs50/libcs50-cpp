#include <string>

namespace cs50
{

/** 
 * Creates a class in which the constructor cancels buffering for cout.
 * The class gets instantiated in cs50.cpp via a static member and, therefore,
 * it gets created before main() gets called. 
*/
 
class BeforeMain
{
	public:
		BeforeMain() 
		{ 
			std::cout.setf(std::ios::unitbuf); 
		}
};

/**
 * TODO
 */
void eprintf();

/**
 * TODO
 */
char get_char(void);

/**
 * Reads a line of text from standard input and returns the equivalent
 * double as precisely as possible; if text does not represent a
 * double or if value would cause underflow or overflow, user is
 * prompted to retry. If line can't be read or EOF, returns DBL_MAX.
 */
double get_double(void);

/**
 * Reads a line of text from standard input and returns the equivalent
 * float as precisely as possible; if text does not represent a
 * float or if value would cause underflow or overflow, user is
 * prompted to retry. If line can't be read or EOF, returns FLT_MAX.
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
 * reads a line of text from standard input and returns it as std::string. It
 * takes an optional bool pointer argument to signify EOF to the caller.
 * is_eof's default argument is NULL.
 * If input stream goes bad or read fails (should never happen barring hardware 
 * issues) throws std::runtime_error object. If EOF is read returns empty
 * string after setting the guard bool to true if applicable 
 */
std::string get_string(bool *is_eof = NULL);
}