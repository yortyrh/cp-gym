# Compatible Assignments

**Technique:** bitmask DP on subsets (`dp[mask]`)

Time limit: 1 s
Memory limit: 256 MB

## Problem

There are $n$ people and $n$ jobs. Person $i$ can take job $j$ only if $a_{i,j} = 1$. Each person must receive exactly one job, and each job must be given to exactly one person.

Count the number of valid assignments modulo $10^9 + 7$.

Process people in order $1, 2, \ldots, n$. Let `mask` be the set of jobs already taken. Then `dp[mask]` is the number of ways to assign the first $\mathrm{popcount}(mask)$ people to exactly those jobs. Do not enumerate permutations with backtracking; $n!$ is too large.

## Input

The first line contains one integer $n$ ($1 \le n \le 20$).

Each of the next $n$ lines contains $n$ integers $a_{i,1}, \ldots, a_{i,n}$ ($a_{i,j} \in \{0, 1\}$). Rows are people, columns are jobs, both 1-based in the statement.

## Output

Print one integer: the number of assignments modulo $10^9 + 7$.

## Sample 1

Input:

```
3
1 1 0
1 0 1
0 1 1
```

Output:

```
2
```

## Run

From the repository root, after writing `bitmask-assignment.student.cpp`:

```sh
./scripts/check.sh src/dynamic_programming/bitmask/assignment
```

To run the reference solution instead:

```sh
./scripts/check.sh src/dynamic_programming/bitmask/assignment --solution
```
