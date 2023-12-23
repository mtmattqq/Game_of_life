#include "board.h"
#include "rng.h"

position::position(int32_t r, int32_t c) {
    row = r;
    column = c;
}

position operator+(position a, position b) {
    position ret(a.row + b.row, a.column + b.column);
    return ret;
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
    info = mat(r, vec(c));
    rows = r;
    columns = c;
}

double& board::operator[](position pos) {
    return info.at(pos.row).at(pos.column);
}

void board::random() {
    random_number_generater rng(13975);
    for(auto &line : info) {
        for(double &val : line) {
            val = rng(0, 100) / 100.0;
        }
    }
}

position board::size() {
    return position{rows, columns};
}
