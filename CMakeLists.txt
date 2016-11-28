cmake_minimum_required(VERSION 3.0.0)
project(GARPLY VERSION 1.0.1)

include(GNUInstallDirs)

include_directories(BEFORE ${GARPLY_SOURCE_DIR})
enable_testing()

include(CMakePackageConfigHelpers)

configure_package_config_file(GarplyConfig.cmake.in
  ${CMAKE_CURRENT_BINARY_DIR}/GarplyConfig.cmake
  INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/garply/cmake
  PATH_VARS CMAKE_INSTALL_INCLUDEDIR CMAKE_INSTALL_LIBDIR)

write_basic_package_version_file(
  ${CMAKE_CURRENT_BINARY_DIR}/GarplyConfigVersion.cmake
  VERSION ${GARPLY_VERSION}
  COMPATIBILITY ExactVersion)

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/GarplyConfig.cmake
              ${CMAKE_CURRENT_BINARY_DIR}/GarplyConfigVersion.cmake
              DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/garply)

add_subdirectory(garply)
add_subdirectory(tests)
