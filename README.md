# Game_of_life

A variation of game of life.

## Rules

The original conway's game of life uses only previous one state to determine the current state. However, in the project, I'll use the previous $N$ state with different weight.

## Weight function

### Polynomial

Use the previous $N$ state. For each block, let the number surrounding block in the previous $i$'th state be $p_{n - i}$. Let 
