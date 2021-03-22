program: program.o weatherstats.o
	gcc -std=c11 -Wall -fmax-errors=10 -Wextra program.o weatherstats.o -o program

program.o: program.c weatherstats.h
	gcc -std=c11 -Wall -fmax-errors=10 -Wextra -c program.c -o program.o

weatherstats.o: weatherstats.c
	gcc -std=c11 -Wall -fmax-errors=10 -Wextra -c weatherstats.c -o weatherstats.o
