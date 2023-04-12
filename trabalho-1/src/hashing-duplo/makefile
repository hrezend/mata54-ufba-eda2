all: clean main
main: main.o fileManager.o
	gcc -o main main.o fileManager.o
main.o: main.c fileManager.h
	gcc -o main.o -c main.c -Wall -Wextra -Werror -Wpedantic -Wno-unused-result
fileManager.o: fileManager.c
	gcc -o fileManager.o -c fileManager.c -Wall -Wextra  -Wpedantic -Wno-unused-result
clean:
	rm -rf *.o
	rm -rf *.dat
mrproper: clean