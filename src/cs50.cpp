#include <iostream>
#include <string>

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
    // TODO
    static int num;
	string tmp = get_string();
	// check for correct format
	for (int i = 0; i != tmp.size(); ++i)
	{
		// no need for INT_MAX checking
		if (isalpha(tmp[i]))
		{
			cout << "please retry!" << endl;
			get_int();
		}
	}
	num = stoi(tmp);
	return num;
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
const string get_string(void)
{
    // TODO: check for failure
    // TODO: decide whether to return string or c_str
    static string tmp;
	getline(cin, tmp);
	
	if ((tmp.empty() || isspace(tmp[0])) && (tmp.size() != tmp.max_size()))
	{
		cout << "please retry!" << endl;
		get_string();
	}
    
    return tmp;
}

