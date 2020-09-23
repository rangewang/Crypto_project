#!/bin/bash

if [ ! -d "mbedtls" ]; then
	echo "mbedtls not exist!"
else
	read -p "Delete mbedtls folder? " -n 1 -r
	echo
	if [[ $REPLY =~ ^[Yy]$ ]]; then
		rm -rf mbedtls
	fi
	echo "done."
fi



