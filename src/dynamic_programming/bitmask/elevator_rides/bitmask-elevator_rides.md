# Elevator Rides

**Technique:** bitmask DP (permutations to subsets)

Time limit: 1 s
Memory limit: 256 MB

## Problem

An elevator has weight limit $x$. There are $n$ people with weights $w_1, \ldots, w_n$. Each ride may carry any subset whose total weight is at most $x$. Every person must go up.

Compute the minimum number of rides.

Backtracking over the $n!$ boarding orders is too slow. Instead, for every subset $S$ of people store a pair: the fewest rides needed for $S$, and the smallest possible weight of the last ride among those optimal solutions. Transition by adding one person from $S$ to a solution of $S$ without that person.

## Input

The first line contains two integers $n$ and $x$ ($1 \le n \le 20$, $1 \le x \le 10^9$).

The second line contains $n$ integers $w_1, \ldots, w_n$ ($1 \le w_i \le x$).

## Output

Print one integer: the minimum number of rides.

## Sample 1

Input:

```
5 12
2 3 4 5 9
```

Output:

```
2
```

## Run

From the repository root, after writing `bitmask-elevator_rides.student.cpp`:

```sh
./scripts/check.sh src/dynamic_programming/bitmask/elevator_rides
```

To run the reference solution instead:

```sh
./scripts/check.sh src/dynamic_programming/bitmask/elevator_rides --solution
```
