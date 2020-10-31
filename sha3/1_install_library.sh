#!/bin/bash

if [ ! -d "tiny_sha3" ]; then
	echo "clone tiny_sha3 from Github."
	git clone --depth 1 https://github.com/mjosaarinen/tiny_sha3.git
	echo "done."
	echo "Copy files to /dev/library"
	mv tiny_sha3/sha3.* dev/library/
	echo "done."
	rm -rf tiny_sha3
else
	echo "tiny_sha3 already exist!"
fi



