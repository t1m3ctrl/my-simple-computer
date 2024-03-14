CC=gcc
CFLAGS= -Wall -Werror -Wextra
LDFLAGS=
OBJ_DIR=.
SOURCES=$(shell find ./* -name '*.c')

OBJECTS=$(SOURCES:./%.c=$(OBJ_DIR)/%.o)
EXECUTABLE=$(OBJ_DIR)/libMT.a

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	ar rcs $@ $^
	ranlib $(EXECUTABLE)
# $(MAKE) -C ./ clean

$(OBJ_DIR)/%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	find $(OBJ_DIR) -name '*.o' -exec $(RM) '{}' \;
	find $(OBJ_DIR) -name '*.d' -exec $(RM) '{}' \;
	find $(OBJ_DIR) -name '*.a' -exec $(RM) '{}' \;
# $(RM) $(EXECUTABLE)

.PHONY: all clean
