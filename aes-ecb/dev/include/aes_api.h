#ifndef _AES_API_H_
#define _AES_API_H_

int hal_aes_ecb(uint8_t *key, uint8_t *src, uint8_t *out, int setkey_result, uint8_t mode, uint16_t key_len);

#endif // _AES_API_H_
