#!/bin/bash

if [ -d "mbedtls" ]; then
	echo "move ./dev to ./mbedtls/dev"
	mv ./dev ./mbedtls
	cd ./mbedtls/dev
	chmod a+x ./build.sh
	echo "done"
	echo "run build at ./mbedtls/dev/build.sh"

else
	echo "mbedtls not exist!"
fi



