<!--
  SPDX-FileCopyrightText: © 2026 Code Hive Tx, LLC
  SPDX-License-Identifier: Apache-2.0
-->

# melħ-protocol

A [modbus](https://modbus.org)-based layer providing reliable stream transit and application services.


## Dependencies

- On the server (host) side, we are using [libmodbus](https://libmodbus.org)
- On the client (device) side, [esp-modbus](https://github.com/espressif/esp-modbus)

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