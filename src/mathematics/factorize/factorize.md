# Prime Factorization

**Technique:** integer factorization by trial division

Time limit: 1 s
Memory limit: 256 MB

## Problem

Factor each $n > 1$ as $n = p_1^{e_1} p_2^{e_2} \cdots p_k^{e_k}$ with increasing primes. If $n = 1$, there are no prime powers.

Trial-divide up to $\sqrt{n}$. SPF / linear sieve is not required; this exercise is factorization, not sieving.

## Input

The first line contains one integer $q$ ($1 \le q \le 10^4$).

Each of the next $q$ lines contains one integer $n$ ($1 \le n \le 10^{12}$).

## Output

For each $n$, print $k$ — the number of distinct prime factors — then $k$ lines $p_i$ $e_i$ in increasing $p_i$.

## Sample 1

Input:

```
3
12
7
1
```

Output:

```
2
2 2
3 1
1
7 1
0
```

## Run

From the repository root, after writing `factorize.student.cpp`:

```sh
./scripts/check.sh src/mathematics/factorize
```

To run the reference solution instead:

```sh
./scripts/check.sh src/mathematics/factorize --solution
```
