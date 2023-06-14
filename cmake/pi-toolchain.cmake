# Define our host system
set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_VERSION 1)

# Define the cross compiler locations
set(CMAKE_C_COMPILER   "${RASPBERRY_TOOLCHAIN}/bin/${TOOLCHAIN_PREFIX}-gcc")
set(CMAKE_CXX_COMPILER "${RASPBERRY_TOOLCHAIN}/bin/${TOOLCHAIN_PREFIX}-g++")
set(CMAKE_AR "${RASPBERRY_TOOLCHAIN}/bin/${TOOLCHAIN_PREFIX}-ar")
set(CMAKE_RANLIB "${RASPBERRY_TOOLCHAIN}/bin/${TOOLCHAIN_PREFIX}-ranlib")

# Define the sysroot path for the RaspberryPi distribution in our tools folder 
set(CMAKE_FIND_ROOT_PATH ${RASPBERRY_TOOLCHAIN}/${TOOLCHAIN_PREFIX}/sysroot/)

# Use our definitions for compiler tools
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)

# Search for libraries and headers in the target directories only
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)