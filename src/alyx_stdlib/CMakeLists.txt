if (NOT TARGET alyx_stdlib)
    add_library(alyx_stdlib INTERFACE)

    target_sources(alyx_stdlib INTERFACE
            ${CMAKE_CURRENT_LIST_DIR}/include/alyx/stdlib.h
    )

    target_include_directories(alyx_stdlib INTERFACE ${CMAKE_CURRENT_LIST_DIR}/include)
    target_link_libraries(alyx_stdlib INTERFACE
            pico_stdlib)
endif()
