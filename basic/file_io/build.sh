#!/bin/bash

make
./output/ex_out.elf

hexdump pattern/test_read.bin
hexdump pattern/test_write.bin

