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
