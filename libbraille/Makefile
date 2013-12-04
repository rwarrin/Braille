CC = gcc
CFLAGS = -std=c11 -ggdb -Wall -Werror -Wextra -pedantic -O0

INC_PATH = ./include
SRC_PATH = ./src
OUT_DIR = ./lib

HDRS = $(INC_PATH)/texttobraille.h $(INC_PATH)/brailletotext.h $(INC_PATH)/braillemap.h
SRCS = $(SRC_PATH)/texttobraille.c $(SRC_PATH)/brailletotext.c

B2T: $(INC_PATH)/braillemap.h $(INC_PATH)/brailletotext.h
	$(CC) $(CFLAGS) -I$(INC_PATH) $(SRC_PATH)/brailletotext.c -c -o $(OUT_DIR)/brailletotext.o

T2B: $(INC_PATH)/braillemap.h $(INC_PATH)/texttobraille.h
	$(CC) $(CFLAGS) -I$(INC_PATH) $(SRC_PATH)/texttobraille.c -c -o $(OUT_DIR)/texttobraille.o

all: B2T T2B

clean:
	rm -f $(OUT_DIR)/*.o
