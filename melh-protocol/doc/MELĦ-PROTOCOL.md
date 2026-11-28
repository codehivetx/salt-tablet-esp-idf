# MELĦ-PROTOCOL

The Melħ protocol (Maltese: _salt_) is a reliable stream transport protocol built upon modbus.
It is intended for transit via a RS-485 physical layer.  The immediate application is smart terminals for the household.

## General Overview

RS-485 provides a physical layer.
Modbus provides a request/response layer including CRC packet validation.

As with RS-485 and Modbus, Melħ is designed to be a multidrop protocol.
The initial implementation focusses on a single-drop (host to terminal) usage.

The initial usage scenario for Melħ is that the terminal (client) requests a connection to an application on the host (server).
From there, the host allocates a stream.
Then, the terminal can conduct an interactive session on that stream until it is closed.

All strings UTF-8 or a subset.

## Architecture

### Modbus integration

#### Functions 

- Modbus FUNCTION `0xF0` is used for unreliable, single-packet communication, such as a ping or similar meta-negociation. 

- Modbus FUNCTION `0xF1` is used for most additional stream data.
- Functions 0xF2…0xFF are reserved for Melħ expansion
- Functions below 0xF0 are not used and are available for application-specific use.

#### Registers

- some register can be used to retrieve Melħ statistics such as error count, stream utilization, etc.

- each node will have a persisted UUID which is used in some operations. however, the 1-byte host id will be used. So there may be a register that will map from host id to uuid.

### Ports and Stream Addresses

- a port is a 16 bit value, with 0xFFFF meaning unknown and 0x0000 used for special operations.
- a port number is specific to one side (one client or server)
- other than port 0, Melħ entities do not typically "listen" on a specific port number. (i.e. port 80 http).  rather, a port is only used as a dynamically allocated slot.
- a stream address consists of a port number on both sides, so for example (with C and S being client and server): `C1234-S5678` meaning port 1234 on the client, and port 5678 on the server.
- one could even say `C1234` == `S5678` because these port numbers won't be reused with any other combination until that stream is closed.
- The special stream, `C0-S0` is pre-opened and is used for control.

### Streams

- Streams are reliable. 
- Streams are ordered and chunky. Each side will only receive the next chunk when all prior chunks have already been sent.

#### Stream Handshake

- Each packet contains a sequence number. 
- Packets may be of any length, 1 byte up to the MTU (tbd)
- The sender keeps all outgoing packets in a ring buffer.
- When a packet is confirmed received by the other side, it's removed from the buffer.
- TODO: For now, we'll just have 'confirm' message and a 'resend' message.
- TODO: for now, we fail if we hit max seq! 
- The sequence number is global to the c/s pair.
- When a 'close' message is sent, the stream is closed by both sides.
- Stream 0 is never closed.

### F0 messages

F0 messages have a header area and a variable length string.

#### F0 fields

- from
    - uuid
    - port
- to
    - uuid
    - port
- type (see below) - 1 byte char
- sequences
    - last "highest" sent sequence (mine)
    - last "highest" received sequence (yours)
- int32 val
- int32 err code - 0 on all-ok.  high bit: 1 for error (0x80000000) (rest is an error code). If high bit is 0, low bits are a bitfield of warnings.
- string str (operand, 0 terminated - or 00 byte)

#### F0 types

- `i` idle
    - no message. just idle
- `p` ping
    - 'val' is a random value identifying the packet
    - receiver sends back a `P` pong with the same val
- `P` pong
    - 'val' is returned with a copy of the val from `p`
- `a` ack
    - 'val' is the sequence number of the other side, marking the packet as received
    - TODO investigate using the header value to obviate the ack
- `n` nack
    - 'val' is the seq number of a packet that is expected or failed and should be retried
- `c` close
    - request close of port
- `C` close-ack
    - acknowlege close 
    - val is 0
    - on error: 'err' is code and 'str' is message
- `o` open
    - 'str' is service ID, such as `/app/salt`, see service ids
    - `/app/*` is a request for a list (discovery)
- `O` open-ack
    - acknowledge open
    - 'str' is copied
    - from/to ports setup
    - on error: ports are 0, and str is error msg

## License

[Apache-2.0](../LICENSE)