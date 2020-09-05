#ifndef _AES_H_
#define _AES_H_

#include <stdint.h>

#define AES128  0x1
#define AES192  0x2
#define AES256  0x3

#define AES_IV_SIZE     16
#define AES_BLOCKLEN 16 // Block length in bytes - AES is 128b block only

struct AES_ctx
{
  uint8_t RoundKey[240];
  uint8_t Iv[AES_BLOCKLEN];
};

void aes_config(uint8_t mode);
void AES_ECB_encrypt_new(uint8_t* key, uint8_t* buf);
void AES_ECB_decrypt_new(uint8_t* key, uint8_t* buf);

#endif // _AES_H_
