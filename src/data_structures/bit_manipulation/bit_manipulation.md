# Bit Tricks on 64-bit Words

**Technique:** bit manipulation (popcount, trailing zeros, bit width, lowest set bit)

Time limit: 1 s
Memory limit: 256 MB

## Problem

You are given $n$ non-negative integers. For each value $x$ print four numbers on one line:

- the number of `1`-bits in $x$ (popcount)
- the number of trailing zeros in the binary representation of $x$ (for $x = 0$ print `64`)
- the bit width of $x$: $0$ if $x = 0$, otherwise $\lfloor \log_2 x \rfloor + 1$
- the lowest set bit of $x$, that is $x \mathbin{\&} (\sim x + 1)$ (for $x = 0$ print `0`)

Use constant-time bit operations. Do not loop over all 64 bits of every $x$.

## Input

The first line contains one integer $n$ ($1 \le n \le 2 \cdot 10^5$).

The second line contains $n$ integers $x_1, x_2, \ldots, x_n$ ($0 \le x_i \le 10^{18}$).

## Output

Print $n$ lines. Line $i$ contains four integers: popcount, trailing zeros, bit width, and lowest set bit of $x_i$.

## Sample 1

Input:

```
5
13 12 0 1 8
```

Output:

```
3 0 4 1
2 2 4 4
0 64 0 0
1 0 1 1
1 3 4 8
```

## Run

From the repository root, after writing `bit_manipulation.student.cpp`:

```sh
./scripts/check.sh src/data_structures/bit_manipulation
```

To run the reference solution instead:

```sh
./scripts/check.sh src/data_structures/bit_manipulation --solution
```
