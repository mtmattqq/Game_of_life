#ifndef PNG_H
#define PNG_H

#include <fstream>
#include <cstdint>
#include "board.h"

class png_generator {
private :
    const uint32_t header[] {137, 80, 78, 71, 13, 10, 26, 10};
    void gen(string, board);
public :
    void operator()(string, board);
};

#endif
