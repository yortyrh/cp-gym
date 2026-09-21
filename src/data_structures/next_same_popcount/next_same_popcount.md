# Next Integer With the Same Popcount

**Technique:** Gosper's hack (next number with the same number of 1-bits)

Time limit: 1 s
Memory limit: 256 MB

## Problem

You are given $n$ positive integers. For each $x$, print the smallest integer strictly greater than $x$ that has the same number of `1`-bits in its binary representation.

Use Gosper's hack. Let `lowest` be the lowest set bit of $x$. Then

```
ripple = x + lowest
ones = (ripple ^ x) >> 2
next = ripple | (ones / lowest)
```

Do not scan $x+1, x+2, \ldots$ until the popcount matches.

## Input

The first line contains one integer $n$ ($1 \le n \le 2 \cdot 10^5$).

The second line contains $n$ integers $x_1, x_2, \ldots, x_n$ ($1 \le x_i \le 10^{18}$). Every next value fits in a signed 64-bit integer.

## Output

Print $n$ lines. Line $i$ contains the next integer after $x_i$ with the same popcount.

## Sample 1

Input:

```
5
3 5 6 1 12
```

Output:

```
5
6
9
2
17
```

## Run

From the repository root, after writing `next_same_popcount.student.cpp`:

```sh
./scripts/check.sh src/data_structures/next_same_popcount
```

To run the reference solution instead:

```sh
./scripts/check.sh src/data_structures/next_same_popcount --solution
```
