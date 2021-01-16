stack_sequence_exe : stack_sequence.o main.o
	gcc -o stack_sequence_exe stack_sequence.o main.o

stack_sequence.o : stack_sequence.c
	gcc -c -o stack_sequence.o stack_sequence.c

main.o : main.c
	gcc -c -o main.o main.c

clean :
	rm *.o stack_sequence_exe
