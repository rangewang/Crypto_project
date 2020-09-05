#!/bin/bash

if [ $1 ]; then	
	dd count=$1 ibs=1 if=/dev/urandom > test.bin
	echo "done."
	echo "----------info----------"
	du -sh test.bin
	echo "------------------------"
	hexdump test.bin
	echo "------------------------"
else
	echo "add parameter to generate specific size of file."
	echo "ex: ./go.sh 32, it will generate a 32 bytes' file."
fi

