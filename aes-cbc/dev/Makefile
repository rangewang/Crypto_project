MBEDTLS_LIB	= ../library

CC			= gcc
LD			= gcc
OUT_PATH	= ./output/
CFLAGS		?=	-I./include -I../include -I../include/mbedtls
OBJS      	= 	./src/main.c ./src/aes_hal.c \
				$(MBEDTLS_LIB)/aes.c \
				$(MBEDTLS_LIB)/aesni.c \
				$(MBEDTLS_LIB)/platform_util.c

ex_out.elf :
	if [ ! -d "$(OUT_PATH)" ]; then	mkdir output; fi
	$(CC) $(CFLAGS) $(OBJS) -o $(OUT_PATH)$@ $^

clean:
	rm -rf output