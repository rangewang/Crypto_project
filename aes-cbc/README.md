## README for AES-CBC by MbedTLS
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
1. [SP 800-38A Recommendation for Block Cipher Modes of Operation: Methods and Techniques](https://csrc.nist.gov/publications/detail/sp/800-38a/final)