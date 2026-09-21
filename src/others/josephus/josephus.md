# Josephus Position

**Technique:** Josephus recurrence f(n) = (f(n-1)+k) mod n

Time limit: 1 s
Memory limit: 256 MB

## Problem

$n$ people numbered $0..n-1$ stand in a circle. Counting starts at $0$; every $k$-th remaining person is eliminated until one remains. Print the $0$-based index of the survivor.

The iterative recurrence is $f(1) = 0$, $f(i) = (f(i-1) + k) \bmod i$ for $i = 2..n$.

## Input

The first line contains one integer $q$ ($1 \le q \le 10^5$).

Each of the next $q$ lines contains two integers $n$ and $k$ ($1 \le k \le n \le 10^6$). The sum of $n$ over all queries is at most $10^6$.

## Output

For each query, print the survivor index.

## Sample 1

Input:

```
2
5 2
1 1
```

Output:

```
2
0
```

## Run

From the repository root, after writing `josephus.student.cpp`:

```sh
./scripts/check.sh src/others/josephus
```

To run the reference solution instead:

```sh
./scripts/check.sh src/others/josephus --solution
```
