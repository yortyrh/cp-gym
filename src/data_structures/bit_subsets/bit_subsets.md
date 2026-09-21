# Submasks of a Mask

**Technique:** submask enumeration (`sub = (sub - 1) & mask`)

Time limit: 1 s
Memory limit: 256 MB

## Problem

You are given $q$ bit masks. For each mask, print every submask of that mask, including $0$ and the mask itself.

Walk the $2^{\mathrm{popcount}(\mathrm{mask})}$ submasks with the classic loop: start at the mask, then repeatedly replace `sub` with `(sub - 1) & mask` until you return to the mask. Print values in that order (the mask first, then descending, ending at $0$).

Do not generate all integers in $0 \ldots \mathrm{mask}$ and filter them.

## Input

The first line contains one integer $q$ ($1 \le q \le 10^5$).

Each of the next $q$ lines contains one integer `mask` ($0 \le \mathrm{mask} < 2^{60}$).

It is guaranteed that the total number of printed submasks over all queries does not exceed $2 \cdot 10^5$.

## Output

For each mask, print its submasks on one line, separated by spaces, in the enumeration order described above.

## Sample 1

Input:

```
3
5
0
13
```

Output:

```
5 4 1 0
0
13 12 9 8 5 4 1 0
```

## Run

From the repository root, after writing `bit_subsets.student.cpp`:

```sh
./scripts/check.sh src/data_structures/bit_subsets
```

To run the reference solution instead:

```sh
./scripts/check.sh src/data_structures/bit_subsets --solution
```
