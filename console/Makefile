CC=gcc
CFLAGS= -Wall -Werror -Wextra
LDFLAGS=
OBJ_DIR=.
SOURCES=$(shell find ./* -name '*.c')
LIB=$(shell find ../mySimpleComputer -name '*.a') | $(shell find ../myTerm -name '*.a') 

OBJECTS=$(SOURCES:./%.c=$(OBJ_DIR)/%.o)
EXECUTABLE=test

all: $(EXECUTABLE) $(OBJECTS)

$(EXECUTABLE): test.o
	gcc test.o -L../mySimpleComputer -lSC -L../myTerm -lMT  -o test

test.o: test.c lib
	gcc test.c -c -o test.o

lib:
	$(MAKE) -C ../mySimpleComputer
	$(MAKE) -C ../myTerm	

clean:
	find $(OBJ_DIR) -name '*.o' -exec $(RM) '{}' \;
	find $(OBJ_DIR) -name '*.d' -exec $(RM) '{}' \;
	find $(OBJ_DIR) -name 'test' -exec $(RM) '{}' \;
	$(MAKE) -C ../mySimpleComputer clean
# $(RM) $(EXECUTABLE)

.PHONY: all clean lib