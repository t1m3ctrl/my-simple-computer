all: main.cpp
	g++ main.cpp -o sat

test: all main.a
	./main.a test.asm 

clean:
	rm -rf sat