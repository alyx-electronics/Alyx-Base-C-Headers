if (NOT TARGET piccolo_os)
    add_library(piccolo_os INTERFACE)

    target_sources(piccolo_os INTERFACE
            ${CMAKE_CURRENT_LIST_DIR}/include/piccolo/os.h
            ${CMAKE_CURRENT_LIST_DIR}/include/piccolo/os.h
            ${CMAKE_CURRENT_LIST_DIR}/include/piccolo/os.h
    )

    target_include_directories(piccolo_os INTERFACE ${CMAKE_CURRENT_LIST_DIR}/include)
    target_link_libraries(piccolo_os INTERFACE
            pico_stdlib)
endif()
