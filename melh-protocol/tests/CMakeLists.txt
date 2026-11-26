# SPDX-FileCopyrightText: © 2026 Code Hive Tx, LLC
# SPDX-License-Identifier: Apache-2.0

add_executable(melh-common-unit-tests
    unit/common_test.cpp
)
target_link_libraries(melh-common-unit-tests PRIVATE melh::common)
add_test(NAME melh.common.unit COMMAND melh-common-unit-tests)

add_executable(melh-client-unit-tests
    unit/client_test.cpp
)
target_link_libraries(melh-client-unit-tests PRIVATE melh::client)
add_test(NAME melh.client.unit COMMAND melh-client-unit-tests)

add_executable(melh-server-unit-tests
    unit/server_test.cpp
)
target_link_libraries(melh-server-unit-tests PRIVATE melh::server)
add_test(NAME melh.server.unit COMMAND melh-server-unit-tests)

add_executable(melh-threaded-test
    threaded/threaded_test.cpp
)
target_link_libraries(melh-threaded-test
    PRIVATE
        melh::client
        melh::server
        Threads::Threads
)
add_test(NAME melh.threaded COMMAND melh-threaded-test)
