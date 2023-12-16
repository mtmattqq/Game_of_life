#ifndef PNG_H
#define PNG_H

#include <fstream>
#include <cstdint>
#include "board.h"

namespace png {
    struct chunk {
        uint32_t length;
        std::string ctype;
        std::vector<unsigned char> data;
        std::vector<unsigned char> crc32;
    };

    template<typename T> void gen(std::string, board<T>);
};

#endif
