#include <string.h>
#include "config.h"
#include "aes.h"
#include "aes_api.h"


int hal_aes128_xts(uint8_t *key1, uint8_t *key2, uint8_t *iv, uint8_t *src, uint16_t src_len, uint8_t *out, uint8_t mode)
{
    mbedtls_aes_xts_context ctx;
    uint8_t key[0x20];

    memcpy(key+0x00, key1, 0x10);
    memcpy(key+0x10, key2, 0x10);

    mbedtls_aes_xts_init( &ctx );
    if (mode == ENCRYPT) {
        mode = MBEDTLS_AES_ENCRYPT;
        mbedtls_aes_xts_setkey_enc( &ctx, key, sizeof(key) * 8 );

    } else { //DECRYPT
        mode = MBEDTLS_AES_DECRYPT;
        mbedtls_aes_xts_setkey_dec( &ctx, key, sizeof(key) * 8 );
    }

    mbedtls_aes_crypt_xts( &ctx, mode, src_len, iv, src, out );

    mbedtls_aes_xts_free( &ctx );

    return 0;
}

int hal_aes256_xts(uint8_t *key1, uint8_t *key2, uint8_t *iv, uint8_t *src, uint16_t src_len, uint8_t *out, uint8_t mode)
{
    mbedtls_aes_xts_context ctx;
    uint8_t key[0x40];

    memcpy(key+0x00, key1, 0x20);
    memcpy(key+0x20, key2, 0x20);

    mbedtls_aes_xts_init( &ctx );
    if (mode == ENCRYPT) {
        mode = MBEDTLS_AES_ENCRYPT;
        mbedtls_aes_xts_setkey_enc( &ctx, key, sizeof(key) * 8 );

    } else { //DECRYPT
        mode = MBEDTLS_AES_DECRYPT;
        mbedtls_aes_xts_setkey_dec( &ctx, key, sizeof(key) * 8 );
    }

    mbedtls_aes_crypt_xts( &ctx, mode, src_len, iv, src, out );

    mbedtls_aes_xts_free( &ctx );

    return 0;
}