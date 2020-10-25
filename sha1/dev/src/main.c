#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "sha1_api.h"
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

int sha1_test(void)
{
    FILE *dataf, *goldenf;
    uint8_t data[0x100], golden[20], hash_result[20];

    dataf = fopen("./pattern/vector1_0.bin","rb");
    goldenf = fopen("./pattern/vector1_0_golden.bin","rb");

    fread(data, 0, 1, dataf);
    fread(golden, sizeof(golden), 1, goldenf);

    printf("Test - SHA-1 FIPS 180-4 length=0 bytes...");
    hal_sha1(data, 0, hash_result);
    if (!sec_compare(hash_result, golden, 20))
        printf("pass\n");
    else
        printf("fail\n");

    fclose(dataf);
    fclose(goldenf);

    dataf = fopen("./pattern/vector1_3.bin","rb");
    goldenf = fopen("./pattern/vector1_3_golden.bin","rb");

    fread(data, 3, 1, dataf);
    fread(golden, sizeof(golden), 1, goldenf);

    printf("Test - SHA-1 FIPS 180-4 length=3 bytes...");
    hal_sha1(data, 3, hash_result);
    if (!sec_compare(hash_result, golden, 20))
        printf("pass\n");
    else
        printf("fail\n");

    fclose(dataf);
    fclose(goldenf);

    dataf = fopen("./pattern/vector1_56.bin","rb");
    goldenf = fopen("./pattern/vector1_56_golden.bin","rb");

    fread(data, 56, 1, dataf);
    fread(golden, sizeof(golden), 1, goldenf);

    printf("Test - SHA-1 FIPS 180-4 length=56 bytes...");
    hal_sha1(data, 56, hash_result);
    if (!sec_compare(hash_result, golden, 20))
        printf("pass\n");
    else
        printf("fail\n");

    fclose(dataf);
    fclose(goldenf);

    dataf = fopen("./pattern/vector1_112.bin","rb");
    goldenf = fopen("./pattern/vector1_112_golden.bin","rb");

    fread(data, 112, 1, dataf);
    fread(golden, sizeof(golden), 1, goldenf);

    printf("Test - SHA-1 FIPS 180-4 length=112 bytes...");
    hal_sha1(data, 112, hash_result);
    if (!sec_compare(hash_result, golden, 20))
        printf("pass\n");
    else
        printf("fail\n");

    fclose(dataf);
    fclose(goldenf);

}


int main(void)
{
    sha1_test();

    return 0;
}
