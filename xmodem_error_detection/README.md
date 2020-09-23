## README for XMODEM CheckSum/CRC
-------------

### How to build up
-------------
#### Download MbedTLS source code from MbedTLS Github  
`$ ./build.sh`  

#### Pattern  
`$ ./pattern/`  

### Study
-------------
#### Verification  
T.B.D.

#### Note  
1. "If the file length is not an integer multiple of 128 bytes, the valid content of the last chunk is necessarily less than the frame length, and the remainder needs to be populated with other data, Xmodem recommends using the " Ctrl-z "(=26 (01aH)), in this case, how the receiver distinguishes between the contents of the file and the contents of the fill in that frame."  
2. "Important: The XMODEM protocol does not guarantee that the receiver receives a file length that is exactly the same as the sender,"  

### Environment information
-------------
gcc (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0


### Reference
-------------
1. [Xmodem protocol.](https://topic.alibabacloud.com/a/xmodem-protocol_8_8_10275011.html)
2. [XMODEM, CRC XMODEM, WXMODEM File Transfer Protocols](http://wiki.synchro.net/ref:xmodem)
3. [XModem和CRC校驗](https://www.twblogs.net/a/5b8e2ceb2b71771883435395)