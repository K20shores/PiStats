cmake_minimum_required(VERSION 3.10)

################
# Package options
# set(RASPBERRY_TOOLCHAIN "/Volumes/RPI-Toolchain/toolchain" CACHE STRING "The location of the toolchains required for your version of raspberry pi" )

################
# Set the toolchain file
# set(CMAKE_TOOLCHAIN_FILE "${CMAKE_SOURCE_DIR}/cmake/pi-toolchain.cmake")

project(
  pi_stats
  VERSION 0.1.0
  LANGUAGES CXX
)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH};${PROJECT_SOURCE_DIR}/cmake")

################
# Add the target

add_subdirectory(src)
