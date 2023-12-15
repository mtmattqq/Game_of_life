#include <vector>
#include <cstdint>

struct position {
    uint32_t row;
    uint32_t column;
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
    position size();
};
