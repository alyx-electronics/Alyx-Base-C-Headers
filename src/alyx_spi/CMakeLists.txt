if (NOT TARGET alyx_spi)
    add_library(alyx_i2c INTERFACE)

    target_sources(alyx_spi INTERFACE
            ${CMAKE_CURRENT_LIST_DIR}/include/alyx/spi.h
    )

    target_include_directories(alyx_spi INTERFACE ${CMAKE_CURRENT_LIST_DIR}/include)
    target_link_libraries(alyx_spi INTERFACE
            hardware_spi
            hardware_gpio)
endif()
