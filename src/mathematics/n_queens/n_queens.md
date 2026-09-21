# N Queens

**Technique:** N-queens backtracking

Time limit: 1 s
Memory limit: 256 MB

## Problem

Place $n$ queens on an $n \times n$ board so that no two share a row, column, or diagonal.

Search row by row. For each row choose a column that is not attacked, then recurse. The sample uses $n = 4$, which has two solutions. Print every solution as the column of the queen in each row, $0$-based, in the order the search finds them (columns tried from $0$ to $n-1$).

## Input

One line with an integer $n$ ($1 \le n \le 8$).

## Output

Print $t$ — the number of solutions — then $t$ lines of $n$ integers each: the column chosen for rows $0..n-1$.

## Sample 1

Input:

```
4
```

Output:

```
2
1 3 0 2
2 0 3 1
```

## Run

From the repository root, after writing `n_queens.student.cpp`:

```sh
./scripts/check.sh src/mathematics/n_queens
```

To run the reference solution instead:

```sh
./scripts/check.sh src/mathematics/n_queens --solution
```
