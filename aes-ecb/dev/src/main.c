#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "aes_api.h"
#include "config.h"

void print_arr(uint8_t *arr, uint16_t size)
{
    uint16_t i;

    for (i = 0 ; i < size ; i++) {
        if (!(i % 16))
            printf("\n");
        printf("%02x ", arr[i]);
    }

}

int sec_compare(uint8_t *arr1, uint8_t *arr2, int size)
{
    int ret = 0, i = 0;

    /* for security reason
     * it guarantees execution time will be the same with match and mismatch data.
     */
    while ( i < size) {
        if (arr1[i] != arr2[i])
            ret = -1;
        i++;
    }

    return ret;
}

static void aes_ecb_128_test(void)
{
    FILE *keyf,  *dataf, *goldenf;
    uint8_t key[AES128];
    uint8_t data[AES_BLOCKLEN], golden[AES_BLOCKLEN], tmp[AES_BLOCKLEN];
    uint16_t len;

    keyf = fopen("./pattern/vector1_128_key.bin","rb");
    dataf = fopen("./pattern/vector1_128_ptx.bin","rb");
    goldenf = fopen("./pattern/vector1_128_ctx.bin","rb");

    fread(key, sizeof(key), 1, keyf);
    fread(data, sizeof(data), 1, dataf);
    fread(golden, sizeof(golden), 1, goldenf);

    printf("Test - AES-128-ECB Encrypt NIST KAT #1...");
    hal_aes_ecb(key, data, tmp, 0, ENCRYPT, AES128);
    if (!sec_compare(tmp, golden, AES_BLOCKLEN))
        printf("pass\n");
    else
        printf("fail\n");

    fclose(keyf);
    fclose(dataf);
    fclose(goldenf);

    keyf = fopen("./pattern/vector2_128_key.bin","rb");
    dataf = fopen("./pattern/vector2_128_ptx.bin","rb");
    goldenf = fopen("./pattern/vector2_128_ctx.bin","rb");

    fread(key, sizeof(key), 1, keyf);
    fread(data, sizeof(data), 1, dataf);
    fread(golden, sizeof(golden), 1, goldenf);

    printf("Test - AES-128-ECB Decrypt NIST KAT #1...");
    hal_aes_ecb(key, data, tmp, 0, DECRYPT, AES128);
    if (!sec_compare(tmp, golden, AES_BLOCKLEN))
        printf("pass\n");
    else
        printf("fail\n");

    fclose(keyf);
    fclose(dataf);
    fclose(goldenf);
}

static void aes_ecb_192_test(void)
{
    FILE *keyf,  *dataf, *goldenf;
    uint8_t key[AES192];
    uint8_t data[AES_BLOCKLEN], golden[AES_BLOCKLEN], tmp[AES_BLOCKLEN];
    uint16_t len;

    keyf = fopen("./pattern/vector1_192_key.bin","rb");
    dataf = fopen("./pattern/vector1_192_ptx.bin","rb");
    goldenf = fopen("./pattern/vector1_192_ctx.bin","rb");

    fread(key, sizeof(key), 1, keyf);
    fread(data, sizeof(data), 1, dataf);
    fread(golden, sizeof(golden), 1, goldenf);

    printf("Test - AES-192-ECB Encrypt NIST KAT #1...");
    hal_aes_ecb(key, data, tmp, 0, ENCRYPT, AES192);
    if (!sec_compare(tmp, golden, AES_BLOCKLEN))
        printf("pass\n");
    else
        printf("fail\n");

    fclose(keyf);
    fclose(dataf);
    fclose(goldenf);

    keyf = fopen("./pattern/vector2_192_key.bin","rb");
    dataf = fopen("./pattern/vector2_192_ptx.bin","rb");
    goldenf = fopen("./pattern/vector2_192_ctx.bin","rb");

    fread(key, sizeof(key), 1, keyf);
    fread(data, sizeof(data), 1, dataf);
    fread(golden, sizeof(golden), 1, goldenf);

    printf("Test - AES-192-ECB Decrypt NIST KAT #1...");
    hal_aes_ecb(key, data, tmp, 0, DECRYPT, AES192);
    if (!sec_compare(tmp, golden, AES_BLOCKLEN))
        printf("pass\n");
    else
        printf("fail\n");

    fclose(keyf);
    fclose(dataf);
    fclose(goldenf);
}

static void aes_ecb_256_test(void)
{
    FILE *keyf,  *dataf, *goldenf;
    uint8_t key[AES256];
    uint8_t data[AES_BLOCKLEN], golden[AES_BLOCKLEN], tmp[AES_BLOCKLEN];
    uint16_t len;

    keyf = fopen("./pattern/vector1_256_key.bin","rb");
    dataf = fopen("./pattern/vector1_256_ptx.bin","rb");
    goldenf = fopen("./pattern/vector1_256_ctx.bin","rb");

    fread(key, sizeof(key), 1, keyf);
    fread(data, sizeof(data), 1, dataf);
    fread(golden, sizeof(golden), 1, goldenf);

    printf("Test - AES-256-ECB Encrypt NIST KAT #1...");
    hal_aes_ecb(key, data, tmp, 0, ENCRYPT, AES256);
    if (!sec_compare(tmp, golden, AES_BLOCKLEN))
        printf("pass\n");
    else
        printf("fail\n");

    fclose(keyf);
    fclose(dataf);
    fclose(goldenf);

    keyf = fopen("./pattern/vector2_256_key.bin","rb");
    dataf = fopen("./pattern/vector2_256_ptx.bin","rb");
    goldenf = fopen("./pattern/vector2_256_ctx.bin","rb");

    fread(key, sizeof(key), 1, keyf);
    fread(data, sizeof(data), 1, dataf);
    fread(golden, sizeof(golden), 1, goldenf);

    printf("Test - AES-256-ECB Decrypt NIST KAT #1...");
    hal_aes_ecb(key, data, tmp, 0, DECRYPT, AES256);
    if (!sec_compare(tmp, golden, AES_BLOCKLEN))
        printf("pass\n");
    else
        printf("fail\n");

    fclose(keyf);
    fclose(dataf);
    fclose(goldenf);
}

