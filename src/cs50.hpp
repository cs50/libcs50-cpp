#include <iostream>
#include <string>
#include <limits>
#include <string_view>

namespace cs50 {
    template<typename T>
    T get(std::string_view prompt = std::string_view()) {
        if (prompt.size()) {
            std::cout << prompt;
        }

        for (;;) {
            T i;
            if (std::cin >> std::noskipws >> i && i != std::numeric_limits<T>::max())
            {
                return i;
            } 
            else if (std::cin.bad() || std::cin.eof())
            {
                return std::numeric_limits<T>::max();
            } 
            else 
            {
                std::cout << (prompt.empty() ? "Retry: " : prompt);

                // Clear fail bit
                std::cin.clear();

                // Skip until next line
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }
    }

    // Specialize get template for strings
    template<>
    std::string get(std::string_view prompt) {
        if (prompt.size()) {
            std::cout << prompt;
        }

        for (;;) {
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
                return std::string();
            }
        }
    }

    struct Eprinter {
        Eprinter(char const *file, unsigned line)
        {
            std::cerr << file << ':' << line << ": ";
        }

        template<typename T>
         Eprinter &operator<<(T const& t)
         {
             std::cerr << t;
             return *this;
         }
    };

    // Not truly namespaced
    #define eprint Eprinter(__FILE__, __LINE__)
}

