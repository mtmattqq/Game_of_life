#ifndef PNG_H
#define PNG_H

#include <fstream>
#include <cstdint>
#include "board.h"

struct chunk {
    uint32_t length;
    std::vector<u_char> ctype;
    std::vector<u_char> data;
    uint32_t crc32;
};

std::ostream& operator<<(std::ostream &output, chunk c);

class png {
private :
    chunk header;
    std::vector<u_char> crc_table;
    void build_crc_table();
    uint32_t crc(std::vector<u_char>, std::vector<u_char>);

public :
    void gen(std::string, board);
    png();
    png(chunk);
};

#endif
