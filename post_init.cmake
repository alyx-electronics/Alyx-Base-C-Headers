add_library(alyx_header_included INTERFACE)
target_compile_definitions(alyx_header_included INTERFACE
        -DALYX_HEADER=1
        )

pico_add_platform_library(alyx_header_included)

# note as we're a .cmake included by the SDK, we're relative to the pico-sdk build
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/src ${CMAKE_BINARY_DIR}/alyx_base_c_headers/src)
