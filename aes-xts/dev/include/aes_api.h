#ifndef _AES_API_H_
#define _AES_API_H_

int hal_aes128_xts(uint8_t *key1, uint8_t *key2, uint8_t *iv, uint8_t *src, uint16_t src_len, uint8_t *out, uint8_t mode);
int hal_aes256_xts(uint8_t *key1, uint8_t *key2, uint8_t *iv, uint8_t *src, uint16_t src_len, uint8_t *out, uint8_t mode);


#endif // _AES_API_H_
