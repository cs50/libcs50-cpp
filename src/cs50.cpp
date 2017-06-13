#include "cs50.hpp"

struct BufferingDisabler
{
    BufferingDisabler()
    {
        // Should we make EOF/read errors exceptions?
        //std::cin.exceptions(std::ios_base::eofbit | std::ios_base::badbit);
        std::cout.setf(std::ios::unitbuf);
    }
};

static BufferingDisabler _disable_buffering;
