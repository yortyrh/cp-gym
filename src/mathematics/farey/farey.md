# Farey Neighbours

**Technique:** Farey sequence mediant and next neighbour

Time limit: 1 s
Memory limit: 256 MB

## Problem

Let $a/b$ and $c/d$ be adjacent in a Farey sequence, so $bc - ad = 1$. Their mediant is $(a+c)/(b+d)$. The next term after $c/d$ in the Farey sequence of order $n$ is
$(kc - a)/(kd - b)$ where $k = \lfloor (n + b)/d \rfloor$.

Print the mediant, then that next neighbour.

## Input

One line with five integers $a$, $b$, $c$, $d$, and $n$
($0 \le a \le c \le n \le 1000$, $1 \le b, d \le n$, and $a/b$, $c/d$ are adjacent in some Farey sequence).

## Output

Print two lines: the mediant numerator and denominator, then the next neighbour numerator and denominator.

## Sample 1

Input:

```
0 1 1 3 3
```

Output:

```
1 4
1 2
```

## Run

From the repository root, after writing `farey.student.cpp`:

```sh
./scripts/check.sh src/mathematics/farey
```

To run the reference solution instead:

```sh
./scripts/check.sh src/mathematics/farey --solution
```
