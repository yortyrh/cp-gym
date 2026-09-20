# Exercise-Format Pilot Design

Date: 2026-09-20

Pilot that replaces header-plus-Catch2 practice with judge-style exercises for Fenwick tree techniques and minimum-coin DP. If the format works, later work migrates the rest of the catalog the same way.

## Goal

A student reads a Codeforces/Kattis-style statement, fills a guided stub, and checks the program against sample I/O with one copy-paste command. The command does not set `CXX=`. CMake selects the compiler.

## Non-goals (this pilot)

- Do not migrate topics other than Fenwick tree and `coin_change_min`.
- Do not delete remaining `include/cprepo/**/*.hpp` or remaining Catch2 tests.
- Do not add a web UI (Coddy is only the stub-marker inspiration).
- Do not keep a duplicate `classic` vs `point_update_range_query` Fenwick exercise. Classic is PURQ.

## Locked decisions

| Topic | Decision |
|---|---|
| Scope | Fenwick (7 techniques) + `coin_change_min` |
| Language | English statements and stub comments; C++ identifiers in English |
| Student vs solution | `<stem>.student.cpp` is the stub; `<stem>.cpp` is the reference |
| FastIO | Student writes it. `cin`/`cout` only. No `scanf`/`printf` |
| Fenwick indexing | Always 1-based internally and in Fenwick statements. Ranges inclusive `[l, r]` |
| Coin-change arrays | 0-based, as usual for DP |
| Checker | `scripts/check.sh <dir>` builds via CMake preset `dev`, runs stdin/stdout, `diff -u` |
| Exercise root | All exercises live under `src/`, never at the repo root and never under `include/` |
| Compiler | CMake finds GNU `g++` (see Build). Student command never passes `CXX=` |

## Layout

Exercises live under `src/`. They do not live at the repository root and they do not live under `include/`. Domain folders (`data_structures`, `dynamic_programming`, `graphs`, …) are children of `src/`.

```text
src/
  data_structures/fenwick_tree/
    classic/
    2d/
    range_update_point_query/
    range_update_range_query/
    count_inversions/
    frequency_counting/
    dynamic/
  dynamic_programming/coin_change_min/
scripts/check.sh
```

Multi-technique data structure: one subdirectory per technique. Single algorithm: files directly in the topic folder. No extra `classic/` wrapper for `coin_change_min`.

Each Fenwick technique directory contains exactly these five files, stem `fenwick_tree-<technique>`:

- `fenwick_tree-<technique>.md`
- `fenwick_tree-<technique>.cpp` (reference; full solution)
- `fenwick_tree-<technique>.student.cpp` (stub; markers only)
- `fenwick_tree-<technique>.in`
- `fenwick_tree-<technique>.out`

`coin_change_min` uses stem `coin_change_min` (no technique suffix).

Slugs are `snake_case`. Use `classic`, not `clasic`.

Sample 1 in the markdown is byte-for-byte the `.in` / `.out` pair (UTF-8, Unix newlines, newline at end of file).

### Files to delete

- `include/cprepo/data_structures/fenwick_tree.hpp`
- `include/cprepo/dynamic_programming/coin_change_min.hpp`
- `tests/data_structures/fenwick_tree_test.cpp`
- `tests/dynamic_programming/coin_change_min_test.cpp`

## Statement template

Every `.md` uses this section order. Prose is normal English (not compressed). Original problems; do not copy CSES/Kattis/UVa text.

```markdown
# <Title>

**Technique:** <structure or algorithm, including the variant>

Time limit: 1 s
Memory limit: 256 MB

## Problem

<statement. Mention that the named technique solves it efficiently.
If a common alternative exists, the stub (not the statement body) tells
the student not to use it.>

## Input

<exact format, constraints, 1-based Fenwick indices when applicable>

## Output

<exact format>

## Sample 1

Input:
```
<same bytes as the .in file, shown as a markdown code block>
```

Output:
```
<same bytes as the .out file, shown as a markdown code block>
```

## Run

From the repository root, after writing `<stem>.student.cpp`:

```sh
./scripts/check.sh <relative-dir-from-repo-root>
```

To run the reference solution instead:

```sh
./scripts/check.sh <relative-dir-from-repo-root> --solution
```
```

