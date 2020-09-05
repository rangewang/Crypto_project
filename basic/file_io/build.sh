#!/bin/bash

make
./build/ex_out.elf

hexdump pattern/test_read.bin
hexdump pattern/test_write.bin

