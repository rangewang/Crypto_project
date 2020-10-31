MBEDTLS_LIB	= ./library

CC			= gcc
LD			= gcc
OUT_PATH	= ./output/
CFLAGS		?=	-I./include -I$(MBEDTLS_LIB)
OBJS      	= 	./src/main.c \
				$(MBEDTLS_LIB)/sha3.c

ex_out.elf :
	if [ ! -d "$(OUT_PATH)" ]; then	mkdir output; fi
	$(CC) $(CFLAGS) $(OBJS) -o $(OUT_PATH)$@ $^

clean:
	rm -rf output