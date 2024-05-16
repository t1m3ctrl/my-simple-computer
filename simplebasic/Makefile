FLAGS = -pedantic -ansi -lm -std=c++11
OUT_FOLDER = ./bin
DEP_FILES = $(shell find ./ -maxdepth 1 -iname '*.cpp')
OBJ_FILES = $(patsubst %.cpp, $(OUT_FOLDER)/%.o, $(DEP_FILES))

.PHONY: prepare
all: build

prepare:
	mkdir -p $(OUT_FOLDER)

$(OUT_FOLDER)/%.o: %.cpp
	g++ $(FLAGS) -I. -c $< -o $@

build: prepare $(OBJ_FILES)
	g++ $(FLAGS) -I. $(OBJ_FILES) -o sbt

clean:
	rm -rf $(OUT_FOLDER) sbt
