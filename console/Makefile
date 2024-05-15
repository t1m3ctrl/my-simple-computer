build:
	gcc main.c -o console.out -I../include -I../mySimpleComputer -I../myBigChars -I../myTerm -I../myReadKey -L../mySimpleComputer -lMySimpleComputer -L../myTerm -lMyTerm -L../myBigChars -lMyBigChars -L../myReadKey -lMyReadKey

run: build
	./console.out

clean: 
	rm -rf console.out