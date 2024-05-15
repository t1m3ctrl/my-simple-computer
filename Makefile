all: 
	$(MAKE) -C mySimpleComputer
	$(MAKE) -C myTerm
	$(MAKE) -C myBigChars
	$(MAKE) -C myReadKey
	$(MAKE) -C console
	
clean:
	$(MAKE) -C console clean
	$(MAKE) -C myTerm clean
	$(MAKE) -C mySimpleComputer clean
	$(MAKE) -C myBigChars clean
	$(MAKE) -C myReadKey clean

	