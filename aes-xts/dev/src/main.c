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

int aes_xts_128_test(void)
{
    FILE *key1f, *key2f, *ivf, *dataf, *goldenf;
    uint8_t key1[0x10], key2[0x10], iv[0x10];
    uint8_t data[0x200], golden[0x200], tmp[0x200];
    uint16_t len;

    key1f = fopen("./pattern/vector1_key1.bin","rb");
    key2f = fopen("./pattern/vector1_key2.bin","rb");
    ivf = fopen("./pattern/vector1_iv.bin","rb");
    dataf = fopen("./pattern/vector1_ptx.bin","rb");
    goldenf = fopen("./pattern/vector1_ctx.bin","rb");

    fread(key1, sizeof(key1), 1, key1f);
    fread(key2, sizeof(key2), 1, key2f);
    fread(iv, sizeof(iv), 1, ivf);
    while (1) {
        len = fread(data, 0x200, 1, dataf);

        if (len == 0)
            break;
        else
            printf("Note: data size >= 0x200.\n");
    }

    while (1) {
        len = fread(golden, 0x200, 1, goldenf);

        if (len == 0)
            break;
        else
            printf("Note: data size >= 0x200.\n");
    }

    printf("Test - AES-128-XTS Encrypt IEEE P1619/D16 Vector 1...");
    hal_aes128_xts(key1, key2, iv, data, 0x20, tmp, ENCRYPT);
    if (!sec_compare(tmp, golden, 0x20))
        printf("pass\n");
    else
        printf("fail\n");

    printf("Test - AES-128-XTS Decrypt IEEE P1619/D16 Vector 1...");
    hal_aes128_xts(key1, key2, iv, golden, 0x20, tmp, DECRYPT);
    if (!sec_compare(tmp, data, 0x20))
        printf("pass\n");
    else
        printf("fail\n");

    fclose(key1f);
    fclose(key2f);
    fclose(ivf);
    fclose(dataf);
    fclose(goldenf);
}

int aes_xts_256_test(void)
{
    FILE *key1f, *key2f, *ivf, *dataf, *goldenf;
    uint8_t key1[0x20], key2[0x20], iv[0x10];
    uint8_t data[0x200], golden[0x200], tmp[0x200];
    uint16_t len;

    key1f = fopen("./pattern/vector10_key1.bin","rb");
    key2f = fopen("./pattern/vector10_key2.bin","rb");
    ivf = fopen("./pattern/vector10_iv.bin","rb");
    dataf = fopen("./pattern/vector10_ptx.bin","rb");
    goldenf = fopen("./pattern/vector10_ctx.bin","rb");

    fread(key1, sizeof(key1), 1, key1f);
    fread(key2, sizeof(key2), 1, key2f);
    fread(iv, sizeof(iv), 1, ivf);
    while (1) {
        len = fread(data, 0x200, 1, dataf);

        if (len == 0)
            break;
        else
            printf("Note: data size >= 0x200.\n");
    }

    while (1) {
        len = fread(golden, 0x200, 1, goldenf);
        if (len == 0)
            break;
        else
            printf("Note: data size >= 0x200.\n");
    }

    printf("Test - AES-256-XTS Encrypt IEEE P1619/D16 Vector 10...");
    hal_aes256_xts(key1, key2, iv, data, 0x200, tmp, ENCRYPT);
    if (!sec_compare(tmp, golden, 0x200))
        printf("pass\n");
    else
        printf("fail\n");

    printf("Test - AES-256-XTS Decrypt IEEE P1619/D16 Vector 10...");
    hal_aes256_xts(key1, key2, iv, golden, 0x200, tmp, DECRYPT);
    if (!sec_compare(tmp, data, 0x200))
        printf("pass\n");
    else
        printf("fail\n");

    fclose(key1f);
    fclose(key2f);
    fclose(ivf);
    fclose(dataf);
    fclose(goldenf);
}

int aes_xts_128_non16bytes_test(void)
{
    FILE *key1f, *key2f, *ivf, *dataf, *goldenf;
    uint8_t key1[0x10], key2[0x10], iv[0x10];
    uint8_t data[0x200], golden[0x200], tmp[0x200];
    uint16_t len;

    key1f = fopen("./pattern/vector15_key1.bin","rb");
    key2f = fopen("./pattern/vector15_key2.bin","rb");
    ivf = fopen("./pattern/vector15_iv.bin","rb");
    dataf = fopen("./pattern/vector15_ptx.bin","rb");
    goldenf = fopen("./pattern/vector15_ctx.bin","rb");

    fread(key1, sizeof(key1), 1, key1f);
    fread(key2, sizeof(key2), 1, key2f);
    fread(iv, sizeof(iv), 1, ivf);
    while (1) {
        len = fread(data, 0x200, 1, dataf);

        if (len == 0)
            break;
        else
            printf("Note: data size >= 0x200.\n");
    }

    while (1) {
        len = fread(golden, 0x200, 1, goldenf);
        if (len == 0)
            break;
        else
            printf("Note: data size >= 0x200.\n");
    }

    printf("Test - AES-256-XTS Encrypt IEEE P1619/D16 Vector 10...");
    hal_aes128_xts(key1, key2, iv, data, 0x11, tmp, ENCRYPT);
    if (!sec_compare(tmp, golden, 0x11))
        printf("pass\n");
    else
        printf("fail\n");

    printf("Test - AES-256-XTS Decrypt IEEE P1619/D16 Vector 10...");
    hal_aes128_xts(key1, key2, iv, golden, 0x11, tmp, DECRYPT);
    if (!sec_compare(tmp, data, 0x11))
        printf("pass\n");
    else
        printf("fail\n");

    fclose(key1f);
    fclose(key2f);
    fclose(ivf);
    fclose(dataf);
    fclose(goldenf);
}

int main(void)
{
    printf("\nXTS-AES-128 applied for a data unit of 512 bytes\n");
    aes_xts_128_test();

    printf("\nXTS-AES-256 applied for a data unit of 512 bytes\n");
    aes_xts_256_test();

    printf("\nXTS-AES-128 applied for a data unit that is not a multiple of 16 bytes\n");
    aes_xts_128_non16bytes_test();

    return 0;
}
