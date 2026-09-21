# Equal Candle Lengths

**Technique:** binary search the answer

Time limit: 1 s
Memory limit: 256 MB

## Problem

You have $n$ wax sticks of integer lengths $\ell_0, \ell_1, \ldots, \ell_{n-1}$. You want to cut $k$ candles of the same integer length $L$. From a stick of length $\ell$ you may cut $\lfloor \ell / L \rfloor$ candles; leftover wax is discarded. Sticks cannot be glued together.

Find the maximum $L$ for which at least $k$ candles can be cut. If even $L = 1$ is impossible, print $0$.

The predicate "we can cut $k$ candles of length $L$" is monotone in $L$. Binary-search $L$ on that predicate. Do not try every possible length from the maximum stick downward.

## Input

The first line contains two integers $n$ and $k$ ($1 \le n \le 10^5$, $1 \le k \le 10^9$).

The second line contains $n$ integers $\ell_i$ ($1 \le \ell_i \le 10^9$).

## Output

Print one integer: the maximum candle length, or $0$.

## Sample 1

Input:

```
3 4
8 5 3
```

Output:

```
3
```

## Run

From the repository root, after writing `binary_search-on_answer.student.cpp`:

```sh
./scripts/check.sh src/searching/binary_search/on_answer
```

To run the reference solution instead:

```sh
./scripts/check.sh src/searching/binary_search/on_answer --solution
```