Fenwick constraints: `n, q ≤ 2 · 10^5` (or the 2D analogue) so a naive rebuild is the wrong approach. Coin-change: `n ≤ 100`, `amount ≤ 10^4`. Values fit in `int64_t` unless a problem states otherwise. Print `-1` when coin change is impossible.

## Student stub

The stub compiles. It contains no algorithm, no FastIO, and no input parsing. `main` only `return 0;`. Comments are English. Blocks appear in this order: FastIO, Technique, I/O.

Fenwick classic stub (the other Fenwick stubs follow the same shape; only the Technique and I/O comments change):

```cpp
#include <cstdint>
#include <iostream>
#include <vector>

// === FastIO ===
// Enable fast C++ I/O here:
//   std::ios_base::sync_with_stdio(false);
//   std::cin.tie(nullptr);
//   std::cout.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: Fenwick tree (point update, range query) ===
// Implement a 1-based Fenwick tree (binary indexed tree).
// Index 0 is unused. tree[1] stores information about a[1].
// Required operations:
//   add(i, delta)   — point update at 1-based index i
//   prefix_sum(i)   — sum of a[1] + ... + a[i]
//   range_sum(l, r) — sum of a[l] + ... + a[r] = prefix_sum(r) - prefix_sum(l - 1)
// Do not rebuild prefix sums on every query. Do not use a segment tree for this exercise.

int main() {
    // === I/O ===
    // Read n, q and the initial array a[1..n] from stdin.
    // Build the Fenwick tree from the array.
    // For each query:
    //   type 1 i v  → point-update index i to value v
    //   type 2 l r  → print range_sum(l, r) followed by a newline
    // Write answers to stdout.
    return 0;
}
```

The Technique block always names the required structure or DP and names the typical alternative not to use. Students write FastIO themselves, using this struct in the reference solutions:

```cpp
struct FastIO {
    FastIO() {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);
    }
};
static FastIO fastio;
```

Reference `*.cpp` files are self-contained: FastIO, the technique, and I/O in one translation unit. They do not `#include` anything under `include/cprepo/`. They use `std::cin` / `std::cout`. They match the stub's include style (explicit standard headers, not `bits/stdc++.h`).

## Pilot problems

All Fenwick problems use 1-based indices and inclusive ranges. Query type integers are as specified below.

### 1. `src/data_structures/fenwick_tree/classic` — Dynamic Range Sum Queries

**Technique:** Fenwick tree (point update, range query).

Array `a[1..n]`. Queries:

- `1 i v` — set `a[i] = v` (implement as `add(i, v - old)` or store values beside the tree)
- `2 l r` — print `a[l] + ... + a[r]`

Input: `n q`; then `n` integers; then `q` query lines. `1 ≤ n, q ≤ 2 · 10^5`. `|a[i]|, |v| ≤ 10^9`.

### 2. `src/data_structures/fenwick_tree/2d` — Matrix Range Sum Queries

**Technique:** 2D Fenwick tree.

Matrix `n × m`, 1-based. Queries:

- `1 x y v` — set `a[x][y] = v`
- `2 x1 y1 x2 y2` — print the sum of the inclusive subrectangle

Input: `n m q`; then `n` rows of `m` integers; then `q` query lines. `1 ≤ n, m ≤ 500`, `1 ≤ q ≤ 10^5`.

### 3. `src/data_structures/fenwick_tree/range_update_point_query` — Range Add, Point Query

**Technique:** Fenwick tree as a difference array (range update, point query).

- `1 l r v` — add `v` to every element in `[l, r]`
- `2 i` — print `a[i]`

Input: `n q`; initial `a[1..n]`; `q` query lines. `1 ≤ n, q ≤ 2 · 10^5`.

