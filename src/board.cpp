#include "board.h"
#include "rng.h"

position::position(int32_t r, int32_t c) {
    row = r;
    column = c;
}

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
    return info.at(pos.row).at(pos.column);
}

template<typename T>
void board::random() {
    random_number_generator rng(13975);
    for(auto &line : info) {
        for(T &val : line) {
            val = rng(0, 100);
        }
    }
}

position board::size() {
    return position{rows, columns};
}
