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

add_library(cprepo INTERFACE)
add_library(cprepo::cprepo ALIAS cprepo)

target_include_directories(
  cprepo
  INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)
target_compile_features(cprepo INTERFACE cxx_std_23)

set(CPREPO_WARNING_FLAGS -Wall -Wextra -Wpedantic -Wconversion -Wshadow)
if(CPREPO_WARNINGS_AS_ERRORS)
  list(APPEND CPREPO_WARNING_FLAGS -Werror)
endif()
target_compile_options(
  cprepo
  INTERFACE
    $<$<CXX_COMPILER_ID:GNU,Clang,AppleClang>:${CPREPO_WARNING_FLAGS}>
)

if(CPREPO_ENABLE_SANITIZERS)
  if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang|AppleClang")
    target_compile_options(cprepo INTERFACE -fsanitize=address,undefined -fno-omit-frame-pointer)
    target_link_options(cprepo INTERFACE -fsanitize=address,undefined -fno-omit-frame-pointer)
  else()
    message(FATAL_ERROR "CPREPO_ENABLE_SANITIZERS requires GCC or Clang")
  endif()
endif()

add_subdirectory(src)

if(BUILD_TESTING AND EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/tests/CMakeLists.txt")
  add_subdirectory(tests)
endif()
