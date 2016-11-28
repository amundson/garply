configure_file (
  "${CMAKE_CURRENT_SOURCE_DIR}/garply_version_h.in"
  "${CMAKE_CURRENT_BINARY_DIR}/garply_version.h"
)

add_library(garply SHARED garply.cc garply.h)
target_include_directories(garply BEFORE
  PUBLIC
   $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
   $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>
   $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
   )

install(TARGETS garply
        EXPORT GarplyTargets
        DESTINATION ${CMAKE_INSTALL_LIBDIR})
install(FILES
        garply.h
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/garply)
