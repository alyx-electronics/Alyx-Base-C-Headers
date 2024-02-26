if (NOT TARGET alyx_uart)
    add_library(alyx_uart INTERFACE)

    target_sources(alyx_uart INTERFACE
            ${CMAKE_CURRENT_LIST_DIR}/include/alyx/uart.h
    )

    target_include_directories(alyx_uart INTERFACE ${CMAKE_CURRENT_LIST_DIR}/include)
    target_link_libraries(alyx_uart INTERFACE
            hardware_uart
            hardware_gpio)
endif()
