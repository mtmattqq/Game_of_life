#include <iostream>
#include <deque>
#include <cmath>
#include <vector>
#include <functional>
#include "src/board.h"
#include "src/png.h"

void next_state(std::deque<board<double>> &states, std::function<double(double)> &weight, const int WIDTH, const int HEIGHT) {
    board<double> next(WIDTH, HEIGHT);
    const position surround[8]{
        (0, 1), (1, 0), (0, -1), (-1, 0),
        (1, 1), (1, -1), (-1, 1), (-1, -1)
    };
    
    uint32_t size = states.size();
    for(int i = 0; i < WIDTH; ++i) {
        for(int j = 0; j < HEIGHT; ++j) {
            position pos_now{i, j};
            double w = 0;
            for(int k = 0; k < size; ++k) {
                double p = 0;
                for(position &delta : surround) {
                    position pos_next = pos_now + delta;
                    if(states.at(size - k - 1).in(pos_next)) {
                        p += states.at(size - k - 1)[pos_next];
                    }
                }
                w += weight(p, k);
            }
            next[pos_next] = w;
        }
    }
    states.push_back(next);
    states.pop_front();
}

void polynomial(int n) {
    const int WIDTH = 20;
    const int HEIGHT = 10;
    board<double> begin(WIDTH, HEIGHT);

    begin.random();
    std::deque<board<double>> states(n, begin);
    const int ROUND = 100;
    
    std::function<double(double)> weight = [](double p, int i) {
        return pow(p / 8, i);
    }
    for(int i = 0; i < ROUND; ++i) {
        next_state(states, weight, WIDTH, HEIGHT);
    }
}

int main(void) {
    int n;
    std::cin >> n;
    polynomial(n);
    return 0;
}
