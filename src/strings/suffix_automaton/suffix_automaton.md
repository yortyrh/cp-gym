# Suffix Automaton Queries

**Technique:** suffix automaton (online construction)

Time limit: 1 s
Memory limit: 256 MB

## Problem

You are given a string $s$. Build its suffix automaton: the smallest DFA that recognizes every suffix of $s$ (and therefore every substring). Then:

- print the number of distinct nonempty substrings of $s$
- answer $q$ membership queries: is $t$ a substring of $s$?

Extend the automaton one character at a time with clone nodes. The number of distinct substrings is $\sum (\mathrm{len}(v) - \mathrm{len}(\mathrm{link}(v)))$ over every state $v$ except the initial one. Do not insert every substring into a set.

## Input

The first line contains the string $s$ ($1 \le |s| \le 10^5$).

The second line contains one integer $q$ ($1 \le q \le 10^5$).

Each of the next $q$ lines contains one nonempty query string $t$. All strings use only lowercase English letters, and the total length of the queries is at most $10^6$.

## Output

Print the number of distinct nonempty substrings of $s$.

Then print $q$ lines: `YES` if the query occurs in $s$, otherwise `NO`.

## Sample 1

Input:

```
banana
3
ana
anana
ab
```

Output:

```
15
YES
YES
NO
```

## Run

From the repository root, after writing `suffix_automaton.student.cpp`:

```sh
./scripts/check.sh src/strings/suffix_automaton
```

To run the reference solution instead:

```sh
./scripts/check.sh src/strings/suffix_automaton --solution
```
