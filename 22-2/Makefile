main: main.o stack.o maze.o
	gcc main.o stack.o maze.o -o main

main.o stack.o maze.o: main.h
main.o maze.o: maze.h
main.o stack.o: stack.h

clean:
	-rm main *.o
.PHONY: clean

