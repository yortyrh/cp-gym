# Stars and Bars

**Technique:** stars and bars (non-negative integer solutions)

Time limit: 1 s
Memory limit: 256 MB

## Problem

For each pair $(n, k)$, print the number of non-negative integer solutions of
$x_1 + \cdots + x_k = n$, which is $\binom{n + k - 1}{k - 1}$.

## Input

The first line contains one integer $q$ ($1 \le q \le 100$).

Each of the next $q$ lines contains two integers $n$ and $k$ ($0 \le n \le 40$, $1 \le k \le 40$).

## Output

For each pair, print the number of solutions.

## Sample 1

Input:

```
3
3 2
0 5
5 1
```

Output:

```
4
1
1
```

## Run

From the repository root, after writing `stars_and_bars.student.cpp`:

```sh
./scripts/check.sh src/mathematics/stars_and_bars
```

To run the reference solution instead:

```sh
./scripts/check.sh src/mathematics/stars_and_bars --solution
```
