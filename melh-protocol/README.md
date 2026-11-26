<!--
  SPDX-FileCopyrightText: © 2026 Code Hive Tx, LLC
  SPDX-License-Identifier: Apache-2.0
-->

# melħ-protocol

A [modbus](https://modbus.org)-based layer providing reliable stream transit and application services.


## Dependencies

- On the client (device) side, [esp-modbus](https://github.com/espressif/esp-modbus) - see parent directory

- On the server (host) side, we are using [libmodbus](https://libmodbus.org)

- for tests, we use [gtest](https://google.github.io/googletest/)

### Homebrew (mac)

```sh
brew install libmodbus googletest
```

### Fedora

```sh
sudo dnf install pkg-config cmake libmodbus-devel gtest-devel
```

### Ubuntu

```sh
sudo apt-get install pkg-config cmake libmodbus-dev libgtest-dev

## Build

```sh
cmake -S . -B build
cmake --build build
ctest --test-dir build --output-on-failure
```

## The name

[melħ](https://wiktionary.org/wiki/melħ) means salt. 

## License

© 2026 Code Hive Tx, LLC

[Apache-2.0](./LICENSE)