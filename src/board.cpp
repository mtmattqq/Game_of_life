#include "board.h"

board::board() {
    info = mat(0, vec(0));
    rows = 0;
    columns = 0;
}

board::board(const uint32_t n) {
    info = mat(n, vec(n));
    rows = columns = n;
}

board::board(const uint32_t r, const uint32_t c) {
    info = mat(row, vec(column));
    rows = r;
    columns = c;
}

template<typename T>
T& board::operator[](position pos) {
    return info[pos.row][pos.column];
}

position board::size() {
    return position{rows, columns};
}
