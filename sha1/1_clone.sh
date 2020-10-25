#!/bin/bash

if [ ! -d "mbedtls" ]; then
	echo "clone mbedtls from Github."
	git clone --depth 1 --branch mbedtls-2.16 https://github.com/ARMmbed/mbedtls.git
	echo "done."
else
	echo "mbedtls already exist!"
fi



