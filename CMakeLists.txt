cmake_minimum_required(VERSION 3.25)

project(ui)

add_subdirectory(easyx)

add_executable(test)

target_compile_features(test PRIVATE cxx_std_17)

target_sources(test
  PRIVATE
    main.cpp
)

target_link_libraries(test
  PRIVATE
    easyx
)