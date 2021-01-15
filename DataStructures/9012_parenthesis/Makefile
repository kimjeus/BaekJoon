parenthesis_exe : parenthesis.o main.o
	gcc -o parenthesis_exe parenthesis.o main.o

parenthesis.o : parenthesis.c
	gcc -c -o parenthesis.o parenthesis.c

main.o : main.c
	gcc -c -o main.o main.c

clean :
	rm *.o parenthesis_exe
