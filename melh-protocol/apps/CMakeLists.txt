# SPDX-FileCopyrightText: © 2026 Code Hive Tx, LLC
# SPDX-License-Identifier: Apache-2.0

add_executable(melh-client
    melh-client/main.cpp
)
target_link_libraries(melh-client PRIVATE melh::client)

add_executable(melh-server
    melh-server/main.cpp
)
target_link_libraries(melh-server PRIVATE melh::server)
