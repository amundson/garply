cmake_minimum_required(VERSION 3.0.0)
project(GARPLY VERSION 1.0.1)

set(INCLUDE_INSTALL_DIR include/ CACHE PATH "install directory")
set(LIB_INSTALL_DIR lib/ CACHE PATH "lib directory")

include_directories(BEFORE ${GARPLY_SOURCE_DIR})
enable_testing()

include(CMakePackageConfigHelpers)

configure_package_config_file(GarplyConfig.cmake.in
  ${CMAKE_CURRENT_BINARY_DIR}/GarplyConfig.cmake
  INSTALL_DESTINATION ${LIB_INSTALL_DIR}/garply/cmake
  PATH_VARS INCLUDE_INSTALL_DIR LIB_INSTALL_DIR)

write_basic_package_version_file(
  ${CMAKE_CURRENT_BINARY_DIR}/GarplyConfigVersion.cmake
  VERSION ${GARPLY_VERSION}
  COMPATIBILITY ExactVersion)

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/GarplyConfig.cmake
              ${CMAKE_CURRENT_BINARY_DIR}/GarplyConfigVersion.cmake
        DESTINATION ${LIB_INSTALL_DIR}/garply/cmake)

add_subdirectory(garply)
add_subdirectory(tests)
