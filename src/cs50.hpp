#include <iostream>
#include <string>
#include <limits>
#include <sstream>

namespace cs50
{
    template<typename T>
    T get(std::string const& prompt)
    {
        T i;
        for (;;)
        {
            auto stream = std::istringstream{get<std::string>(prompt)};

            // Read value of type T from stream
            if (stream >> std::noskipws >> i ) 
            {
                // Ensure `i` is not the maximum value of its type and that there
                // are no more characters in the stream after reading it
                if (i != std::numeric_limits<T>::max() && !stream.rdbuf()->in_avail()) {
                    return i;
                }
            }
            
            // Return maximum value of type T if there was an error/EOF when
            // reading stdin
            else if (std::cin.bad() || std::cin.eof())
            {
                return std::numeric_limits<T>::max();
            }

            if (prompt.empty())
            {
                std::cout << "Retry: ";
            }
        }
    }


    // Specialize get template for strings
    template<>
    std::string get(std::string const& prompt)
    {
        std::cout << prompt;
        for (;;)
        {
            std::string s;
            if (std::getline(std::cin, s))
            {
                // Remove trailing \r if present
                if (s.size() && s.back() == '\r')
                {
                    s.pop_back();
                }
                return s;
            }
            else
            {
                return std::string{};
            }
        }
    }

    struct Eprinter
    {
        Eprinter(char const *file, unsigned line)
        {
            std::cerr << file << ':' << line << ": ";
        }

        template<typename T>
        Eprinter& operator<<(T const& t)
        {
            std::cerr << t;
            return *this;
        }
    };

    // Not truly namespaced
    #define eout Eprinter(__FILE__, __LINE__)
}

