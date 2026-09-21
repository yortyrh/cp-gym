# CP Repo Practice

A C++23 **gym** for competitive-programming data structures and techniques.

Each exercise is a classic, single-technique problem. You implement the structure
or algorithm until it is automatic. On a real contest problem, that piece should
not be what slows you down.

This is not a place to grind hard contest problems. Those belong on Kattis,
Codeforces, AtCoder, and similar platforms: they mix several ideas, hide the
technique, and reward problem-solving. Here the technique is the point. The
statement tells you which one to use. The sample is small. The job is to write
the standard solution from memory.

## How an exercise is laid out

Topics live under `src/<domain>/<topic>/`. When one topic has several variants,
they sit in sibling folders (for example Fenwick: classic, 2d, range updates).

Every exercise is five files with the same stem:

| File | Role |
|---|---|
| `*.md` | Statement: problem, constraints, sample, and the check command |
| `*.student.cpp` | **Your code.** Stub that already compiles. Fill this in. |
| `*.cpp` | Reference solution. Open it only after you have tried. |
| `*.in` / `*.out` | Sample 1. `check.sh` compiles your stub and diffs stdout against `.out` |

The stub already has the contest prelude (`bits/stdc++.h`, `using namespace std`,
`#define int long long`, `signed main()`). Comments mark where FastIO, the
technique, and I/O go. Leave those comments as a map; replace them with working
code.

## How to practice

1. Pick a topic from [docs/catalog.md](docs/catalog.md) (or browse `src/`).
2. Read the `.md` in that folder. Note the named technique; that is what you
   are drilling, not a puzzle to invent from scratch.
3. Write the solution in `*.student.cpp`. Do not open `*.cpp` yet.
4. From the **repository root**, run the command in the statement. Example:

   ```sh
   ./scripts/check.sh src/data_structures/avl_tree
   ```

   The script builds the student target and compares your output to `.out`.
   `OK` means Sample 1 matches.

5. If it fails, fix the stub and run the same command again. Peek at `*.cpp`
   only after a real attempt (or to check a detail you already implemented).

To run the reference instead of your stub:

```sh
./scripts/check.sh src/data_structures/avl_tree --solution
```

`check.sh` configures `cmake --preset dev` on first use if `build/dev` is
missing. After that it only rebuilds the one exercise you asked for.

## Requirements

- CMake 3.25 or newer.
- Ninja.
- GNU g++. When `CXX` is unset, CMake searches `g++-15`, `g++-14`, `g++-13`,
  `g++-12`, then `g++`. AppleClang (`/usr/bin/g++` on macOS) is not enough:
  the stubs include `bits/stdc++.h`.

## Full test suite (optional)

Daily practice uses `check.sh`. The presets exist to build and run every
exercise at once (students plus references):

```sh
cmake --preset dev
cmake --build --preset dev
ctest --preset dev
```

Sanitizer and release presets:

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
├── data_structures/
├── dynamic_programming/
├── geometry/
├── graphs/
├── mathematics/
├── others/
├── schedules/
├── searching/
├── sorting/
└── strings/
scripts/check.sh
docs/catalog.md           # CP4 / cp-algorithms topic map
CONTRIBUTING.md           # how to add an exercise
```

## Coverage

The catalog in [docs/catalog.md](docs/catalog.md) follows Competitive Programming 4
chapters (`ch2`…`ch9`) as in the
[CP4 Free Source Code Project](https://github.com/stevenhalim/cpbook-code)
(Steven Halim, Felix Halim, Suhendry Effendy). Topics from
[cp-algorithms](https://cp-algorithms.com) sit in the nearest CP4 section.

Code here is an educational reimplementation. It does not copy CPBook sources
verbatim.

To add an exercise, see [CONTRIBUTING.md](CONTRIBUTING.md).
