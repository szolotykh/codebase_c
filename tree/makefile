all: treetest.o tree.o treerand.o
	gcc -g treetest.o tree.o -o treetest
	gcc -g treerand.o tree.o -o treerand

tree.o: tree.c tree.h
	gcc -g -c tree.c

treetest.o: treetest.c tree.h
	gcc -g -c treetest.c

treerand.o: treerand.c tree.h
	gcc -g -c treerand.c

clean:
	rm -f *.o
	rm -f treetest
	rm -f treerand

docs:
	doxygen
