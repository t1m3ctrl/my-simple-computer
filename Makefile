all: 
	$(MAKE) -C mySimpleComputer
	$(MAKE) -C console
	
clean:
	$(MAKE) -C console clean
	$(MAKE) -C mySimpleComputer clean