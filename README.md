# CP Repo Practice

A C++23 practice repository inspired by the catalog in the
[CP4 Free Source Code Project](https://github.com/stevenhalim/cpbook-code), by Steven Halim,
Felix Halim, and Suhendry Effendy.

The goal is not to preserve complete contest programs. Topics are judge-style
exercises: read the statement, fill the student stub, and verify with `./scripts/check.sh`.
Real problems stay on Kattis, LeetCode, and Codeforces.

## Requirements

- CMake 3.25 or newer.
- Ninja.
- GNU g++. When `CXX` is unset, CMake searches `g++-15`, `g++-14`, `g++-13`, `g++-12`, then `g++`.

## Build and test

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
docs/catalog.md           # CP4/cpbook-code chapter map, including cp-algorithms extras
```

Each topic is a five-file exercise: statement (`.md`), reference (`.cpp`), student stub
(`.student.cpp`), and Sample 1 (`.in` / `.out`).

## Practice workflow

1. Open the `.md` in the exercise folder.
2. Fill `*.student.cpp` (FastIO, named technique, I/O).
3. From the repo root run `./scripts/check.sh src/...` (the command is in the statement).
4. Peek at `*.cpp` only after attempting the stub.

## Coverage

The catalog in [docs/catalog.md](docs/catalog.md) follows Competitive Programming 4 chapters
(`ch2`…`ch9`) as in [cpbook-code](https://github.com/stevenhalim/cpbook-code). Topics from
[cp-algorithms](https://cp-algorithms.com) are filed in the nearest CP4 section. The code in
this repository is an educational reimplementation and does not copy CPBook source code
verbatim.
