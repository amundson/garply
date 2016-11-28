configure_file (
  "${CMAKE_CURRENT_SOURCE_DIR}/garply_version_h.in"
  "${CMAKE_CURRENT_BINARY_DIR}/garply_version.h"
)
include_directories(${CMAKE_CURRENT_BINARY_DIR})

add_library(garply SHARED garply.cc garply.h)

install(TARGETS garply
        EXPORT GarplyTargets
        DESTINATION ${CMAKE_INSTALL_LIBDIR})
install(FILES
        garply.h
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/garply)
