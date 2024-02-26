if (NOT TARGET alyx_pwm)
    add_library(alyx_pwm INTERFACE)

    target_sources(alyx_pwm INTERFACE
            ${CMAKE_CURRENT_LIST_DIR}/include/alyx/pwm.h
    )

    target_include_directories(alyx_pwm INTERFACE ${CMAKE_CURRENT_LIST_DIR}/include)
    target_link_libraries(alyx_pwm INTERFACE
            hardware_pwm
            hardware_gpio)
endif()
