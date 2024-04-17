CC=gcc
CFLAGS= -Wall -Werror -Wextra
LDFLAGS=
OBJ_DIR=.
SOURCES=$(shell find ./* -name '*.c')
LIB=$(shell find ../mySimpleComputer -name '*.a') | $(shell find ../myTerm -name '*.a') | $(shell find ../myBigChars -name '*.a')

OBJECTS=$(SOURCES:./%.c=$(OBJ_DIR)/%.o)
EXECUTABLE=console
EXECUTABLE2=font

all: $(EXECUTABLE) $(EXECUTABLE2) $(OBJECTS)

$(EXECUTABLE2): font.o
	gcc $(CFLAGS) font.o -L../myBigChars -lBC -L../mySimpleComputer -lSC -L../myTerm -lMT -o $(EXECUTABLE2)

font.o: font.c lib 
	gcc $(CFLAGS) font.c -c -o font.o 

$(EXECUTABLE): console.o
	gcc $(CFLAGS) console.o -L../myBigChars -lBC -L../mySimpleComputer -lSC -L../myTerm -lMT  -o $(EXECUTABLE)

console.o: console.c lib
	gcc $(CFLAGS) console.c -c -o console.o

lib:
	$(MAKE) -C ../mySimpleComputer
	$(MAKE) -C ../myTerm
	$(MAKE) -C ../myBigChars

clean:
	find $(OBJ_DIR) -name '*.o' -exec $(RM) '{}' \;
	find $(OBJ_DIR) -name '*.d' -exec $(RM) '{}' \;
	find $(OBJ_DIR) -name 'console' -exec $(RM) '{}' \;
	find $(OBJ_DIR) -name 'font' -exec $(RM) '{}' \;
	$(MAKE) -C ../mySimpleComputer clean
# $(RM) $(EXECUTABLE)

.PHONY: all clean lib