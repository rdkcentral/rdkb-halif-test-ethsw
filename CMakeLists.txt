cmake_minimum_required(VERSION 3.10)

project(ethsw_vl LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

set(COMMON_LIB "" CACHE STRING "Additional server libraries (CMake list)")

include(GNUInstallDirs)

# Transport Library
add_library(vl_transport STATIC dispatcher/src/vl_transport.c)

target_include_directories(vl_transport PUBLIC cli)

target_compile_options(vl_transport PRIVATE
    -Wall
    -Wextra
    -g
)

file(RELATIVE_PATH VL_LIBDIR_FROM_BINDIR
    "${CMAKE_INSTALL_FULL_BINDIR}"
    "${CMAKE_INSTALL_FULL_LIBDIR}"
)

# CLI
add_executable(vl_cli cli/vl_cli.c)

target_link_libraries(vl_cli PRIVATE vl_transport)

target_compile_options(vl_cli PRIVATE
    -Wall
    -Wextra
    -g
)

install(TARGETS vl_cli
    RUNTIME DESTINATION "${CMAKE_INSTALL_BINDIR}"
)

#------------------------------------------------------------------------------
# ETHSW HAL Configuration
#------------------------------------------------------------------------------

set(ETHSW_HAL_LIB "" CACHE FILEPATH
    "Prebuilt libethsw_hal.so to test (empty: build the stand-in HAL)"
)

if(ETHSW_HAL_LIB)

    get_filename_component(hal_lib "${ETHSW_HAL_LIB}" ABSOLUTE)

    if(NOT EXISTS "${hal_lib}")
        message(FATAL_ERROR "ETHSW_HAL_LIB not found: ${hal_lib}")
    endif()

    add_library(ethsw_hal SHARED IMPORTED)

    set_target_properties(ethsw_hal PROPERTIES
        IMPORTED_LOCATION "${hal_lib}"
        INTERFACE_INCLUDE_DIRECTORIES
            "${CMAKE_CURRENT_SOURCE_DIR}/dispatcher/include"
    )

    message(STATUS "ethsw: using prebuilt HAL ${hal_lib}")

else()

    add_library(ethsw_hal SHARED
        dispatcher/src/ethsw_hal.c
    )

    target_include_directories(ethsw_hal PUBLIC
        dispatcher/include
    )

    target_compile_definitions(ethsw_hal PUBLIC
        FEATURE_RDKB_WAN_MANAGER
        FEATURE_RDKB_AUTO_PORT_SWITCH
    )

    target_compile_options(ethsw_hal PRIVATE
        -Wall
        -Wextra
        -g
    )

endif()

#------------------------------------------------------------------------------
# ETHSW VL Server
#------------------------------------------------------------------------------

add_executable(ethsw_vl
    dispatcher/src/vl_main.c
    dispatcher/src/vl_server.c
    dispatcher/src/component.c
    dispatcher/src/ethswhal_apis.c
)

target_compile_definitions(ethsw_vl PRIVATE
    VL_SERVER
)

target_compile_options(ethsw_vl PRIVATE
    -Wall
    -Wextra
    -g
)

target_link_libraries(ethsw_vl PRIVATE
    vl_transport
    ethsw_hal
    ${COMMON_LIB}
)

set_target_properties(ethsw_vl PROPERTIES
    INSTALL_RPATH "$ORIGIN/${VL_LIBDIR_FROM_BINDIR}"
)

install(TARGETS ethsw_vl
    RUNTIME DESTINATION "${CMAKE_INSTALL_BINDIR}"
)

if(ETHSW_HAL_LIB)
    install(FILES "${hal_lib}"
        DESTINATION "${CMAKE_INSTALL_LIBDIR}"
    )
else()
    install(TARGETS ethsw_hal
        LIBRARY DESTINATION "${CMAKE_INSTALL_LIBDIR}"
    )
endif()