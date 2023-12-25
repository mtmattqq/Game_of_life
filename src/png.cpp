#include "png.h"
#include <iomanip>
#include <iostream>

const u_char PNG_HEADER[] {
    0x89, 0x50, 0x4E, 0x47, 0x0D, 
    0x0A, 0x1A, 0x0A
};
const chunk IHDR {
    13,
    {0x49, 0x48, 0x44, 0x52},
    {
        0, 0, 0x78, 0, // width
        0, 0, 0x43, 0x8, // height
        8, // bit depth
        0, // color type
        0, // compression method
        0, // filter method
        0  // interlace method
    },
    0
};
chunk IEND  {
    0,
    {0x49, 0x45, 0x4E, 0x44}
};

std::ostream& print(std::ostream &output, uint32_t num) {
    std::vector<u_char> data;
    for(int i = 0; i < 4; ++i) {
        data.push_back(num & 0xff);
        num >>= 8;
    }
    for(int i = 3; i >= 0; --i) {
        output << data[i];
    }
    return output;
}

std::ostream& operator<<(std::ostream &output, chunk c) {
    print(output, c.length);
    for(u_char word : c.ctype) {
        output << word;
    }
    for(u_char word : c.data) {
        output << word;
    }
    print(output, c.crc32);
    return output;
}

void png::gen(std::string filename, board bd) {
    std::ofstream output(filename, std::ios::binary);
    for(u_char word : PNG_HEADER) {
        output << word;
    }
    header.crc32 = crc(header.ctype, header.data);

    std::cerr << header.crc32 << "\n";
    output << header;
    chunk IBIT {
        0,
        {0x73, 0x42, 0x49, 0x54}
    };

    const std::vector<u_char> IDAT{0x49, 0x44, 0x41, 0x54};
    for(int i = 0; i < bd.size().row; ++i) {
        for(int j = 0; j < bd.size().column; ++j) {
            position now(i, j);
            chunk data {
                1,
                IDAT,
                {},
                {}
            };
            u_char color = (u_char) ((1.0 - bd[now]) * 255);
            data.data.push_back(color);
            data.crc32 = crc(data.ctype, data.data);
            output << data;
        }
    }
    IEND.crc32 = crc(IEND.ctype, IEND.data);
    output << IEND;
    return;
}

void png::build_crc_table() {
    crc_table.resize(256);
    for(int n = 0; n < 256; ++n) {
        uint32_t c = (uint32_t) n;
        for(int k = 0; k < 8; ++k) {
            if(c & 1) {
                c = 0xedb88320L ^ (c >> 1);
            } else {
                c >>= 1;
            }
        }
        crc_table[n] = c;
    }
}

png::png() {
    header = IHDR;
    build_crc_table();
}

png::png(chunk _header) {
    header = _header;
    build_crc_table();
}

uint32_t png::crc(std::vector<u_char> buf, std::vector<u_char> buf2) {
    uint32_t ret = 0xffffffffL;
    for(int n = 0; n < buf.size(); ++n) {
        ret = crc_table[(ret ^ buf[n]) & 0xff] ^ (ret >> 8);
    }
    for(int n = 0; n < buf2.size(); ++n) {
        ret = crc_table[(ret ^ buf2[n]) & 0xff] ^ (ret >> 8);
    }
    return ret;
}