add_library(garply SHARED garply.cc)

install(TARGETS garply DESTINATION lib)
install(FILES
        garply.h
        DESTINATION include/garply)
