#!/bin/bash

if [ -d "./mbedtls/dev" ]; then
	echo "move ./mbedtls/dev to ./dev"
	mv ./mbedtls/dev ./
	echo "done"

else
	echo "./mbedtls/dev not exist!"
fi



