# Fibonacci Fast Doubling

**Technique:** Fibonacci via fast doubling

Time limit: 1 s
Memory limit: 256 MB

## Problem

For each pair $(n, m)$, print $F_n \bmod m$, where $F_0 = 0$, $F_1 = 1$.

From $(F_k, F_{k+1})$ derive
$F_{2k} = F_k (2 F_{k+1} - F_k)$ and $F_{2k+1} = F_k^2 + F_{k+1}^2$,
all modulo $m$. Recurse on $\lfloor n/2 \rfloor$. Do not fill a linear DP table.

## Input

The first line contains one integer $q$ ($1 \le q \le 10^4$).

Each of the next $q$ lines contains two integers $n$ and $m$ ($0 \le n \le 10^{18}$, $1 \le m \le 10^9 + 7$).

## Output

For each pair, print $F_n \bmod m$.

## Sample 1

Input:

```
4
0 7
1 7
10 7
10 1000
```

Output:

```
0
1
6
55
```

## Run

From the repository root, after writing `fibonacci.student.cpp`:

```sh
./scripts/check.sh src/mathematics/fibonacci
```

To run the reference solution instead:

```sh
./scripts/check.sh src/mathematics/fibonacci --solution
```
