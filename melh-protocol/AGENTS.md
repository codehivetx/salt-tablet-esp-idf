<!--
  SPDX-FileCopyrightText: © 2026 Code Hive Tx, LLC
  SPDX-License-Identifier: Apache-2.0
-->

# AGENTS.md

## Project

Standalone C++17 CMake project for the melħ protocol: a Modbus-based stream transit and application-services library with client and server halves. It is independent of the parent ESP-IDF firmware build and uses plain CMake/CTest.

## Layout

- `include/melh/common/`, `src/common/` — code shared by client and server.
- `include/melh/client/`, `src/client/` — client library.
- `include/melh/server/`, `src/server/` — server library.
- `apps/melh-client/`, `apps/melh-server/` — executable entry points.
- `tests/unit/` — per-library unit tests.
- `tests/threaded/` — integration test that links both client and server.
- `build/`, `out/` — generated; ignored by `.gitignore`; do not hand-edit.

## Build and verification

No ESP-IDF environment is needed:

- `cmake -S . -B build`
- `cmake --build build`
- `ctest --test-dir build --output-on-failure`

Use this directory's own `build/`, not the parent ESP-IDF `build/`. Tests are enabled by default via `include(CTest)`; disable with `-DBUILD_TESTING=OFF`.

The checked-in `.cpp`/`.hpp` files are comment-only placeholders. Configure succeeds, but linking and CTest fail until `main()` and test bodies are implemented.

## CMake conventions

- C++17 is required; keep `CMAKE_CXX_STANDARD` and target compile features consistent.
- libmodbus is discovered through PkgConfig (`PkgConfig::LIBMODBUS`, minimum 3.2.0); link the imported target instead of raw `${LIBMODBUS_*}` variables.
- Libraries are `melh_common`, `melh_client`, `melh_server`, with aliases `melh::common`, `melh::client`, `melh::server`. Prefer the aliases when linking.
- `melh_client` and `melh_server` link `melh::common` publicly; the threaded test links both `melh::client` and `melh::server` plus `Threads::Threads`.
- Public headers come from `include/` via `PUBLIC` `target_include_directories` using `BUILD_INTERFACE` / `INSTALL_INTERFACE`; do not hardcode machine-specific paths.
- Add every new source or header to the nearest `CMakeLists.txt`. Keep target names stable: `melh-client`, `melh-server`, and the `melh-*-tests` / `melh-threaded-test` executables.

## Code conventions

- Headers are `.hpp` under `include/melh/<component>/`; implementations are `.cpp` under `src/<component>/`.
- Keep declarations in headers and definitions in sources; avoid variables with static storage in headers.
- Every new file carries `SPDX-FileCopyrightText: © 2026 Code Hive Tx, LLC` and `SPDX-License-Identifier: Apache-2.0` in the appropriate comment syntax.
- Match existing naming and directory structure; do not add generated build output to source control.
- Do not commit changes unless explicitly asked.

## Review guidance

Before flagging an issue, check the relevant `CMakeLists.txt` for target/link wiring and confirm new files are actually added to a target. Prefer concrete build/CTest failures over style preferences.
