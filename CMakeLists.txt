cmake_minimum_required(VERSION 3.9)

project(piq
    VERSION 0.0.0
    #DESCRIPTION ${PACKAGE_DESCRIPTION}
    LANGUAGES C
)

#include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
#conan_basic_setup(TARGETS)

add_custom_command(
    OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/include/piq/version.h"
    COMMAND "${CMAKE_COMMAND}"
        -D "GENERATED_WARNING=// this file is generated from src/version.in"
        -D "VERSION_MAJOR=${PROJECT_VERSION_MAJOR}"
        -D "VERSION_MINOR=${PROJECT_VERSION_MINOR}"
        -D "VERSION_PATCH=${PROJECT_VERSION_PATCH}"
        -D "INPUT=${CMAKE_CURRENT_SOURCE_DIR}/src/version.h.in"
        -D "OUTPUT=include/piq/version.h"
        -P "${CMAKE_SOURCE_DIR}/cmake/configure_file.cmake"
    MAIN_DEPENDENCY src/version.h.in
)

add_library(library
    src/version.c
    src/allocator.c
)
target_include_directories(library PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)
set_target_properties(library PROPERTIES
    OUTPUT_NAME piq

    C_STANDARD 11
    C_STANDARD_REQUIRED YES
    C_EXTENSIONS OFF
)
target_sources(library PUBLIC
    "${CMAKE_CURRENT_BINARY_DIR}/include/piq/version.h"
)
target_include_directories(library PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/include>
)

