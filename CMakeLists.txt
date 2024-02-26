cmake_minimum_required(VERSION 3.13)

if (NOT TARGET _alyx_header_inclusion_marker)
    add_library(_alyx_header_inclusion_marker INTERFACE)

    # Pull in PICO SDK (must be before project)
    include(${PICO_SDK_PATH}/external/alyx_base_c_sdk_import.cmake)
    if (PICO_SDK_VERSION_STRING VERSION_LESS "1.2.0")
        message(FATAL_ERROR "Require at least Raspberry Pi Pico SDK version 1.2.0")
    endif()

    project(alyx_base_c_headers C CXX)

    set(CMAKE_C_STANDARD 11)
    set(CMAKE_CXX_STANDARD 17)

    pico_is_top_level_project(ALYX_HEADER_TOP_LEVEL_PROJECT)

    if (NOT ALYX_HEADER_PATH)
        set(ALYX_HEADER_PATH ${CMAKE_CURRENT_LIST_DIR})
    endif()
    set(ALYX_HEADER_PATH "${ALYX_HEADER_PATH}" CACHE PATH "Path to Alyx C Headers")

    # The real work gets done in post_init which is called at the end of pico_sdk_init
    list(APPEND PICO_SDK_POST_LIST_FILES ${CMAKE_CURRENT_LIST_DIR}/post_init.cmake)
    if (ALYX_HEADER_TOP_LEVEL_PROJECT)
        message("alyx_header: initialize SDK since we're the top-level")
        # Initialize the SDK
        pico_sdk_init()
    else()
        set(PICO_SDK_POST_LIST_FILES ${PICO_SDK_POST_LIST_FILES} PARENT_SCOPE)
    endif()
endif()
