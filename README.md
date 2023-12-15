# Game_of_life

A variation of game of life.

## Rules

The original conway's game of life uses only previous one state to determine the current state. However, in the project, I'll use the previous $N$ state with different weight.

## Weight function

Let weight function be W().

### Polynomial

Use the previous $N$ state. For each block, let the number surrounding block in the previous $i$'th state be $P_{N - i}$. Let $W(P) = {\displaystyle\sum_{i = 1}^{N}{P_{i}^i} \over \displaystyle\sum_{i = 1}^{N}{8^i}}$
