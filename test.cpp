#include "src/png.h"

int main(void) {
    chunk header {
        13,
        {0x49, 0x48, 0x44, 0x52},
        {
            0, 0, 0, 0x1, // width
            0, 0, 0, 0x1, // height
            8, // bit depth
            0, // color type
            0, // compression method
            0, // filter method
            0  // interlace method
        },
        0
    };

    png unit_picture(header);
    board unit_picture_board(1);
    unit_picture_board[{0, 0}] = 0;
    unit_picture.gen("test.png", unit_picture_board);

}