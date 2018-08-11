cmake_minimum_required (VERSION 3.6)

project(explorer LANGUAGES CXX VERSION 0.0.0)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# TESTING with catch2
# set(CATCH_INCLUDE_DIR lib/catch)
#
# add_executable(Catch test.cpp)
# add_library(Catch INTERFACE)
# target_include_directories(Catch INTERFACE ${CATCH_INCLUDE_DIR})
# target_link_libraries(MapMakertests Catch2::Catch2)
#
# include(CTest)
# include(Catch)
# catch_discover_tests(MapMakerTests)

enable_testing()

add_library(TestMain OBJECT lib/catch/TestMain.cpp)

add_executable(TestCore src/MapMaker/test/TestCore.cpp $<TARGET_OBJECTS:TestMain>)
add_test(NAME TestCore COMMAND TestCore)
