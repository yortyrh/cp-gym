# Split Packing

**Technique:** meet in the middle subset sum ($n \le 40$)

Time limit: 1 s
Memory limit: 256 MB

## Problem

You have $n$ parcel weights and a mailbox limit $x$. Count the subsets whose weights sum to exactly $x$. The empty subset counts only when $x = 0$.

Because $n \le 40$, split the parcels into two halves and enumerate every subset sum of each half ($2^{n/2}$). Sort one list of sums. For each sum $L$ from the other half, count values $R$ with $L + R = x$. Do not enumerate all $2^n$ subsets.

## Input

The first line contains two integers $n$ and $x$ ($1 \le n \le 40$, $0 \le x \le 10^{15}$).

The second line contains $n$ integers $a_1, \ldots, a_n$ ($0 \le a_i \le 10^9$).

## Output

Print one integer: the number of subsets with sum $x$.

## Sample 1

Input:

```
4 5
1 2 3 4
```

Output:

```
2
```

## Run

From the repository root, after writing `meet_in_the_middle.student.cpp`:

```sh
./scripts/check.sh src/searching/meet_in_the_middle
```

To run the reference solution instead:

```sh
./scripts/check.sh src/searching/meet_in_the_middle --solution
```
