mycomp: mycomp.o textTransition.o complex.o
	gcc -g -ansi mycomp.o textTransition.o complex.o -o mycomp -lm

mycomp.o: mycomp.c complex.h
	gcc -c -Wall -ansi -pedantic mycomp.c -o mycomp.o

textTransition.o: textTransition.c complex.o complex.h 
	gcc -c -Wall -ansi -pedantic textTransition.c -o textTransition.o

complex.o: complex.c complex.h
	gcc -c -Wall -ansi -pedantic complex.c -o complex.o -lm

