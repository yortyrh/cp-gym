function(cprepo_apply_exercise_flags target)
  target_compile_features(${target} PRIVATE cxx_std_23)
  target_compile_options(
    ${target}
    PRIVATE
      $<$<CXX_COMPILER_ID:GNU,Clang,AppleClang>:${CPREPO_WARNING_FLAGS} -O2>
  )
  if(CPREPO_ENABLE_SANITIZERS)
    target_compile_options(${target} PRIVATE -fsanitize=address,undefined -fno-omit-frame-pointer)
    target_link_options(${target} PRIVATE -fsanitize=address,undefined -fno-omit-frame-pointer)
  endif()
  set_target_properties(${target} PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/exercises")
endfunction()

function(cprepo_add_exercise relative_dir stem)
  set(dir "${CMAKE_CURRENT_SOURCE_DIR}/${relative_dir}")
  add_executable(${stem}-student "${dir}/${stem}.student.cpp")
  add_executable(${stem}-solution "${dir}/${stem}.cpp")
  cprepo_apply_exercise_flags(${stem}-student)
  cprepo_apply_exercise_flags(${stem}-solution)
  if(BUILD_TESTING)
    add_test(
      NAME ${stem}-solution
      COMMAND "${CMAKE_SOURCE_DIR}/scripts/check.sh" "src/${relative_dir}" --solution
      WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}"
    )
  endif()
endfunction()

cprepo_add_exercise(data_structures/fenwick_tree/classic fenwick_tree-classic)
