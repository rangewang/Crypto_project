CC			= gcc
LD			= gcc
CFLAGS		?=	-I./include
OBJS      	= ./src/main.c
OUT_PATH	= ./build/

ex_out.elf :
	if [ ! -d "$(OUT_PATH)" ]; then	mkdir build; fi
	$(CC) $(CFLAGS) $(OBJS) -o $(OUT_PATH)$@ $^

clean:
	rm -rf build