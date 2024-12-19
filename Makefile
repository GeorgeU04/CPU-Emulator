a.out: main.o Instructions.o CPU.o Arithmetic.o Misc.o Branching.o Load_Store.o Logical.o Stack.o Compare.o
	gcc main.o Instructions.o CPU.o Arithmetic.o Misc.o Branching.o Load_Store.o Logical.o Stack.o Compare.o

main.o: main.c
	gcc -c main.c

Instructions.o: Instructions.h Instructions.c 
	gcc -c Instructions.c 

CPU.o: CPU.h CPU.c 
	gcc -c CPU.c 

Arithmetic.o: Arithmetic.h Arithmetic.c
	gcc -c Arithmetic.c

Misc.o: Misc.h Misc.c
	gcc -c Misc.c 

Branching.o: Branching.h Branching.c
	gcc -c Branching.c

Load_Store.o: Load_Store.h Load_Store.c
	gcc -c Load_Store.c

Logical.o: Logical.h Logical.c 
	gcc -c Logical.c

Stack.o: Stack.h Stack.c 
	gcc -c Stack.c

Compare.o: Compare.h Compare.c
	gcc -c Compare.c

clean:
	rm *.o a.out
