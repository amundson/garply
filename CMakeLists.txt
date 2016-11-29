cmake_minimum_required(VERSION 3.0.0)
project(GARPLY VERSION 2.0.0)

include(GNUInstallDirs)

enable_testing()

add_subdirectory(garply)
add_subdirectory(tests)

include(CMakePackageConfigHelpers)

# - Versioning File (Same for Build/Install Trees)
write_basic_package_version_file(
  ${CMAKE_CURRENT_BINARY_DIR}/GarplyConfigVersion.cmake
  VERSION ${GARPLY_VERSION}
  COMPATIBILITY ExactVersion)

# - Build Tree Config/Targets files
set(GARPLY_CURRENT_INCLUDEDIR "${PROJECT_SOURCE_DIR}")
set(GARPLY_CURRENT_LIBDIR "${PROJECT_BINARY_DIR}/garply")

configure_package_config_file(GarplyConfig.cmake.in
  ${CMAKE_CURRENT_BINARY_DIR}/GarplyConfig.cmake
  INSTALL_DESTINATION ${CMAKE_CURRENT_BINARY_DIR}
  INSTALL_PREFIX ${CMAKE_CURRENT_BINARY_DIR}
  PATH_VARS GARPLY_CURRENT_INCLUDEDIR GARPLY_CURRENT_LIBDIR)

# NB: must be called *after* EXPORT argument is created, hence
# move of add_subdirectory earlier.
export(EXPORT GarplyTargets NAMESPACE garply::)

# - Install Tree Config/Targets file
set(GARPLY_CURRENT_INCLUDEDIR "${CMAKE_INSTALL_INCLUDEDIR}")
set(GARPLY_CURRENT_LIBDIR "${CMAKE_INSTALL_LIBDIR}")

configure_package_config_file(GarplyConfig.cmake.in
  ${CMAKE_CURRENT_BINARY_DIR}/InstallTreeFiles/GarplyConfig.cmake
  INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/garply/cmake
  PATH_VARS GARPLY_CURRENT_INCLUDEDIR GARPLY_CURRENT_LIBDIR)

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/InstallTreeFiles/GarplyConfig.cmake
              ${CMAKE_CURRENT_BINARY_DIR}/GarplyConfigVersion.cmake
              DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/garply)
install(EXPORT GarplyTargets
        NAMESPACE garply::
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/garply)

# - Uninstall target
if (NOT TARGET uninstall)
  configure_file(
    "${CMAKE_CURRENT_LIST_DIR}/uninstall.cmake.in"
    "${CMAKE_BINARY_DIR}/uninstall.cmake"
    IMMEDIATE
    @ONLY
    )

  add_custom_target(uninstall
    COMMAND "${CMAKE_COMMAND}" -P "${CMAKE_BINARY_DIR}/uninstall.cmake"
    WORKING_DIRECTORY "${CMAKE_BINARY_DIR}"
    )
endif()
