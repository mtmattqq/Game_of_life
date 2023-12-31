#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <cstdint>

struct position {
    int32_t row;
    int32_t column;
    position(int32_t, int32_t);
};

position operator+(position a, position b);

class board {
private :
    using vec = std::vector<double>;
    using mat = std::vector<vec>;
    mat info;
    uint32_t rows, columns;

public :
    board();
    board(uint32_t);
    board(uint32_t, uint32_t);

    double& operator[](position pos);
    void random();
    position size();
    bool in(position pos);
};

#endif
