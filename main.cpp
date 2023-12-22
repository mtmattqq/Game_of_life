#include <iostream>
#include <deque>
#include "src/board.h"
#include "src/pnh.h"

void next_state(deque<board> states) {
    ;
}

void polynomial(int n) {
    const int WIDTH = 20;
    const int HEIGHT = 10;
    board begin(WIDTH, HEIGHT);
    
    begin.random();
    deque<board> states(n, begin);
    const int ROUND = 100;

    for(int i = 0; i < ROUND; ++i) {
        next_state(states);
    }
}

int main(void) {
    int n;
    std::cin >> n;
    polynomial(n);
    return 0;
}
