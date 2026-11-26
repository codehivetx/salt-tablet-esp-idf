# SPDX-FileCopyrightText: © 2026 Code Hive Tx, LLC
# SPDX-License-Identifier: Apache-2.0

cmake_minimum_required(VERSION 3.16)

project(melh-protocol
    VERSION 0.1.0
    DESCRIPTION "Modbus-based stream transit and application services"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(Threads REQUIRED)

include(CTest)

add_subdirectory(src)
add_subdirectory(apps)

if(BUILD_TESTING)
    add_subdirectory(tests)
endif()
