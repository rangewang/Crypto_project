#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "../library/sha3.h"
#include "config.h"

void print_arr(uint8_t *arr, uint16_t size)
{
    uint16_t i;

printf("---------------------------------------");
    for (i = 0 ; i < size ; i++) {
        if (!(i % 16))
            printf("\n");
        printf("%02x ", arr[i]);
    }
printf("\n---------------------------------------\n");
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

int sha3_224_test(void)
{
    FILE *dataf, *goldenf;
    uint8_t data[0x100], golden[28], hash_result[28];

    dataf = fopen("./pattern/vector1_0.bin","rb");
    goldenf = fopen("./pattern/vector1_0_224_golden.bin","rb");

    fread(data, 0, 1, dataf);
    fread(golden, sizeof(golden), 1, goldenf);

    printf("Test - SHA-3-224 FIPS 202 length=0 bytes...");
    sha3(data, 0, hash_result, sizeof(hash_result));
    if (!sec_compare(hash_result, golden, 28))
        printf("pass\n");
    else
        printf("fail\n");

    fclose(dataf);
    fclose(goldenf);

    dataf = fopen("./pattern/vector1_3.bin","rb");
    goldenf = fopen("./pattern/vector1_3_224_golden.bin","rb");

    fread(data, 3, 1, dataf);
    fread(golden, sizeof(golden), 1, goldenf);

    printf("Test - SHA-3-224 FIPS 202 length=3 bytes...");
    sha3(data, 3, hash_result, sizeof(hash_result));
    if (!sec_compare(hash_result, golden, 28))
        printf("pass\n");
    else
        printf("fail\n");

    fclose(dataf);
    fclose(goldenf);

    dataf = fopen("./pattern/vector1_56.bin","rb");
    goldenf = fopen("./pattern/vector1_56_224_golden.bin","rb");

    fread(data, 56, 1, dataf);
    fread(golden, sizeof(golden), 1, goldenf);

    printf("Test - SHA-3-224 FIPS 202 length=56 bytes...");
    sha3(data, 56, hash_result, sizeof(hash_result));
    if (!sec_compare(hash_result, golden, 28))
        printf("pass\n");
    else
        printf("fail\n");

    fclose(dataf);
    fclose(goldenf);

    dataf = fopen("./pattern/vector1_112.bin","rb");
    goldenf = fopen("./pattern/vector1_112_224_golden.bin","rb");

    fread(data, 112, 1, dataf);
    fread(golden, sizeof(golden), 1, goldenf);

    printf("Test - SHA-3-224 FIPS 202 length=112 bytes...");
    sha3(data, 112, hash_result, sizeof(hash_result));
    if (!sec_compare(hash_result, golden, 28))
        printf("pass\n");
    else
        printf("fail\n");

    fclose(dataf);
    fclose(goldenf);
}

int sha3_256_test(void)
{
    FILE *dataf, *goldenf;
    uint8_t data[0x100], golden[0x20], hash_result[0x20];

    dataf = fopen("./pattern/vector1_0.bin","rb");
    goldenf = fopen("./pattern/vector1_0_256_golden.bin","rb");

    fread(data, 0, 1, dataf);
    fread(golden, sizeof(golden), 1, goldenf);

    printf("Test - SHA-3-256 FIPS 202 length=0 bytes...");
    sha3(data, 0, hash_result, sizeof(hash_result));
    if (!sec_compare(hash_result, golden, 0x20))
        printf("pass\n");
    else
        printf("fail\n");

    fclose(dataf);
    fclose(goldenf);

    dataf = fopen("./pattern/vector1_3.bin","rb");
    goldenf = fopen("./pattern/vector1_3_256_golden.bin","rb");

    fread(data, 3, 1, dataf);
    fread(golden, sizeof(golden), 1, goldenf);

    printf("Test - SHA-3-256 FIPS 202 length=3 bytes...");
    sha3(data, 3, hash_result, sizeof(hash_result));
    if (!sec_compare(hash_result, golden, 0x20))
        printf("pass\n");
    else
        printf("fail\n");

    fclose(dataf);
    fclose(goldenf);

    dataf = fopen("./pattern/vector1_56.bin","rb");
    goldenf = fopen("./pattern/vector1_56_256_golden.bin","rb");

    fread(data, 56, 1, dataf);
    fread(golden, sizeof(golden), 1, goldenf);

    printf("Test - SHA-3-256 FIPS 202 length=56 bytes...");
    sha3(data, 56, hash_result, sizeof(hash_result));
    if (!sec_compare(hash_result, golden, 0x20))
        printf("pass\n");
    else
        printf("fail\n");

    fclose(dataf);
    fclose(goldenf);

    dataf = fopen("./pattern/vector1_112.bin","rb");
    goldenf = fopen("./pattern/vector1_112_256_golden.bin","rb");

    fread(data, 112, 1, dataf);
    fread(golden, sizeof(golden), 1, goldenf);

    printf("Test - SHA-3-256 FIPS 202 length=112 bytes...");
    sha3(data, 112, hash_result, sizeof(hash_result));
    if (!sec_compare(hash_result, golden, 0x20))
        printf("pass\n");
    else
        printf("fail\n");

    fclose(dataf);
    fclose(goldenf);
}

int sha3_384_test(void)
{
    FILE *dataf, *goldenf;
    uint8_t data[0x100], golden[0x30], hash_result[0x30];

    dataf = fopen("./pattern/vector1_0.bin","rb");
    goldenf = fopen("./pattern/vector1_0_384_golden.bin","rb");

    fread(data, 0, 1, dataf);
    fread(golden, sizeof(golden), 1, goldenf);

    printf("Test - SHA-3-384 FIPS 202 length=0 bytes...");
    sha3(data, 0, hash_result, sizeof(hash_result));
    if (!sec_compare(hash_result, golden, 0x30))
        printf("pass\n");
    else
        printf("fail\n");

    fclose(dataf);
    fclose(goldenf);

    dataf = fopen("./pattern/vector1_3.bin","rb");
    goldenf = fopen("./pattern/vector1_3_384_golden.bin","rb");

    fread(data, 3, 1, dataf);
    fread(golden, sizeof(golden), 1, goldenf);

    printf("Test - SHA-3-384 FIPS 202 length=3 bytes...");
    sha3(data, 3, hash_result, sizeof(hash_result));
    if (!sec_compare(hash_result, golden, 0x30))
        printf("pass\n");
    else
        printf("fail\n");

    fclose(dataf);
    fclose(goldenf);

    dataf = fopen("./pattern/vector1_56.bin","rb");
    goldenf = fopen("./pattern/vector1_56_384_golden.bin","rb");

    fread(data, 56, 1, dataf);
    fread(golden, sizeof(golden), 1, goldenf);

    printf("Test - SHA-3-384 FIPS 202 length=56 bytes...");
    sha3(data, 56, hash_result, sizeof(hash_result));
    if (!sec_compare(hash_result, golden, 0x30))
        printf("pass\n");
    else
        printf("fail\n");

    fclose(dataf);
    fclose(goldenf);

    dataf = fopen("./pattern/vector1_112.bin","rb");
    goldenf = fopen("./pattern/vector1_112_384_golden.bin","rb");

    fread(data, 112, 1, dataf);
    fread(golden, sizeof(golden), 1, goldenf);

    printf("Test - SHA-3-384 FIPS 202 length=112 bytes...");
    sha3(data, 112, hash_result, sizeof(hash_result));
    if (!sec_compare(hash_result, golden, 0x30))
        printf("pass\n");
    else
        printf("fail\n");


    fclose(dataf);
    fclose(goldenf);
}


int sha3_512_test(void)
{
    FILE *dataf, *goldenf;
    uint8_t data[0x100], golden[0x40], hash_result[0x40];

    dataf = fopen("./pattern/vector1_0.bin","rb");
    goldenf = fopen("./pattern/vector1_0_512_golden.bin","rb");

    fread(data, 0, 1, dataf);
    fread(golden, sizeof(golden), 1, goldenf);

    printf("Test - SHA-3-512 FIPS 202 length=0 bytes...");
    sha3(data, 0, hash_result, sizeof(hash_result));
    if (!sec_compare(hash_result, golden, 0x40))
        printf("pass\n");
    else
        printf("fail\n");

    fclose(dataf);
    fclose(goldenf);

    dataf = fopen("./pattern/vector1_3.bin","rb");
    goldenf = fopen("./pattern/vector1_3_512_golden.bin","rb");

    fread(data, 3, 1, dataf);
    fread(golden, sizeof(golden), 1, goldenf);

    printf("Test - SHA-3-512 FIPS 202 length=3 bytes...");
    sha3(data, 3, hash_result, sizeof(hash_result));
    if (!sec_compare(hash_result, golden, 0x40))
        printf("pass\n");
    else
        printf("fail\n");

    fclose(dataf);
    fclose(goldenf);

    dataf = fopen("./pattern/vector1_56.bin","rb");
    goldenf = fopen("./pattern/vector1_56_512_golden.bin","rb");

    fread(data, 56, 1, dataf);
    fread(golden, sizeof(golden), 1, goldenf);

    printf("Test - SHA-3-512 FIPS 202 length=56 bytes...");
    sha3(data, 56, hash_result, sizeof(hash_result));
    if (!sec_compare(hash_result, golden, 0x40))
        printf("pass\n");
    else
        printf("fail\n");

    fclose(dataf);
    fclose(goldenf);

    dataf = fopen("./pattern/vector1_112.bin","rb");
    goldenf = fopen("./pattern/vector1_112_512_golden.bin","rb");

    fread(data, 112, 1, dataf);
    fread(golden, sizeof(golden), 1, goldenf);

    printf("Test - SHA-3-512 FIPS 202 length=112 bytes...");
    sha3(data, 112, hash_result, sizeof(hash_result));
    if (!sec_compare(hash_result, golden, 0x40))
        printf("pass\n");
    else
        printf("fail\n");


    fclose(dataf);
    fclose(goldenf);
}

int main(void)
{
    sha3_224_test();
    sha3_256_test();
    sha3_384_test();
    sha3_512_test();

    return 0;
}
