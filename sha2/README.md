## README for SHA-2 by MbedTLS
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
#### Step 1: Move ./mbedtls/dev folder to ./  
`$ ./3_move_out.sh`  
#### Step 2: Delete ./mbedtls folder  
`$ ./4_clean.sh`

### Environment information
-------------
gcc (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0


### Reference
-------------
1. [Test vectors for SHA-1, SHA-2 and SHA-3](https://www.di-mgt.com.au/sha_testvectors.html)
2. [Hash Functions](https://csrc.nist.gov/projects/hash-functions)
3. [Secure Hash Algorithm](https://csrc.nist.gov/csrc/media/projects/cryptographic-standards-and-guidelines/documents/examples/sha_all.pdf)
3. [Secure Hash Algorithm - wikipedia](https://en.wikipedia.org/wiki/Secure_Hash_Algorithms)