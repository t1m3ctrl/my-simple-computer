CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11 
SRCDIR = .
OBJ_DIR = ./obj
LIBDIR = .

SRCS := $(wildcard $(SRCDIR)/*.c)
OBJS := $(patsubst $(SRCDIR)/%,$(OBJ_DIR)/%,$(SRCS:.c=.o))

LIB_FILE = $(LIBDIR)/libMyBigChars.a

.PHONY: all clean

all: $(LIB_FILE)

$(LIB_FILE): $(OBJS)
	ar rcs $@ $^

$(OBJ_DIR)/%.o: $(SRCDIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I. -I../include -I../myTerm -c -o $@ $<

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

run: all $(SRCDIR) $(SRCDIR)console.out

$(SRCDIR)console.out: $(OBJ_DIR)/main.o $(LIB_FILE)
	$(CC) $(CFLAGS) -o $@ $^
$(OBJ_DIR)main.o: main.c 
	$(CC) -c $(CFLAGS) -o $@ $^

clean:
	rm -rf $(OBJ_DIR) $(LIB_FILE) *.bin *.o