#include "png.h"
namespace png {
    const uint32_t PNG_HEADER[] {137, 80, 78, 71, 13, 10, 26, 10};
    const chunk IHDR {
        4,
        "IHDR",
        {
            0, 0, 0x78, 0, // width
            0, 0, 0x43, 0x8, // height
            8, // bit depth
            0, // color type
            0, // compression method
            0, // filter method
            0 // interlace method
        },
        {}
    };

    void gen(std::string filename, board<double>) {
        std::ofstream output(filename, std::ios::binary);
        for(uint32_t word : PNG_HEADER) {
            output << word;
        }
    }
};