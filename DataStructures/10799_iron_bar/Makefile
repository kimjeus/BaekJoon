iron_bar_exe : iron_bar.o main.o
	gcc -o iron_bar_exe iron_bar.o main.o

iron_bar.o : iron_bar.c
	gcc -c -o iron_bar.o iron_bar.c

main.o : main.c
	gcc -c -o main.o main.c

clean :
	rm *.o iron_bar_exe
