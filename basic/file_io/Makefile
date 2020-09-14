CC			= gcc
LD			= gcc
CFLAGS		?=	-I./include
OBJS      	= ./src/main.c
OUT_PATH	= ./output/

ex_out.elf :
	if [ ! -d "$(OUT_PATH)" ]; then	mkdir output; fi
	$(CC) $(CFLAGS) $(OBJS) -o $(OUT_PATH)$@ $^

clean:
	rm -rf output
