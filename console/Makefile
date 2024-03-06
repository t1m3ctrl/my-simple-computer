CC=gcc
CFLAGS= -Wall -Werror -Wextra
LDFLAGS=
OBJ_DIR=.
SOURCES=$(shell find ./* -name '*.c')
LIB=$(shell find ../mySimpleComputer -name '*.a')

OBJECTS=$(SOURCES:./%.c=$(OBJ_DIR)/%.o)
EXECUTABLE=pr01

all: $(EXECUTABLE) $(OBJECTS)

$(EXECUTABLE): test.o
	gcc test.o -L../mySimpleComputer -lSC -I../mySimpleComputer -o pr01

test.o: test.c lib
	gcc test.c -c -o test.o

lib:
	$(MAKE) -C ../mySimpleComputer

clean:
	find $(OBJ_DIR) -name '*.o' -exec $(RM) '{}' \;
	find $(OBJ_DIR) -name '*.d' -exec $(RM) '{}' \;
	find $(OBJ_DIR) -name 'pr01' -exec $(RM) '{}' \;
	$(MAKE) -C ../mySimpleComputer clean
# $(RM) $(EXECUTABLE)

.PHONY: all clean lib