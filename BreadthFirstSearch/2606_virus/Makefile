virus_exe : virus.o main.o
	gcc -o virus_exe virus.o main.o

virus.o : virus.c
	gcc -c -o virus.o virus.c

main.o : main.c
	gcc -c -o main.o main.c

clean :
	rm *.o virus_exe
