if (NOT TARGET piccolo_os)
    add_library(piccolo_os INTERFACE)

    target_sources(piccolo_os INTERFACE
            ${CMAKE_CURRENT_LIST_DIR}/include/piccolo/os.h
            ${CMAKE_CURRENT_LIST_DIR}/include/piccolo/os.c
            ${CMAKE_CURRENT_LIST_DIR}/include/piccolo/context_switch.s
            ${CMAKE_CURRENT_LIST_DIR}/include/piccolo/os_lock_core_v1.1.h
            ${CMAKE_CURRENT_LIST_DIR}/include/piccolo/os_lock_core_v1.1.c
    )

    target_include_directories(piccolo_os INTERFACE ${CMAKE_CURRENT_LIST_DIR}/include)
    target_link_libraries(piccolo_os INTERFACE
            pico_stdlib)
endif()
