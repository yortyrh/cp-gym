# Stone Heaps

**Technique:** Nim xor (first / second player)

Time limit: 1 s
Memory limit: 256 MB

## Problem

Two players play Nim on $n$ heaps. A turn consists of choosing one heap and removing at least one stone from it. The player who takes the last stone wins. Both play optimally.

The xor of the heap sizes is a complete description of the position. If it is nonzero, the first player wins; if it is zero, the second player wins.

## Input

The first line contains one integer $n$ ($1 \le n \le 10^5$).

The second line contains $n$ integers $a_1, \ldots, a_n$ ($0 \le a_i \le 10^9$), the heap sizes.

## Output

Print `First` if the first player wins, otherwise `Second`.

## Sample 1

Input:

```
3
1 2 3
```

Output:

```
Second
```

## Run

From the repository root, after writing `nim.student.cpp`:

```sh
./scripts/check.sh src/mathematics/nim
```

To run the reference solution instead:

```sh
./scripts/check.sh src/mathematics/nim --solution
```
