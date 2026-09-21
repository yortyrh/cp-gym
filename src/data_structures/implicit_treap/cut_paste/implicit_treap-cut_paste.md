# Cut and Paste

**Technique:** implicit treap cut-and-merge

Time limit: 1 s
Memory limit: 256 MB

## Problem

You are given a sequence of $n$ integers $a_1, a_2, \ldots, a_n$. Process $q$ operations. Each operation is three integers $l$, $r$, and $p$:

1. Cut the inclusive subarray $[l, r]$ out of the current sequence.
2. Let $R$ be the remaining sequence. Insert the cut piece so that it sits immediately after the first $p$ elements of $R$. If $p = 0$, the piece is moved to the front. If $p = |R|$, it is moved to the back.

Positions are 1-based in the sequence as it stands before the operation. The length of the sequence never changes.

Maintain an implicit treap and implement each operation with three splits and two merges: split off the prefix before $l$, split off the cut segment of length $r-l+1$, then split the remaining sequence after $p$ elements and merge in the order left, cut, right.

Print the sequence after all operations.

## Input

The first line contains two integers $n$ and $q$ ($1 \le n \le 2 \cdot 10^5$, $0 \le q \le 2 \cdot 10^5$).

The second line contains $n$ integers $a_1, a_2, \ldots, a_n$ ($|a_i| \le 10^9$).

Each of the next $q$ lines contains three integers $l$, $r$, and $p$ ($1 \le l \le r \le n$, $0 \le p \le n-(r-l+1)$).

## Output

Print $n$ integers: the sequence after every cut-and-paste, separated by spaces.

## Sample 1

Input:

```
6 2
1 2 3 4 5 6
3 5 1
4 6 0
```

Output:

```
5 2 6 1 3 4
```

## Run

From the repository root, after writing `implicit_treap-cut_paste.student.cpp`:

```sh
./scripts/check.sh src/data_structures/implicit_treap/cut_paste
```

To run the reference solution instead:

```sh
./scripts/check.sh src/data_structures/implicit_treap/cut_paste --solution
```
