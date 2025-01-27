cmake_minimum_required(VERSION 3.10)

# Project name
project(SinesNaturalsort VERSION 1.0)

# Create a static library from the source files
add_library(SinesNaturalsort STATIC
    SinesNaturalSort.cpp
)

# Specify include directories for the library
target_include_directories(SinesNaturalsort PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

# Specify the C++ standard
target_compile_features(SinesNaturalsort PUBLIC cxx_std_17)

# Include GNU standard installation directories
include(GNUInstallDirs)

# Install the header files to the default include directory
install(FILES SinesNaturalSort.h
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

# Install the static library to the default library directory
install(TARGETS SinesNaturalsort
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}  # This installs the .a file
)

# Export the library for use by other projects
install(TARGETS SinesNaturalsort
    EXPORT SinesNaturalsortTargets
)

# Generate and install the CMake config file to the default cmake directory
install(EXPORT SinesNaturalsortTargets
    FILE SinesNaturalsortConfig.cmake
    NAMESPACE SinesNaturalsort::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/SinesNaturalsort
)