### 4. `src/data_structures/fenwick_tree/range_update_range_query` — Range Add, Range Sum

**Technique:** two Fenwick trees (range update, range query).

- `1 l r v` — add `v` to `[l, r]`
- `2 l r` — print sum of `[l, r]`

Input: `n q`; initial `a[1..n]`; `q` query lines. `1 ≤ n, q ≤ 2 · 10^5`.

### 5. `src/data_structures/fenwick_tree/count_inversions` — Inversion Count

**Technique:** Fenwick frequency tree plus coordinate compression.

Input: `n`; then `n` integers `a[1..n]`. Output: one integer, the number of pairs `i < j` with `a[i] > a[j]`. `1 ≤ n ≤ 2 · 10^5`. Values may be negative or up to `10^9` in absolute value, so compress.

### 6. `src/data_structures/fenwick_tree/frequency_counting` — Range Frequency Queries

**Technique:** Fenwick tree as a frequency table on values in `1..n`.

Start with empty frequencies. Values are already in `1..n` (no compression).

- `1 x` — insert one occurrence of `x`
- `2 x` — erase one occurrence of `x` (input guarantees `x` is present)
- `3 l r` — print how many stored values lie in `[l, r]`

Input: `n q` where `n` is the value universe; then `q` query lines. `1 ≤ n, q ≤ 2 · 10^5`.

### 7. `src/data_structures/fenwick_tree/dynamic` — Compressed Online Frequency Queries

**Technique:** Fenwick tree on a coordinate-compressed universe (values up to `10^9`).

Same three query types as frequency counting, but `x`, `l`, and `r` satisfy `1 ≤ x, l, r ≤ 10^9`. Input starts with `q`, then `q` query lines (no `n`). Compress all values that appear in the input, then Fenwick over the compressed rank. Type `2` still has a present value.

### 8. `src/dynamic_programming/coin_change_min` — Minimum Coins

**Technique:** unbounded knapsack DP (`dp[x]` = fewest coins for sum `x`). Do not use greedy coin choice.

Input: `n amount`; then `n` positive coin denominations. Output: minimum number of coins that sum to `amount`, or `-1` if impossible. `1 ≤ n ≤ 100`, `1 ≤ amount ≤ 10^4`. Unlimited supply of each coin.

## Build and checker

### Compiler selection

CMake must pick a GNU C++ compiler so the student does not export `CXX`.

Before `project()` in the root `CMakeLists.txt`: if `CMAKE_CXX_COMPILER` is unset and `ENV{CXX}` is unset, `find_program` for `g++-15`, `g++-14`, `g++-13`, `g++-12`, then `g++`, and cache the first hit as `CMAKE_CXX_COMPILER`. If `CXX` or `-DCMAKE_CXX_COMPILER=` is already set (CI sets `CXX: g++`), do not override.

`project()` keeps `LANGUAGES CXX`. Exercise targets do not link `cprepo::cprepo`. They use `cxx_std_23`, the same warning flags as `cprepo` (`-Wall -Wextra -Wpedantic -Wconversion -Wshadow`, plus `-Werror` when `CPREPO_WARNINGS_AS_ERRORS` is on), and `-O2`. When `CPREPO_ENABLE_SANITIZERS` is on, apply `-fsanitize=address,undefined -fno-omit-frame-pointer` to compile and link of every exercise target. Targets must build under presets `dev`, `sanitizers`, and `release`.

### CMake exercise targets

Root `CMakeLists.txt` calls `add_subdirectory(src)`. `src/CMakeLists.txt` defines the helper and invokes it once per exercise directory. Paths passed to the helper are relative to `src/` (for example `data_structures/fenwick_tree/classic`). `check.sh` and CTest still receive the path from the repository root (`src/data_structures/fenwick_tree/classic`).

- `<stem>-student` from `<dir>/<stem>.student.cpp`
- `<stem>-solution` from `<dir>/<stem>.cpp`

