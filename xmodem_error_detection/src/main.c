#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

static int cal_checksum(uint8_t *ptx, int size)
{
    int i = 0, tmp = 0;

    for (i = 0 ; i < 128 ; i++)
        tmp += ptx[i];
    tmp &= 255;

    return tmp;
}

static int cal_crc(char *ptr, int count)
{
    int crc, i;

    crc = 0;
    while (--count >= 0) {
        crc = crc ^ (int)*ptr++ << 8;
        for (i = 0; i < 8; ++i)
            if (crc & 0x8000)
                crc = crc << 1 ^ 0x1021;
            else
                crc = crc << 1;
    }

    return (crc & 0xFFFF);
}

int main(void)
{
    FILE *inf, *outf;
    uint8_t buf[128];
    uint8_t buf_1k[1024];
    uint32_t i, len, size;

    inf = fopen("./pattern/test.bin","rb");

    fseek(inf, 0, SEEK_END);
    size = ftell(inf);

    printf("\n**file: test.bin, file size: %d bytes\n", size);

    printf("--------------------------\n");
    printf("XMODEM checksum\n");
    printf("--------------------------\n");
    if( size % 128 )
        printf("Note: file size is not multiple of 128 bytes\n");
    i = 0;
    fseek(inf, 0, SEEK_SET);
    while (1) {
        len = fread(buf, sizeof(buf), 1, inf);
        if (len == 0)
            break;
        printf("block[%02d]: %02x\n", i, cal_checksum(buf, 128));
        i++;
    }

    printf("--------------------------\n");
    printf("XMODEM CRC\n");
    printf("--------------------------\n");
    if( size % 128 )
        printf("Note: file size is not multiple of 128 bytes\n");
    i = 0;
    fseek(inf, 0, SEEK_SET);
    while (1) {
        len = fread(buf, sizeof(buf), 1, inf);
        if (len == 0)
            break;
        printf("block[%02d]: %04x\n", i, cal_crc(buf, 128));
        i++;
    }

    fclose(inf);
    inf = fopen("./pattern/test_1k.bin","rb");

    fseek(inf, 0, SEEK_END);
    size = ftell(inf);

    printf("\n**file: test_1k.bin, file size: %d bytes\n", size);

    printf("--------------------------\n");
    printf("XMODEM 1K\n");
    printf("--------------------------\n");
    if( size % 1024 )
        printf("Note: file size is not multiple of 1024 bytes\n");
    i = 0;
    fseek(inf, 0, SEEK_SET);
    while (1) {
        len = fread(buf_1k, sizeof(buf_1k), 1, inf);
        if (len == 0)
            break;
        printf("block[%02d]: %04x\n", i, cal_crc(buf_1k, 1024));
        i++;
    }

    printf("\n");
    fclose(inf);

    return 0;
}
