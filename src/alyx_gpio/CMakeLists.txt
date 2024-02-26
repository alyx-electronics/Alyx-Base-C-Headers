if (NOT TARGET alyx_gpio)
    add_library(alyx_gpio INTERFACE)

    target_sources(alyx_gpio INTERFACE
            ${CMAKE_CURRENT_LIST_DIR}/include/alyx/gpio.h
    )

    target_include_directories(alyx_gpio INTERFACE ${CMAKE_CURRENT_LIST_DIR}/include)
    target_link_libraries(alyx_gpio INTERFACE
            hardware_gpio)
endif()
