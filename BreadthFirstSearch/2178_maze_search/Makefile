maze_search_exe : maze_search.o main.o
	gcc -o maze_search_exe maze_search.o main.o

maze_search.o : maze_search.c
	gcc -c -o maze_search.o maze_search.c

main.o : main.c
	gcc -c -o main.o main.c

clean :
	rm *.o maze_search_exe
