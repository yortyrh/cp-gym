cmake_minimum_required(VERSION 3.25)

if(NOT CMAKE_CXX_COMPILER AND NOT DEFINED ENV{CXX})
  find_program(CPREPO_GNU_CXX NAMES g++-15 g++-14 g++-13 g++-12 g++)
  if(CPREPO_GNU_CXX)
    set(CMAKE_CXX_COMPILER "${CPREPO_GNU_CXX}" CACHE FILEPATH "GNU C++ compiler")
  endif()
endif()

project(
  cprepo_practice
  VERSION 0.1.0
  DESCRIPTION "Competitive-programming data structures and algorithms for deliberate practice"
  LANGUAGES CXX
)

if(NOT CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
  message(
    WARNING
    "bits/stdc++.h exercises need GNU g++. "
    "macOS /usr/bin/g++ is AppleClang, not GCC."
  )
endif()

set(CMAKE_CXX_EXTENSIONS OFF)

include(CTest)

option(CPREPO_WARNINGS_AS_ERRORS "Treat compiler warnings as errors" OFF)
option(CPREPO_ENABLE_SANITIZERS "Enable AddressSanitizer and UndefinedBehaviorSanitizer" OFF)

set(CPREPO_WARNING_FLAGS -Wall -Wextra -Wpedantic -Wconversion -Wshadow)
if(CPREPO_WARNINGS_AS_ERRORS)
  list(APPEND CPREPO_WARNING_FLAGS -Werror)
endif()

add_subdirectory(src)
