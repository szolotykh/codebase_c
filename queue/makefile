queuetest: queuetest.o queue.o
	gcc -g queuetest.o queue.o -o queuetest

queue.o: queue.c queue.h
	gcc -g -c queue.c

queuetest.o: queuetest.c queue.h
	gcc -g -c queuetest.c

clean:
	rm -f *.o
	rm -f queuetest

docs:
	doxygen
