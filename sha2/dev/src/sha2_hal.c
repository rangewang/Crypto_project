#include <string.h>
#include "config.h"
#include "sha256.h"
#include "sha512.h"
#include "sha2_api.h"

int hal_sha2(uint8_t *src, uint16_t data_len, uint8_t *out, uint16_t mode)
{
    mbedtls_sha256_context ctx256;
    mbedtls_sha512_context ctx512;

    if (mode == 224 || mode == 256) {
        mbedtls_sha256_init( &ctx256 );
        if (mode == 224)
            mbedtls_sha256_starts_ret( &ctx256, 1 );
        else if (mode == 256)
            mbedtls_sha256_starts_ret( &ctx256, 0 );
        mbedtls_sha256_update_ret( &ctx256, src, data_len );
        mbedtls_sha256_finish_ret( &ctx256, out );
        mbedtls_sha256_free( &ctx256 );
    } else if (mode == 384 || mode == 512) {
        mbedtls_sha512_init( &ctx512 );
        if (mode == 384)
            mbedtls_sha512_starts_ret( &ctx512, 1 );
        else if (mode == 512)
            mbedtls_sha512_starts_ret( &ctx512, 0 );
        mbedtls_sha512_update_ret( &ctx512, src, data_len );
        mbedtls_sha512_finish_ret( &ctx512, out );
        mbedtls_sha512_free( &ctx512 );
    }

    return 0;
}
