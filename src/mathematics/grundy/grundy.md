# Token Subtraction

**Technique:** Sprague-Grundy numbers on an impartial subtraction game

Time limit: 1 s
Memory limit: 256 MB

## Problem

There are $n$ independent piles of tokens. A move chooses one pile and subtracts a value from a fixed set $S$, provided the pile does not go negative. The player who cannot move loses. Both play optimally.

Compute Grundy numbers for a single pile: `g[0] = 0` and `g[x]` is the mex of `g[x - d]` over $d \in S$ with $d \le x$. The full position is the xor of the pile Grundy numbers. A nonzero xor is a first-player win.

## Input

The first line contains two integers $n$ and $s$ ($1 \le n \le 10^5$, $1 \le s \le 20$).

The second line contains $s$ distinct integers, the allowed subtractions ($1 \le d \le 100$).

The third line contains $n$ integers, the pile sizes ($0 \le a_i \le 10^5$).

## Output

Print `First` if the first player wins, otherwise `Second`.

## Sample 1

Input:

```
3 2
1 2
3 4 5
```

Output:

```
First
```

## Run

From the repository root, after writing `grundy.student.cpp`:

```sh
./scripts/check.sh src/mathematics/grundy
```

To run the reference solution instead:

```sh
./scripts/check.sh src/mathematics/grundy --solution
```
