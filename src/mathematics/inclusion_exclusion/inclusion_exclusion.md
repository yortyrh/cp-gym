# Union by Inclusion-Exclusion

**Technique:** inclusion-exclusion for two sets

Time limit: 1 s
Memory limit: 256 MB

## Problem

How many integers in $1..n$ are divisible by $a$ or by $b$?

By inclusion-exclusion, the count is $\lfloor n/a \rfloor + \lfloor n/b \rfloor - \lfloor n / \operatorname{lcm}(a, b) \rfloor$.

## Input

The first line contains one integer $q$ ($1 \le q \le 10^5$).

Each of the next $q$ lines contains three integers $n$, $a$, and $b$ ($1 \le n \le 10^{18}$, $1 \le a, b \le 10^9$).

## Output

For each triple, print the count.

## Sample 1

Input:

```
3
10 2 3
10 4 6
7 7 3
```

Output:

```
7
3
3
```

## Run

From the repository root, after writing `inclusion_exclusion.student.cpp`:

```sh
./scripts/check.sh src/mathematics/inclusion_exclusion
```

To run the reference solution instead:

```sh
./scripts/check.sh src/mathematics/inclusion_exclusion --solution
```
