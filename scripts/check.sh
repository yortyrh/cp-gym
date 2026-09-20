#!/usr/bin/env bash
set -euo pipefail

usage() {
    echo "usage: $0 <src/path/to/exercise> [--solution]" >&2
    exit 2
}

if [[ $# -lt 1 || $# -gt 2 ]]; then
    usage
fi

dir_arg=""
use_solution=0
for arg in "$@"; do
    case "$arg" in
        --solution)
            use_solution=1
            ;;
        -*)
            usage
            ;;
        *)
            if [[ -n "$dir_arg" ]]; then
                usage
            fi
            dir_arg="$arg"
            ;;
    esac
done

if [[ -z "$dir_arg" ]]; then
    usage
fi

root="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
cd "$root"

if [[ "$dir_arg" = /* ]]; then
    exercise_dir="$dir_arg"
else
    exercise_dir="$root/$dir_arg"
fi

if [[ ! -d "$exercise_dir" ]]; then
    echo "error: not a directory: $dir_arg" >&2
    exit 2
fi

exercise_dir="$(cd "$exercise_dir" && pwd)"
rel="${exercise_dir#"$root"/}"
if [[ "$rel" != src/* ]]; then
    echo "error: exercise path must be under src/" >&2
    exit 2
fi

shopt -s nullglob
in_files=("$exercise_dir"/*.in)
shopt -u nullglob
if [[ ${#in_files[@]} -ne 1 ]]; then
    echo "error: expected exactly one .in in $rel" >&2
    exit 2
fi

in_file="${in_files[0]}"
stem="$(basename "$in_file" .in)"
out_file="$exercise_dir/$stem.out"
build_dir="${CPREPO_BUILD_DIR:-$root/build/dev}"

if [[ "$use_solution" -eq 1 ]]; then
    src_file="$exercise_dir/$stem.cpp"
    target="$stem-solution"
    bin="$build_dir/exercises/$stem-solution"
else
    src_file="$exercise_dir/$stem.student.cpp"
    target="$stem-student"
    bin="$build_dir/exercises/$stem-student"
fi

if [[ ! -f "$src_file" ]]; then
    echo "error: missing source: $src_file" >&2
    exit 2
fi
if [[ ! -f "$out_file" ]]; then
    echo "error: missing output file: $out_file" >&2
    exit 2
fi

if [[ ! -f "$build_dir/CMakeCache.txt" ]]; then
    if [[ "$build_dir" == "$root/build/dev" ]]; then
        cmake --preset dev
    else
        echo "error: missing CMakeCache.txt in $build_dir" >&2
        exit 2
    fi
fi

cmake --build "$build_dir" --target "$target"

got="$(mktemp)"
trap 'rm -f "$got"' EXIT

set +e
"$bin" < "$in_file" > "$got"
status=$?
set -e
if [[ "$status" -ne 0 ]]; then
    echo "error: program exited with status $status" >&2
    exit 1
fi

if ! diff -u "$out_file" "$got"; then
    exit 1
fi

echo "OK"
