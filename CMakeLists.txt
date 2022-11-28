cmake_minimum_required(VERSION 3.0.0)
project(main VERSION 0.1.0)

include(CTest)

set(CMAKE_CXX_STANDARD 20)

enable_testing()

Include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.0.1 # or a later release
)

FetchContent_MakeAvailable(Catch2)

include_directories(.)

add_library(dura duration.cpp)

add_executable(main main.cpp)

target_link_libraries(main dura)

add_executable(tests test/test.cpp)

target_link_libraries(tests dura Catch2::Catch2WithMain)

include(Catch)
catch_discover_tests(tests)
