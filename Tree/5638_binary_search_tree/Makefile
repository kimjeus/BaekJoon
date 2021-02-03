CC = gcc
CFLAGS = -W -Wall
TARGET = binary_search_tree_exe
OBJS = binary_search_tree.o main.o

all = $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

binary_search_tree.o : binary_search_tree.c binary_search_tree.h
	$(CC) $(CFLAGS) -c -o $@ binary_search_tree.c

main.o : main.c binary_search_tree.h
	$(CC) $(CFLAGS) -c -o $@ main.c

clean :
	rm *.o $(TARGET)
