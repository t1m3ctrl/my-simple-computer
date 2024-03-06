all: 
	$(MAKE) -C mySimpleComputer
	$(MAKE) -C myTerm
	$(MAKE) -C console
	
clean:
	$(MAKE) -C console clean
	$(MAKE) -C myTerm clean
	$(MAKE) -C mySimpleComputer clean