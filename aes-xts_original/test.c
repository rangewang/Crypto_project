#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#include "aes.h"
#include "aes_pattern.h"

static void phex_size(uint8_t* str, uint16_t len);
static int encrypt_xts(uint8_t* src, uint16_t len, uint8_t* key1, uint8_t* key2, uint8_t* iv, uint8_t* dst);
static int decrypt_xts(uint8_t* src, uint16_t len, uint8_t* key1, uint8_t* key2, uint8_t* iv, uint8_t* dst);

int main(void)
{
    uint16_t i, exit = 0;
    uint8_t *src[] = {src0, src1, src2, src3, src4};
    uint16_t src_len[] = {sizeof(src0), sizeof(src1), sizeof(src2), sizeof(src3), sizeof(src4)};
    uint8_t *dst[] = {dst0, dst1, dst2, dst3, dst4};
    uint16_t dst_len[] = {sizeof(dst0), sizeof(dst1), sizeof(dst2), sizeof(dst3), sizeof(dst4)};
    uint8_t tmp[0x100];

    aes_config(AES128);
    for (i = 0 ; i < 5 ; i++) {
        encrypt_xts(src[i], src_len[i], key1_128, key2_128, tweak, dst[i]);
        decrypt_xts(dst[i], dst_len[i], key1_128, key2_128, tweak, tmp);
    }

    aes_config(AES256);
    for (i = 0 ; i < 5 ; i++) {
        encrypt_xts(src[i], src_len[i], key1_256, key2_256, tweak, dst[i]);
        decrypt_xts(dst[i], dst_len[i], key1_256, key2_256, tweak, tmp);
    }

    return exit;
}

//#define CODE_MODE
static void phex_size(uint8_t* str, uint16_t len)
{
    uint16_t i;

    for (i = 0; i < len; ++i) {
        if(!(i % AES_BLOCKLEN))
            printf("\n");
#ifdef CODE_MODE
        printf("0x%.2x, ", str[i]);
#else
        printf("%.2x ", str[i]);
#endif /* CODE_MODE */

    }
    printf("\n");
}

static int encrypt_xts(uint8_t* src, uint16_t len, uint8_t* key1, uint8_t* key2, uint8_t* iv, uint8_t* dst)
{
    uint8_t* cipher;
    uint16_t i, j, residual;
    uint8_t t = 0, tt = 0;
    uint8_t x[AES_BLOCKLEN] = { 0 };
    uint8_t y[AES_BLOCKLEN] = { 0 };
    uint8_t T[AES_BLOCKLEN] = { 0 };

    if (len < AES_BLOCKLEN) {
        printf("Data length at least 16 bytes\n");
        return -1;
    } else {
        printf("-----------------AES XTS Encryption-----------------\n");
        printf("\nData length: %d bytes\n", len);
    }

    cipher = (uint8_t*) malloc (len + AES_BLOCKLEN);

    residual = len % AES_BLOCKLEN;
    memcpy(T, iv, AES_IV_SIZE);


    AES_ECB_encrypt_new(key2, T);


    for (i = 0 ; i < len ; i += AES_BLOCKLEN) {

        memcpy(y, src + i, AES_BLOCKLEN);

        if (i == (len - residual))
            memcpy((y + residual), (cipher + i - AES_BLOCKLEN + residual), (AES_BLOCKLEN - residual));

        for (j = 0 ; j < AES_BLOCKLEN ; j++)
            x[j] = y[j] ^ T[j];


        AES_ECB_encrypt_new(key1, x);

        for (j = 0 ; j < AES_BLOCKLEN ; j++)
            cipher[i + j] = x[j] ^ T[j];

        if (i == (len - residual)) {
            memcpy(y, cipher + i, AES_BLOCKLEN);
            memcpy(cipher + i, cipher + i - AES_BLOCKLEN, residual);
            memcpy(cipher + i - AES_BLOCKLEN, y, AES_BLOCKLEN);
        }

        //Multiply by x
        for (j = 0; j < AES_BLOCKLEN; j++) {
            tt = T[j] >> 7;
            T[j] = ((T[j] << 1) | t) & 0xFF;
            t = tt;
        }

        if (tt > 0)
            T[0] ^= 0x87;
    }

    if (i < len) {

    }
    memcpy(dst, cipher, len);

    printf("plaintext:");
    phex_size(src, len);
    printf("ciphertext:");
    phex_size(dst, len);

    return 0;
}


static int decrypt_xts(uint8_t* src, uint16_t len, uint8_t* key1, uint8_t* key2, uint8_t* iv, uint8_t* dst)
{
    uint8_t* cipher;
    uint16_t i, j, residual;
    uint8_t t = 0, tt = 0;

    uint8_t x[AES_BLOCKLEN] = { 0 };
    uint8_t y[AES_BLOCKLEN] = { 0 };
    uint8_t T[AES_BLOCKLEN] = { 0 };
    uint8_t backup_T[AES_BLOCKLEN] = { 0 };

    if (len < AES_BLOCKLEN) {
        printf("Data length at least 16 bytes\n");
        return -1;
    } else {
        printf("-----------------AES XTS Decryption-----------------\n");
        printf("\nData length: %d bytes\n", len);
    }

    residual = len % AES_BLOCKLEN;

    cipher = (uint8_t*) malloc (len + AES_BLOCKLEN);

    memcpy(T, iv, AES_IV_SIZE);

    AES_ECB_encrypt_new(key2, T);

    for (i = 0 ; i < len ; i += AES_BLOCKLEN) {
        if (residual && (i == (len - AES_BLOCKLEN - residual))) {
            memcpy (backup_T, T, AES_BLOCKLEN);
            for (j = 0; j < AES_BLOCKLEN; j++) {
                tt = T[j] >> 7;
                T[j] = ((T[j] << 1) | t) & 0xFF;
                t = tt;
            }
            if (tt > 0)
                T[0] ^= 0x87;

            memcpy(y, src + i, AES_BLOCKLEN);
            for (j = 0 ; j < AES_BLOCKLEN ; j++)
                    x[j] = y[j] ^ T[j];
            AES_ECB_decrypt_new(key1, x);
            for (j = 0 ; j < AES_BLOCKLEN ; j++)
                    cipher[i + AES_BLOCKLEN + j] = x[j] ^ T[j];

            memcpy(y, src + i + AES_BLOCKLEN, residual);
            memcpy(y + residual, (cipher + i + AES_BLOCKLEN + residual), (AES_BLOCKLEN - residual));
            for (j = 0 ; j < AES_BLOCKLEN ; j++)
                    x[j] = y[j] ^ backup_T[j];
            AES_ECB_decrypt_new(key1, x);
            for (j = 0 ; j < AES_BLOCKLEN ; j++)
                    cipher[i + j] = x[j] ^ backup_T[j];
            break;
        } else {

                memcpy(y, src + i, AES_BLOCKLEN);
                for (j = 0 ; j < AES_BLOCKLEN ; j++)
                    x[j] = y[j] ^ T[j];

                AES_ECB_decrypt_new(key1, x);

                for (j = 0 ; j < AES_BLOCKLEN ; j++)
                    cipher[i + j] = x[j] ^ T[j];

                //Multiply by x
                for (j = 0; j < AES_BLOCKLEN; j++) {
                    tt = T[j] >> 7;
                    T[j] = ((T[j] << 1) | t) & 0xFF;
                    t = tt;
                }

                if (tt > 0)
                    T[0] ^= 0x87;
        }
    }

    memcpy(dst, cipher, len);

    printf("plaintext:");
    phex_size(src, len);
    printf("ciphertext:");
    phex_size(dst, len);

    return 0;
}
