#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#include "aes.h"
#include "aes_pattern.h"
static void phex(uint8_t* str);
static void phex_size(uint8_t* str, uint16_t len);
static void encrypt_xts(uint8_t* src, uint16_t len, uint8_t* key1, uint8_t* key2, uint8_t* iv, uint8_t* dst);
static void decrypt_xts(uint8_t* src, uint16_t len, uint8_t* key1, uint8_t* key2, uint8_t* iv, uint8_t* dst);

int main(void)
{
    int exit = 0;
    uint8_t *src[] = {src0, src1, src2, src3, src4};
    uint16_t src_len[] = {sizeof(src0), sizeof(src1), sizeof(src2), sizeof(src3), sizeof(src4)};
    uint8_t *dst[] = {dst0, dst1, dst2, dst3, dst4};
    uint16_t dst_len[] = {sizeof(dst0), sizeof(dst1), sizeof(dst2), sizeof(dst3), sizeof(dst4)};
    uint8_t tmp[0x10];


    aes_config(2);
    encrypt_xts(src[0], src_len[0], key1_128, key2_128, tweak, dst[0]);
    decrypt_xts(dst[0], dst_len[0], key1_128, key2_128, tweak, tmp);

    return exit;
}


// prints string as hex
static void phex(uint8_t* str)
{

    uint8_t len = 16;

    unsigned char i;
    for (i = 0; i < len; ++i)
        printf("%.2x", str[i]);
    printf("\n");
}

#define CODE_MODE
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

static void golden_check(uint8_t* out, uint8_t* gold, uint16_t len)
{

    if (memcmp (out, gold, len))
        printf("fail\n");
    else
        printf("pass\n");
}

static void encrypt_xts(uint8_t* src, uint16_t len, uint8_t* key1, uint8_t* key2, uint8_t* iv, uint8_t* dst)
{
    uint8_t* cipher;
    uint16_t i, j;
    uint8_t t = 0, tt = 0;

    uint8_t x[AES_BLOCKLEN] = { 0 };
    uint8_t T[AES_BLOCKLEN] = { 0 };

    cipher = (uint8_t*) malloc (len + AES_BLOCKLEN);

    memcpy(T, iv, AES_IV_SIZE);
    printf("T:\n");
    phex(T);

    AES_ECB_encrypt_new(key2, T);


    for (i = 0 ; i < len ; i += AES_BLOCKLEN) {

        printf("1. plain:\n");
        phex(src);

        for (j = 0 ; j < AES_BLOCKLEN ; j++)
            x[j] = src[i + j] ^ T[j];

        printf("2. and:\n");
        phex(x);

        AES_ECB_encrypt_new(key1, x);

        printf("3. en:\n");
        phex(x);

        for (j = 0 ; j < AES_BLOCKLEN ; j++)
            cipher[i + j] = x[j] ^ T[j];

        printf("4. en+and:\n");
        phex(cipher);

        //Multiply by x
        for (j = 0; j < AES_BLOCKLEN; j++) {
            tt = T[j] >> 7;
            T[j] = ((T[j] << 1) | t) & 0xFF;
            t = tt;
        }

        if (tt > 0)
            T[0] ^= 0x87;
    }

    memcpy(dst, cipher, len);

    printf("plaintext:");
    phex_size(src, len);
    printf("ciphertext:");
    phex_size(dst, len);

}


static void decrypt_xts(uint8_t* src, uint16_t len, uint8_t* key1, uint8_t* key2, uint8_t* iv, uint8_t* dst)
{
    uint8_t* cipher;
    uint16_t i, j;
    uint8_t t = 0, tt = 0;

    uint8_t x[AES_BLOCKLEN] = { 0 };
    uint8_t T[AES_BLOCKLEN] = { 0 };

    cipher = (uint8_t*) malloc (len + AES_BLOCKLEN);

    memcpy(T, iv, AES_IV_SIZE);
    printf("T:\n");
    phex(T);

    AES_ECB_encrypt_new(key2, T);


    for (i = 0 ; i < len ; i += AES_BLOCKLEN) {

        printf("1. en+and:\n");
        phex(src);

        for (j = 0 ; j < AES_BLOCKLEN ; j++)
            x[j] = src[i + j] ^ T[j];

        printf("2. and:\n");
        phex(x);

        AES_ECB_decrypt_new(key1, x);

        printf("3. en:\n");
        phex(x);

        for (j = 0 ; j < AES_BLOCKLEN ; j++)
            cipher[i + j] = x[j] ^ T[j];

        printf("4. en+and:\n");
        phex(cipher);

        //Multiply by x
        for (j = 0; j < AES_BLOCKLEN; j++) {
            tt = T[j] >> 7;
            T[j] = ((T[j] << 1) | t) & 0xFF;
            t = tt;
        }

        if (tt > 0)
            T[0] ^= 0x87;
    }

    memcpy(dst, cipher, len);

    printf("plaintext:");
    phex_size(src, len);
    printf("ciphertext:");
    phex_size(dst, len);

}




