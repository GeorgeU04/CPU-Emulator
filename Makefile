a.out: main.o Instructions.o CPU.o 
	gcc main.o Instructions.o CPU.o

main.o: main.c
	gcc -c main.c

Instructions.o: Instructions.h Instructions.c 
	gcc -c Instructions.c 

CPU.o: CPU.h CPU.c 
	gcc -c CPU.c 

clean:
	rm *.o a.out
