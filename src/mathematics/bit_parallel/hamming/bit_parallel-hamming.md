# Closest Codes

**Technique:** bit-parallel Hamming distance (xor and popcount)

Time limit: 1 s
Memory limit: 256 MB

## Problem

You are given $n$ binary strings of length $m$. The Hamming distance of two strings is the number of positions where they differ. Print the minimum distance between any two distinct strings.

Pack each string into 64-bit words. The distance is the sum of `popcount(word_a xor word_b)` over those words. Do not walk every bit of every pair with a scalar inner loop.

## Input

The first line contains two integers $n$ and $m$ ($2 \le n \le 400$, $1 \le m \le 960$).

Each of the next $n$ lines contains a string of length $m$ consisting of `0` and `1`.

## Output

Print one integer: the minimum Hamming distance.

## Sample 1

Input:

```
3 5
00100
01100
11100
```

Output:

```
1
```

## Run

From the repository root, after writing `bit_parallel-hamming.student.cpp`:

```sh
./scripts/check.sh src/mathematics/bit_parallel/hamming
```

To run the reference solution instead:

```sh
./scripts/check.sh src/mathematics/bit_parallel/hamming --solution
```
