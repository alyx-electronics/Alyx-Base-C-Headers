if (NOT TARGET alyx_os)
    add_library(alyx_os INTERFACE)

    target_sources(alyx_os INTERFACE
            ${CMAKE_CURRENT_LIST_DIR}/include/alyx/alyx_os.h
            ${CMAKE_CURRENT_LIST_DIR}/include/alyx/alyx_os.c
            ${CMAKE_CURRENT_LIST_DIR}/include/alyx/context_switch.s
    )

    target_include_directories(alyx_os INTERFACE ${CMAKE_CURRENT_LIST_DIR}/include)
    target_link_libraries(alyx_os INTERFACE
            alyx_stdlib)
endif()
