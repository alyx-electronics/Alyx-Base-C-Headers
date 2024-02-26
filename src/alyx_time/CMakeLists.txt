if (NOT TARGET alyx_time)
    add_library(alyx_time INTERFACE)

    target_sources(alyx_time INTERFACE
            ${CMAKE_CURRENT_LIST_DIR}/include/alyx/time.h
    )

    target_include_directories(alyx_time INTERFACE ${CMAKE_CURRENT_LIST_DIR}/include)
    target_link_libraries(alyx_time INTERFACE
            hardware_rtc
            hardware_xosc
            hardware_clocks
            pico_stdlib)
endif()
