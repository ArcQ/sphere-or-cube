cmake_minimum_required (VERSION 3.6)

project(explorer LANGUAGES C VERSION 0.0.0)

include_directories(
  lib
  src/HardwareInterfaces/CollisionDetector
  src/HardwareInterfaces/Driver
  src/MapMaker
  src/utils
  )

enable_testing()
add_executable(TestMapMaker src/MapMaker/test/TestMapMaker.c)
add_test(NAME TestCore COMMAND TestMapMaker)
