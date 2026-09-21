# Two-Satisfiability

**Technique:** 2-SAT via implication graph SCCs

Time limit: 1 s
Memory limit: 256 MB

## Problem

There are $n$ Boolean variables $x_1, \ldots, x_n$ and $m$ clauses. Each clause is a disjunction of two literals. A literal is written as a signed integer: $x$ means variable $x$ is true, and $-x$ means variable $x$ is false.

Decide whether the formula is satisfiable. If it is, print one satisfying assignment.

Build the implication graph (clause $(a \lor b)$ adds $\lnot a \to b$ and $\lnot b \to a$) and compute strongly connected components. The formula is unsatisfiable exactly when some variable and its negation lie in the same component. $n$ is small.

## Input

The first line contains two integers $n$ and $m$ ($1 \le n \le 40$, $0 \le m \le 80$).

Each of the next $m$ lines contains two nonzero integers $a$ and $b$ ($1 \le |a|, |b| \le n$).

## Output

If the formula is unsatisfiable, print `NO`.

Otherwise print `YES` on the first line and $n$ numbers $b_1, \ldots, b_n$ on the second line, each $0$ or $1$, where $b_i = 1$ means $x_i$ is true.

## Sample 1

Input:

```
2 2
1 2
-1 2
```

Output:

```
YES
1 1
```

## Run

From the repository root, after writing `two_sat.student.cpp`:

```sh
./scripts/check.sh src/graphs/two_sat
```

To run the reference solution instead:

```sh
./scripts/check.sh src/graphs/two_sat --solution
```
