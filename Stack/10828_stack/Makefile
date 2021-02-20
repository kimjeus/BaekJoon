stack_exe : stack.o main.o
	gcc -o stack_exe stack.o main.o

stack.o : stack.c
	gcc -c -o stack.o stack.c

main.o : main.c
	gcc -c -o main.o main.c

clean :
	rm *.o stack_exe
