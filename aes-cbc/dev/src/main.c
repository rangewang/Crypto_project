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

static void aes_cbc_128_test(void)
{
    FILE *keyf, *ivf, *dataf, *goldenf;
    uint8_t key[AES128], iv[0x10];
    uint8_t data[DATA_SIZE], golden[DATA_SIZE], tmp[DATA_SIZE];
    uint16_t len;

    keyf = fopen("./pattern/vector1_128_key.bin","rb");
    ivf = fopen("./pattern/vector1_128_iv.bin","rb");
    dataf = fopen("./pattern/vector1_128_ptx.bin","rb");
    goldenf = fopen("./pattern/vector1_128_ctx.bin","rb");

    fread(key, sizeof(key), 1, keyf);
    fread(iv, sizeof(iv), 1, ivf);
    fread(data, sizeof(data), 1, dataf);
    fread(golden, sizeof(golden), 1, goldenf);

    printf("Test - F.2.1CBC-AES128.Encrypt...");
    hal_aes_cbc(data, DATA_SIZE, key, AES128, iv, tmp, ENCRYPT);

    if (!sec_compare(tmp, golden, DATA_SIZE))
        printf("pass\n");
    else
        printf("fail\n");


    fseek(ivf, 0, SEEK_SET);
    fread(iv, sizeof(iv), 1, ivf);

    printf("Test - F.2.2CBC-AES128.Decrypt...");
    hal_aes_cbc(golden, DATA_SIZE, key, AES128, iv, tmp, DECRYPT);

    if (!sec_compare(tmp, data, DATA_SIZE))
        printf("pass\n");
    else
        printf("fail\n");

    fclose(keyf);
    fclose(ivf);
    fclose(dataf);
    fclose(goldenf);
}

static void aes_cbc_192_test(void)
{
    FILE *keyf, *ivf, *dataf, *goldenf;
    uint8_t key[AES192], iv[0x10];
    uint8_t data[DATA_SIZE], golden[DATA_SIZE], tmp[DATA_SIZE];
    uint16_t len;

    keyf = fopen("./pattern/vector1_192_key.bin","rb");
    ivf = fopen("./pattern/vector1_192_iv.bin","rb");
    dataf = fopen("./pattern/vector1_192_ptx.bin","rb");
    goldenf = fopen("./pattern/vector1_192_ctx.bin","rb");

    fread(key, sizeof(key), 1, keyf);
    fread(iv, sizeof(iv), 1, ivf);
    fread(data, sizeof(data), 1, dataf);
    fread(golden, sizeof(golden), 1, goldenf);

    printf("Test - F.2.1CBC-AES192.Encrypt...");
    hal_aes_cbc(data, DATA_SIZE, key, AES192, iv, tmp, ENCRYPT);

    if (!sec_compare(tmp, golden, DATA_SIZE))
        printf("pass\n");
    else
        printf("fail\n");


    fseek(ivf, 0, SEEK_SET);
    fread(iv, sizeof(iv), 1, ivf);

    printf("Test - F.2.2CBC-AES192.Decrypt...");
    hal_aes_cbc(golden, DATA_SIZE, key, AES192, iv, tmp, DECRYPT);

    if (!sec_compare(tmp, data, DATA_SIZE))
        printf("pass\n");
    else
        printf("fail\n");

    fclose(keyf);
    fclose(ivf);
    fclose(dataf);
    fclose(goldenf);
}

static void aes_cbc_256_test(void)
{
    FILE *keyf, *ivf, *dataf, *goldenf;
    uint8_t key[AES256], iv[0x10];
    uint8_t data[DATA_SIZE], golden[DATA_SIZE], tmp[DATA_SIZE];
    uint16_t len;

    keyf = fopen("./pattern/vector1_256_key.bin","rb");
    ivf = fopen("./pattern/vector1_256_iv.bin","rb");
    dataf = fopen("./pattern/vector1_256_ptx.bin","rb");
    goldenf = fopen("./pattern/vector1_256_ctx.bin","rb");

    fread(key, sizeof(key), 1, keyf);
    fread(iv, sizeof(iv), 1, ivf);
    fread(data, sizeof(data), 1, dataf);
    fread(golden, sizeof(golden), 1, goldenf);

    printf("Test - F.2.1CBC-AES256.Encrypt...");
    hal_aes_cbc(data, DATA_SIZE, key, AES256, iv, tmp, ENCRYPT);

    if (!sec_compare(tmp, golden, DATA_SIZE))
        printf("pass\n");
    else
        printf("fail\n");


    fseek(ivf, 0, SEEK_SET);
    fread(iv, sizeof(iv), 1, ivf);

    printf("Test - F.2.2CBC-AES256.Decrypt...");
    hal_aes_cbc(golden, DATA_SIZE, key, AES256, iv, tmp, DECRYPT);

    if (!sec_compare(tmp, data, DATA_SIZE))
        printf("pass\n");
    else
        printf("fail\n");

    fclose(keyf);
    fclose(ivf);
    fclose(dataf);
    fclose(goldenf);
}

int main(void)
{
    aes_cbc_128_test();
    aes_cbc_192_test();
    aes_cbc_256_test();

    return 0;
}
