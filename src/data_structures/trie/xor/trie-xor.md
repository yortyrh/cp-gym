# Maximum XOR Pair

**Technique:** binary trie (maximum XOR of two numbers)

Time limit: 1 s
Memory limit: 256 MB

## Problem

You are given $n$ non-negative integers. Print the maximum value of $a_i \oplus a_j$ over all pairs $1 \le i < j \le n$, where $\oplus$ is bitwise XOR.

Insert the numbers into a binary trie of 31 bits (bit $30$ down to bit $0$), most significant bit first. For each number, walk the trie preferring the opposite bit at every level; that walk yields the maximum XOR with any already stored number.

Do not test every pair.

## Input

The first line contains one integer $n$ ($2 \le n \le 2 \cdot 10^5$).

The second line contains $n$ integers $a_1, a_2, \ldots, a_n$ ($0 \le a_i \le 10^9$).

## Output

Print one integer: the maximum XOR of any two elements.

## Sample 1

Input:

```
5
3 10 5 25 2
```

Output:

```
28
```

## Run

From the repository root, after writing `trie-xor.student.cpp`:

```sh
./scripts/check.sh src/data_structures/trie/xor
```

To run the reference solution instead:

```sh
./scripts/check.sh src/data_structures/trie/xor --solution
```
