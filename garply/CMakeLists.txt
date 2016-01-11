configure_file (
  "${CMAKE_CURRENT_SOURCE_DIR}/garply_version_h.in"
  "${CMAKE_CURRENT_BINARY_DIR}/garply_version.h"
)
include_directories(${CMAKE_CURRENT_BINARY_DIR})

add_library(garply SHARED garply.cc garply.h)

install(TARGETS garply DESTINATION ${LIB_INSTALL_DIR})
install(FILES
        garply.h
        DESTINATION ${INCLUDE_INSTALL_DIR}/garply)
