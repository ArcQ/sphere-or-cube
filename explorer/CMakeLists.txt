cmake_minimum_required (VERSION 3.6)

project(explorer LANGUAGES CXX VERSION 0.0.0)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include_directories(
  src/HardwareInterfaces
  src/MapMaker
  )

enable_testing()

add_library(TestMain OBJECT lib/catch/TestMain.cpp)

add_executable(TestCore src/MapMaker/test/TestCore.cpp $<TARGET_OBJECTS:TestMain>)
add_test(NAME TestCore COMMAND TestCore)
