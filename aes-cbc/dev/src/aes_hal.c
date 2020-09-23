#include <string.h>
#include "config.h"
#include "aes.h"
#include "aes_api.h"

int hal_aes_cbc(uint8_t *src, uint16_t data_len, uint8_t *key, uint16_t key_len, uint8_t *iv, uint8_t *out, uint8_t mode)
{
    mbedtls_aes_context ctx;
    uint8_t internal_key[AES256];

    memcpy(internal_key, key, key_len);

    mbedtls_aes_init( &ctx );

    if (mode == ENCRYPT) {
        mode = MBEDTLS_AES_ENCRYPT;
        mbedtls_aes_setkey_enc( &ctx, key, key_len * 8 );
    } else { //DECRYPT
        mode = MBEDTLS_AES_DECRYPT;
        mbedtls_aes_setkey_dec( &ctx, key, key_len * 8 );
    }

    mbedtls_aes_crypt_cbc( &ctx, mode, data_len, iv, src, out );

    mbedtls_aes_free( &ctx );

    return 0;
}

