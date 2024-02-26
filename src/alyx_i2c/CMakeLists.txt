if (NOT TARGET alyx_i2c)
    add_library(alyx_i2c INTERFACE)

    target_sources(alyx_i2c INTERFACE
            ${CMAKE_CURRENT_LIST_DIR}/include/alyx/i2c.h
    )

    target_include_directories(alyx_i2c INTERFACE ${CMAKE_CURRENT_LIST_DIR}/include)
    target_link_libraries(alyx_i2c INTERFACE
            hardware_i2c
            hardware_gpio)
endif()
