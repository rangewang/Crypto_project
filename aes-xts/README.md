## README for AES-XTS by MbedTLS
-------------

### How to build up
-------------
#### Step 1: Download MbedTLS source code from MbedTLS Github  
`$ ./1_clone.sh`  
#### Step 2: Move ./dev folder to ./mbedtls/
`$ ./2_move_in.sh`  
#### Step 3: Enter the ./mbedtls/dev folder and executing ./build.sh  
`$ cd ./mbedtls/dev`  
`$ ./build.sh`  

### Backup and remove MbedTLS source code
-------------
Step 1: Move ./mbedtls/dev folder to ./  
`$ ./3_move_out.sh`  
Step 2: Delete ./mbedtls folder  
`$ ./4_clean.sh`

### Environment information
-------------
gcc (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0


### Reference
-------------
1. [Disk encryption theory](https://en.wikipedia.org/wiki/Disk_encryption_theory#XEX-based_tweaked-codebook_mode_with_ciphertext_stealing_(XTS))
2. [IEEE P1619™/D16](http://libeccio.di.unisa.it/Crypto14/Lab/p1619.pdf)