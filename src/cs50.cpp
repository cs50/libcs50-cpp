#include <iostream>
#include <stdexcept>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#include <errno.h>
#include <stdio.h> // for sscanf
#include <float.h> // for FLT_MIN and FLT_MAX
#include <math.h> // for isfinite
// using the namespace std just for development
using namespace std;
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
    while (true)
    {
        // get line of text, returning CHAR_MAX on failure
        const char* local = get_string();
        static char c; // just a placeholder
		
		// return a char if only a char was provided
        if (strlen(local) > 0 && strlen(local) <= 1 && isalpha(local[0]) && local)
        {
           	c = local[0]; 
        	return c;
        	
        }
        if (strlen(local) > 0 && *local == '\0')
        {
        	return CHAR_MAX;
        	
        }
        cout << "Retry: " << endl;
    }
}

/**
 * TODO
 */
double get_double(void)
{
    while (true)
    {
        // get line of text, returning DBL_MAX on failure
        const char* local = get_string();
        static double d;
        if (strlen(local) > 0 && *local)
        {
            static char* tail;
            errno = 0;;
            d = strtod(local, &tail);
            if (errno == 0 && *tail == '\0' && isfinite(d) != 0 && d < DBL_MAX)
            {
                if (strcspn(local, "XxEePp") == strlen(local))
                {
                    return d;
                }
            }
        }
        //if there is something in the string but buffer is full, return the max double value
        if (strlen(local) > 0 && *local == '\0')
        {
         	return DBL_MAX;
        }
        printf("Retry: ");
}

/**
 * TODO
 */
float get_float(void)
{
    while (true)
	{
		const char* local = get_string();
		static float flt; // a placeholder
		
		if (strlen(local) > 0 && atof(local) && local)
		{
			flt = atof(local);
			if (flt >= FLT_MIN || flt < FLT_MAX) // check for being in valid range
			{
				return flt;
            }
			else
			{
				return FLT_MAX;
            }
			// dissalow hex input format as done in C lib...TODO
		}
		cout << "Retry: " << endl;
	}
}

/**
 * TODO
 */
int get_int(void)
{
    // TODO
    while (true)
	{
		const char* local = get_string();
		static long tmp; // long, since stoi in not c++99 compatib
		
		if (strlen(local) > 0 && local)
		{
			static char* tail = NULL;              // number base is 10
			tmp = strtol(local, &tail, 10); // tail takes care of iterating to the NULL, strtol has a looping construct
			if (errno == 0 && *tail == '\0' && tmp >= INT_MIN && tmp < INT_MAX)
			{
				return tmp;
			}

		}
		if (strlen(local) > 0 && local == '\0')
		{
			return INT_MAX;
		}
		// this will be prompt out in case if nothing is entered, just hit ENTER 
		std::cout << "Retry: " << std::endl;
	}
}

/**
 * TODO
 */
long long get_long_long(void)
{
    while (true)
    {
        // get line of text, returning LLONG_MAX on failure
        const char* local = get_string();
        static long long n;
        
        if (strlen(local) && local)
        {
            char* tail;
            errno = 0;
            n = strtoll(local, &tail, 10);
            if (errno == 0 && *tail == '\0' && n < LLONG_MAX)
            {
                return n;
            }
        }
        printf("Retry: ");
    }
}

/**
 * TODO
 */
 // acts like a parser for the other methods yet to follow
// discarding whitespace characters is done in get_string
char* get_string(void)
{
    // TODO: check for failure
    // TODO: decide whether to return string or c_str
        std::string s;
	getline(std::cin, s);
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
	// I have a problem when input is isneted with spaces...do something to cut off the whitespaces
	static int len = s.length();
	char* str_tmp = new char(len + 1);
	strcpy(str_tmp, s.c_str());
	// make a cut off
	static char* str; 
	while (isspace(*str_tmp) && *str_tmp != '\0') // while not space and *str_tmp != NULL
	{
		(void)*str_tmp++;
	}
	// now share a pointee
	str = str_tmp; // you should clean the str 
	// return without the leading whitespace 
	return str;
}

}
