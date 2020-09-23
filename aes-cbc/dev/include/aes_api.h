#ifndef _AES_API_H_
#define _AES_API_H_

int hal_aes_cbc(uint8_t *src, uint16_t data_len, uint8_t *key, uint16_t key_len, uint8_t *iv, uint8_t *out, uint8_t mode);


#endif // _AES_API_H_