static void aes_ecb_128_test_multi(void)
{
    FILE *keyf,  *dataf, *goldenf;
    uint8_t key[AES128];
    uint8_t data[AES_BLOCKLEN * 4], golden[AES_BLOCKLEN * 4], tmp[AES_BLOCKLEN * 4];
    uint16_t len;

    keyf = fopen("./pattern/multi_128_key.bin","rb");
    dataf = fopen("./pattern/multi_128_ptx.bin","rb");
    goldenf = fopen("./pattern/multi_128_ctx.bin","rb");

    fread(key, sizeof(key), 1, keyf);
    fread(data, sizeof(data), 1, dataf);
    fread(golden, sizeof(golden), 1, goldenf);

    printf("Test - F.1.1 ECB-AES128.Encrypt...");
    hal_aes_ecb_multi(key, data, 0x40, tmp, 0, ENCRYPT, AES128);
    if (!sec_compare(tmp, golden, 0x40))
        printf("pass\n");
    else
        printf("fail\n");

    printf("Test - F.1.2 ECB-AES128.Decrypt...");
    hal_aes_ecb_multi(key, golden, 0x40, tmp, 0, DECRYPT, AES128);
    if (!sec_compare(tmp, data, 0x40))
        printf("pass\n");
    else
        printf("fail\n");

    fclose(keyf);
    fclose(dataf);
    fclose(goldenf);
}

static void aes_ecb_192_test_multi(void)
{
    FILE *keyf,  *dataf, *goldenf;
    uint8_t key[AES192];
    uint8_t data[AES_BLOCKLEN * 4], golden[AES_BLOCKLEN * 4], tmp[AES_BLOCKLEN * 4];
    uint16_t len;

    keyf = fopen("./pattern/multi_192_key.bin","rb");
    dataf = fopen("./pattern/multi_192_ptx.bin","rb");
    goldenf = fopen("./pattern/multi_192_ctx.bin","rb");

    fread(key, sizeof(key), 1, keyf);
    fread(data, sizeof(data), 1, dataf);
    fread(golden, sizeof(golden), 1, goldenf);

    printf("Test - F.1.1 ECB-AES192.Encrypt...");
    hal_aes_ecb_multi(key, data, 0x40, tmp, 0, ENCRYPT, AES192);
    if (!sec_compare(tmp, golden, 0x40))
        printf("pass\n");
    else
        printf("fail\n");

    printf("Test - F.1.2 ECB-AES192.Decrypt...");
    hal_aes_ecb_multi(key, golden, 0x40, tmp, 0, DECRYPT, AES192);
    if (!sec_compare(tmp, data, 0x40))
        printf("pass\n");
    else
        printf("fail\n");

    fclose(keyf);
    fclose(dataf);
    fclose(goldenf);
}

static void aes_ecb_256_test_multi(void)
{
    FILE *keyf,  *dataf, *goldenf;
    uint8_t key[AES256];
    uint8_t data[AES_BLOCKLEN * 4], golden[AES_BLOCKLEN * 4], tmp[AES_BLOCKLEN * 4];
    uint16_t len;

    keyf = fopen("./pattern/multi_256_key.bin","rb");
    dataf = fopen("./pattern/multi_256_ptx.bin","rb");
    goldenf = fopen("./pattern/multi_256_ctx.bin","rb");

    fread(key, sizeof(key), 1, keyf);
    fread(data, sizeof(data), 1, dataf);
    fread(golden, sizeof(golden), 1, goldenf);

    printf("Test - F.1.1 ECB-AES256.Encrypt...");
    hal_aes_ecb_multi(key, data, 0x40, tmp, 0, ENCRYPT, AES256);
    if (!sec_compare(tmp, golden, 0x40))
        printf("pass\n");
    else
        printf("fail\n");

    printf("Test - F.1.2 ECB-AES256.Decrypt...");
    hal_aes_ecb_multi(key, golden, 0x40, tmp, 0, DECRYPT, AES256);
    if (!sec_compare(tmp, data, 0x40))
        printf("pass\n");
    else
        printf("fail\n");

    fclose(keyf);
    fclose(dataf);
    fclose(goldenf);
}


int main(void)
{
    printf("\n---------------------Single Block--------------------- \n");
    aes_ecb_128_test();
    aes_ecb_192_test();
    aes_ecb_256_test();

    printf("\n---------------------Multiple Blocks--------------------- \n");
    aes_ecb_128_test_multi();
    aes_ecb_192_test_multi();
    aes_ecb_256_test_multi();


    return 0;
}
