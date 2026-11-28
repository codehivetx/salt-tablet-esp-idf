# SPDX-FileCopyrightText: © 2026 Code Hive Tx, LLC
# SPDX-License-Identifier: Apache-2.0

add_executable(melh-connect
    melh-connect/main.cpp
)
target_link_libraries(melh-connect PRIVATE melh::client)

add_executable(melh-service
    melh-service/main.cpp
)
target_link_libraries(melh-service PRIVATE melh::server)

foreach(target IN ITEMS melh-connect melh-service)
    target_include_directories(${target} PUBLIC   $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
            $<INSTALL_INTERFACE:include>)
    target_link_libraries(${target} PUBLIC Threads::Threads)
endforeach()
