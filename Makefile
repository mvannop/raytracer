
all:
	@g++ -std=c++11 -MM *.cc > makefile.deps
	$(MAKE) -f makefile.base

clean:
	$(MAKE) -f makefile.base clean