Put both binaries in `${CMAKE_BINARY_DIR}/exercises/` (`RUNTIME_OUTPUT_DIRECTORY`) so `check.sh` always runs `build/dev/exercises/<stem>-student` (or `<stem>-solution`).

When `BUILD_TESTING` is on, `add_test(NAME <stem>-solution COMMAND "${CMAKE_SOURCE_DIR}/scripts/check.sh" <relative-dir> --solution)`. Student binaries are not CTest tests; an empty stub would fail the diff.

Catch2 discovery of `*_test.cpp` stays as it is.

### `scripts/check.sh`

Usage, from the repository root:

```sh
./scripts/check.sh src/data_structures/fenwick_tree/classic
./scripts/check.sh src/data_structures/fenwick_tree/classic --solution
./scripts/check.sh src/dynamic_programming/coin_change_min
```

Behavior:

1. Resolve the exercise directory relative to the repo root (script locates the root by finding `CMakeLists.txt` / `scripts/check.sh`).
2. The directory must be under `src/`. Require exactly one `*.in` in that directory. Stem is the filename without `.in`.
3. Source file: `<stem>.student.cpp`, or `<stem>.cpp` if `--solution`.
4. If `build/dev` is missing, run `cmake --preset dev`.
5. `cmake --build --preset dev --target <stem>-student` (or `<stem>-solution`).
6. Run `build/dev/exercises/<stem>-student` (or `-solution`) with `<stem>.in` on stdin, capture stdout to a temp file.
7. `diff -u` against `<stem>.out`. Exact match, including a trailing newline. Extra spaces fail.
8. Print `OK` and exit 0 on match. On compile error, crash, missing file, or diff: print the error/`diff` and exit non-zero.
9. Delete the temp stdout file on exit (success or failure).

Markdown **Run** sections copy those two commands with no `CXX=` prefix.

If `check.sh` is invoked from CTest, skip re-configure when `build/dev` already exists. Recursion is not an issue: the test command is the same script, but CMake already configured the tree.

## Docs and CI

- `README.md`: practice workflow is read the `.md`, fill `.student.cpp`, run `./scripts/check.sh <dir>`. Document the Fenwick/coin-change-min split. Keep Catch2 instructions for topics still in `include/`.
- `CONTRIBUTING.md`: for migrated topics, add statement + stub + solution + `.in`/`.out` and wire the CMake helper. Do not add Catch2 tests for those topics.
- `docs/catalog.md`: Fenwick row points at `src/data_structures/fenwick_tree/` (list the seven technique dirs). Coin change (min coins) points at `src/dynamic_programming/coin_change_min/`. Column header may stay "Header" for unmigrated rows; migrated rows list the exercise path instead.
- `.github/workflows/ci.yml`: keep configure/build/`ctest --preset dev`. After tests, run `./scripts/check.sh <dir> --solution` for each of the eight exercise directories so a missing CTest wire still fails CI.

## Error handling

- Missing dir, path outside `src/`, missing `.in`/`.out`/source, or more than one `.in`: `check.sh` prints a one-line error and exits 2.
- Compile failure: compiler diagnostics, exit 1.
- Runtime crash / non-zero child: report exit status, exit 1.
- Wrong stdout: unified diff, exit 1.
- Stubs must compile; they are allowed to produce empty or wrong stdout.

## Success criteria

- All eight reference solutions pass `./scripts/check.sh <dir> --solution`.
- All eight student stubs compile via the `-student` targets and fail the output diff.
- Deleted Fenwick and `coin_change_min` headers/tests are gone; remaining Catch2 suite still passes.
- README Run examples work without `CXX=` on a machine where CMake can see GNU `g++`.
- CI is green.

## Later work (out of this spec)

Migrate remaining domains (`graphs`, `mathematics`, other `data_structures`, …) under `src/<domain>/` with the same folder rules: subfolders only when a topic has multiple techniques. Delete each header and its Catch2 test when that topic is migrated.
