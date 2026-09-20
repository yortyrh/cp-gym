# CP Repo Practice

A C++23 practice repository inspired by the catalog in the
[CP4 Free Source Code Project](https://github.com/stevenhalim/cpbook-code), by Steven Halim,
Felix Halim, and Suhendry Effendy.

The goal is not to preserve complete contest programs. Each header is one algorithm or data
structure, documented at the top of the file, with a textbook-sized test. Delete the body,
reimplement it, and run that test. Real problems stay on Kattis, LeetCode, and Codeforces.

## Requirements

- CMake 3.25 or newer.
- Ninja.
- GNU g++. When `CXX` is unset, CMake searches `g++-15`, `g++-14`, `g++-13`, `g++-12`, then `g++`.
- Git, so CMake can download Catch2 during the first configuration.

## Build and test

Build remaining Catch2 tests:

```sh
cmake --preset dev
cmake --build --preset dev
ctest --preset dev
```

Sanitizer and release presets are also available:

```sh
cmake --preset sanitizers
cmake --build --preset sanitizers
ctest --preset sanitizers

cmake --preset release
cmake --build --preset release
ctest --preset release
```

## Project layout

```text
src/
├── data_structures/fenwick_tree/   # one folder per Fenwick technique
└── dynamic_programming/coin_change_min/
scripts/check.sh
include/cprepo/                     # unmigrated headers
├── data_structures/      # DSU, AVL, ...
├── dynamic_programming/  # LIS, Kadane, knapsack, ...
├── geometry/             # point primitives, then one header per algorithm
├── graphs/               # graph.hpp for types; one header per algorithm
├── mathematics/          # one header per number-theory / combinatorics / algebra topic
├── others/               # mex, Floyd cycle, Josephus, 15-puzzle
├── schedules/            # one header per scheduling rule
├── searching/            # quick select, binary/ternary search, Newton, Simpson, SA
└── strings/              # one header per string algorithm
tests/                              # Catch2 for unmigrated headers
docs/catalog.md           # CP4/cpbook-code chapter map, including cp-algorithms extras
```

Migrated topics are judge-style exercises under `src/`. Unmigrated implementations are
header-only and live in the `cprepo` namespace. Types are concrete (`int64_t`, `int`,
`string`), ranges use `[begin, end)`, indices are zero-based, and graphs use vertices `0..n-1`.

## Practice workflow

Practice for migrated topics (Fenwick tree techniques and minimum coin change):

1. Open the `.md` in the exercise folder.
2. Fill `*.student.cpp` (FastIO, named technique, I/O).
3. From the repo root run `./scripts/check.sh src/...` (the command is in the statement).
4. Peek at `*.cpp` only after attempting the stub.

For topics still in `include/`:

1. Run the full test suite to start from a green baseline.
2. Select one header. Read only the matching `*_test.cpp`.
3. Keep the public signature, delete the implementation body, and write it again.
4. Run that exercise through its Catch2 tag:

   ```sh
   ./build/dev/tests/cprepo_tests "[dijkstra]"
   ```

5. Run `ctest --preset sanitizers` before considering the exercise complete.
6. Restore the reference solution with Git whenever you want to compare or start again.

The tests describe observable behavior rather than the procedure. A different implementation is
valid when it preserves the expected complexity and passes both regular and edge cases.

## Coverage

The catalog in [docs/catalog.md](docs/catalog.md) follows Competitive Programming 4 chapters
(`ch2`…`ch9`) as in [cpbook-code](https://github.com/stevenhalim/cpbook-code). Topics from
[cp-algorithms](https://cp-algorithms.com) are filed in the nearest CP4 section. Catch2 is
downloaded from its `v3.15.3` release through `FetchContent`. The code in this repository is an
educational reimplementation and does not copy CPBook source code verbatim.
