cmake_minimum_required(VERSION 3.10)

################
# Package options
set(RASPBERRY_TOOLCHAIN "/Volumes/RPI-Toolchain/toolchain" CACHE STRING "The location of the toolchains required for your version of raspberry pi" )
set(TOOLCHAIN_PREFIX "arm-raspberrypi-linux-gnueabihf" CACHE STRING "the prefix of the toolchain tools")

# ################
# # Set the toolchain file
set(CMAKE_TOOLCHAIN_FILE "${CMAKE_SOURCE_DIR}/cmake/pi-toolchain.cmake")

project(
  pi_stats
  VERSION 0.1.0
  LANGUAGES CXX
)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH};${PROJECT_SOURCE_DIR}/cmake")

# Enable static linking, because I can't figure out how to make dynamic linking work
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static-libstdc++ -static-libgcc")

################
# Dependencies
# include("cmake/dependencies.cmake")

################
# Add the target

add_subdirectory(src)
