if (NOT TARGET alyx_adc)
    add_library(alyx_adc INTERFACE)

    target_sources(alyx_adc INTERFACE
            ${CMAKE_CURRENT_LIST_DIR}/include/alyx/adc.h
    )

    target_include_directories(alyx_adc INTERFACE ${CMAKE_CURRENT_LIST_DIR}/include)
    target_link_libraries(alyx_adc INTERFACE
            hardware_adc)
endif()
