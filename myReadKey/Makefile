CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11 -I../include
SRCDIR = .
OBJ_DIR = ../console/obj
LIBDIR = ../console/obj

SRCS := $(wildcard $(SRCDIR)/*.c)
OBJS := $(patsubst $(SRCDIR)/%,$(OBJ_DIR)/%,$(SRCS:.c=.o))

LIB_FILE = $(LIBDIR)/libRK.a

.PHONY: all clean

all: $(LIB_FILE)

$(LIB_FILE): $(OBJS)
	ar rcs $@ $^

$(OBJ_DIR)/%.o: $(SRCDIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I. -I../include -I../myReadKey -c -o $@ $<

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR) $(LIB_FILE) *.bin *.o