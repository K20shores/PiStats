
########################
# the library

add_library(pistats)

target_compile_features(pistats PUBLIC cxx_std_17)


target_include_directories(pistats
  PUBLIC
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

target_sources(pistats
  PRIVATE
    stats.cpp
)

set_target_properties(pistats PROPERTIES 
  ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib"
  VERSION ${PROJECT_VERSION}
  SOVERSION ${PROJECT_VERSION_MAJOR}
)

########################
# the stats program

add_executable(
  collect_stats
    main.cpp
)

target_link_libraries(collect_stats
  PRIVATE
    pistats
)
