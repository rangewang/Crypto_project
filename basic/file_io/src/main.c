#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

void print_arr(uint8_t *arr, uint16_t size)
{
    uint16_t i;

    for (i = 0 ; i < size ; i++) {
        if (!(i % 16))
            printf("\n");
        printf("%02x ", arr[i]);
    }

}

int main(void)
{
    FILE *inf, *outf;
    uint8_t buf[0x10];
    uint16_t len;

    inf = fopen("./pattern/test_read.bin","rb");
    outf = fopen("./pattern/test_write.bin","wb");

    while (1) {
         len = fread(buf, sizeof(buf), 1, inf);
         if (len == 0)
            break;
         print_arr(buf, sizeof(buf));
         fwrite(buf, sizeof(buf), 1, outf);
         //printf("==> %d <==", len);
    }

    printf("\n");
    fclose(inf);
    fclose(outf);

    return 0;
}
