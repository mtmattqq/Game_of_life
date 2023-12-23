#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <cstdint>

struct position {
    int32_t row;
    int32_t column;
    position(int32_t, int32_t);
};

template<typename T>
class board {
private :
    using vec = std::vector<T>;
    using mat = std::vector<vec>;
    mat info;
    uint32_t rows, columns;

public :
    board();
    board(uint32_t);
    board(uint32_t, uint32_t);

    T& operator[](position pos);
    void random();
    position size();
};

#endif
