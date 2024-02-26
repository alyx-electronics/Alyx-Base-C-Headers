if (NOT TARGET alyx_temp)
    add_library(alyx_temp INTERFACE)

    target_sources(alyx_temp INTERFACE
            ${CMAKE_CURRENT_LIST_DIR}/include/alyx/temp.h
    )

    target_include_directories(alyx_temp INTERFACE ${CMAKE_CURRENT_LIST_DIR}/include)
    target_link_libraries(alyx_temp INTERFACE
            hardware_adc)
endif()
