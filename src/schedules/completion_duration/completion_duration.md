# Shortest Processing Time

**Technique:** single-machine SPT (sort by processing time)

Time limit: 1 s
Memory limit: 256 MB

## Problem

One machine, $n$ jobs with processing times $d_i$. To minimise the total completion time, order jobs by non-decreasing processing time. Ties keep the original $0$-based index.

## Input

The first line contains one integer $n$ ($1 \le n \le 10^5$).

The second line contains $n$ integers $d_i$ ($1 \le d_i \le 10^9$).

## Output

Print $n$ $0$-based indices in SPT order.

## Sample 1

Input:

```
3
5 1 3
```

Output:

```
1 2 0
```

## Run

From the repository root, after writing `completion_duration.student.cpp`:

```sh
./scripts/check.sh src/schedules/completion_duration
```

To run the reference solution instead:

```sh
./scripts/check.sh src/schedules/completion_duration --solution
```
