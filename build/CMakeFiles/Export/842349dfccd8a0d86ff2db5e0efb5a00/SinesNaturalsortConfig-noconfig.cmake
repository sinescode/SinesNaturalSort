#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "SinesNaturalsort::SinesNaturalsort" for configuration ""
set_property(TARGET SinesNaturalsort::SinesNaturalsort APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(SinesNaturalsort::SinesNaturalsort PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_NOCONFIG "CXX"
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libSinesNaturalsort.a"
  )

list(APPEND _cmake_import_check_targets SinesNaturalsort::SinesNaturalsort )
list(APPEND _cmake_import_check_files_for_SinesNaturalsort::SinesNaturalsort "${_IMPORT_PREFIX}/lib/libSinesNaturalsort.a" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
