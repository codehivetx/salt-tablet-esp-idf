# SPDX-FileCopyrightText: © 2026 Code Hive Tx, LLC
# SPDX-License-Identifier: Apache-2.0

add_library(melh_common STATIC
    common/common.cpp
)
add_library(melh::common ALIAS melh_common)

add_library(melh_client STATIC
    client/client.cpp
)
add_library(melh::client ALIAS melh_client)

add_library(melh_server STATIC
    server/server.cpp
)
add_library(melh::server ALIAS melh_server)

foreach(target IN ITEMS melh_common melh_client melh_server)
    target_include_directories(${target}
        PUBLIC
            $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
            $<INSTALL_INTERFACE:include>
    )
    target_link_libraries(${target} PUBLIC Threads::Threads)
endforeach()

target_link_libraries(melh_client
    PUBLIC
        melh::common
        PkgConfig::LIBMODBUS
)
target_link_libraries(melh_server
    PUBLIC
        melh::common
        PkgConfig::LIBMODBUS
)
