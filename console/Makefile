CC = gcc
CFLAGS =  -Wall -Werror -Wextra -std=c11 -I../myReadKey -I../mySimpleComputer
SRCDIR = .
OBJ_DIR = ../console/obj
LIBDIR = ../console/obj

#SRCS := $(wildcard $(SRCDIR)/*.c)
SRCS := $(filter-out $(SRCDIR)/main.c, $(wildcard $(SRCDIR)/*.c))
OBJS := $(patsubst $(SRCDIR)/%,$(OBJ_DIR)/%,$(SRCS:.c=.o))

OBJSLINK := $(wildcard $(OBJ_DIR)/*.o)

LIB_FILE = $(LIBDIR)/libConsole.a

.PHONY: all clean

build: $(LIB_FILE) console.out

console.out:
	gcc -c main.c -o ../console/main.o -I../include -I../mySimpleComputer -I../myBigChars -I../myTerm -I../myReadKey -I../console
	gcc main.o $(OBJSLINK) -o console.out -L../console/obj -lMySimpleComputer -lMyTerm -lMyBigChars -lMyReadKey -lConsole

$(LIB_FILE): $(OBJS)
	ar rcs $@ $^

$(OBJ_DIR)/%.o: $(SRCDIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I../include -c -o $@ $<

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR) $(LIB_FILE) *.bin *.o *.out

