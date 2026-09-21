# LPT Makespan

**Technique:** longest-processing-time multiprocessor scheduling

Time limit: 1 s
Memory limit: 256 MB

## Problem

Assign $n$ jobs to $m$ identical machines. Sort jobs from longest to shortest and always give the next job to a currently least-loaded machine. Print the resulting makespan (maximum machine load). This is the classic $4/3$-approximation for $P||C_{\max}$.

## Input

The first line contains two integers $n$ and $m$ ($1 \le m \le n \le 10^5$).

The second line contains $n$ integers $d_i$ ($1 \le d_i \le 10^9$), the processing times.

## Output

Print the LPT makespan.

## Sample 1

Input:

```
4 2
8 7 6 5
```

Output:

```
13
```

## Run

From the repository root, after writing `lpt.student.cpp`:

```sh
./scripts/check.sh src/schedules/lpt
```

To run the reference solution instead:

```sh
./scripts/check.sh src/schedules/lpt --solution
```
