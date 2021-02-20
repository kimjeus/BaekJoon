josephus_exe : josephus.o main.o
	gcc -o josephus_exe josephus.o main.o

josephus.o : josephus.c
	gcc -c -o josephus.o josephus.c

main.o : main.c
	gcc -c -o main.o main.c

clean :
	rm *.o josephus_exe
