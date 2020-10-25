#include <string.h>
#include "config.h"
#include "sha1.h"
#include "sha1_api.h"

int hal_sha1(uint8_t *src, uint16_t data_len, uint8_t *out)
{
    int count = 0, len;
    mbedtls_sha1_context ctx;

    mbedtls_sha1_init( &ctx );
    mbedtls_sha1_starts_ret( &ctx );

    if (data_len > 56) {
        while (count < data_len) {
            if( (data_len - count) < 56)
                len = data_len + count;
            else
                len = 56;
            mbedtls_sha1_update_ret( &ctx, src + count, len );
            count += 56;
        }
    } else {
        mbedtls_sha1_update_ret( &ctx, src, data_len );
    }

    mbedtls_sha1_finish_ret( &ctx, out );
    mbedtls_sha1_free( &ctx );

    return 0;
}
