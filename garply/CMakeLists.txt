configure_file("${CMAKE_CURRENT_SOURCE_DIR}/garply_version_h.in"
               "${CMAKE_CURRENT_BINARY_DIR}/garply_version.h")

add_library(garply SHARED garply.cc garply.h)
target_include_directories(garply
                           BEFORE
                           PUBLIC
                           $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
                           $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
                           PRIVATE
                           $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>)

add_executable(garplinator garplinator.cc)
target_link_libraries(garplinator garply)
target_include_directories(garplinator
                           BEFORE
                           PUBLIC
                           $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
                           $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
                           PRIVATE
                           $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>)

install(TARGETS garply garplinator
        EXPORT GarplyTargets DESTINATION ${CMAKE_INSTALL_LIBDIR})
install(FILES garply.h DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/garply)
