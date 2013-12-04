CC = gcc

CFLAGS = -std=c11 -ggdb -Wall -Werror -Wextra -pedantic -O0

LIBBRAILLE_INC = -I./libbraille/include
LIBBRAILLE_LIB = -L./libbraille/lib
LIBS = -lbraille

OUT_PATH = ./bin/

HDRS = 
SRCS = main.c

APP = braille

$(APP): $(OBJS) $(HDRS) $(SRCS) Makefile
	$(CC) $(CFLAGS) -o $(OUT_PATH)$@ $(LIBBRAILLE_INC) $(SRCS) $(LIBBRAILLE_LIB) $(LIBS)

clean:
	rm -f $(APP) core
