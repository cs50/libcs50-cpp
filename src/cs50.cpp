#include <iostream>
#include <stdexcept>
#include <string.h>
#include <stdlib.h>
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
char get_char(void)
{
    // TODO
    return '\0';
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
 * TODO
 */
int get_int(void)
{
    while (true)
	{
		char* local = get_string();
		if (local == NULL)
		{
			return INT_MAX;
		}
		if (strlen(local) > 0 && !isspace(local[0]))
		{
			char* tail;
			long tmp = strtol(local, &tail, 10);
			if (*tail == NULL && tmp >= INT_MIN && tmp < INT_MAX)
			{
				return tmp;
			}
		}
		std::cout << "retry!" << std::endl;
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


std::string get_string(void)
{
    // TODO: check for failure
    // TODO: decide whether to return string or c_str
    std::string s;
    std::getline(std::cin, s);
   // check for failure on string class 
	if(!std::cin.good()) // if not good
	{
		throw std::invalid_argument("Something went wrong");
	}
	else if(std::cin.eof()) // if not enough memory
	{
		std::cout << "EOF" << std::endl;
		throw std::invalid_argument("EOF");
	}
	// do the conversion c_str
	static int len = s.length();
	char* str = new char(len + 1);
	strcpy(str, s.c_str());
	
	return str;
}

}
