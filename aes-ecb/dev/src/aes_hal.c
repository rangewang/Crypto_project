#include <string.h>
#include "config.h"
#include "aes.h"
#include "aes_api.h"

int hal_aes_ecb(uint8_t *key, uint8_t *src, uint8_t *out, int setkey_result, uint8_t mode, uint16_t key_len)
{
    int setkey_result_tmp;
    mbedtls_aes_context ctx;
    uint8_t internal_key[AES256];

    memcpy(internal_key, key, key_len);

    mbedtls_aes_init( &ctx );

    if (mode == ENCRYPT) {
        mode = MBEDTLS_AES_ENCRYPT;
        setkey_result_tmp = mbedtls_aes_setkey_enc( &ctx, key, key_len * 8 );
    } else { //DECRYPT
        mode = MBEDTLS_AES_DECRYPT;
        setkey_result_tmp = mbedtls_aes_setkey_dec( &ctx, key, key_len * 8 );
    }

    if(setkey_result == setkey_result_tmp)
        mbedtls_aes_crypt_ecb( &ctx, mode, src, out );

    mbedtls_aes_free( &ctx );

    return 0;
}

int hal_aes_ecb_multi(uint8_t *key, uint8_t *src, uint16_t data_len, uint8_t *out, int setkey_result, uint8_t mode, uint16_t key_len)
{
    int setkey_result_tmp;
    mbedtls_aes_context ctx;
    uint8_t internal_key[AES256];
    int blk = 0;

    if (data_len % 0x10)
        return -1;

    memcpy(internal_key, key, key_len);

    mbedtls_aes_init( &ctx );

    if (mode == ENCRYPT) {
        mode = MBEDTLS_AES_ENCRYPT;
        setkey_result_tmp = mbedtls_aes_setkey_enc( &ctx, key, key_len * 8 );
    } else { //DECRYPT
        mode = MBEDTLS_AES_DECRYPT;
        setkey_result_tmp = mbedtls_aes_setkey_dec( &ctx, key, key_len * 8 );
    }

    if (setkey_result == setkey_result_tmp) {
        for (blk = 0 ; blk < data_len ; blk+=0x10)
            mbedtls_aes_crypt_ecb( &ctx, mode, src + blk, out +blk);
    }

    mbedtls_aes_free( &ctx );

    return 0;
}

