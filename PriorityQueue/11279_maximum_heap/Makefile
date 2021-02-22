CC = gcc
CFLAGS = -W -Wall
TARGET = maximum_heap_exe
OBJS = maximum_heap.o main.o

all = $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

maximum_heap.o : maximum_heap.c maximum_heap.h
	$(CC) $(CFLAGS) -c -o $@ maximum_heap.c

main.o : main.c maximum_heap.h
	$(CC) $(CFLAGS) -c -o $@ main.c

clean :
	rm *.o $(TARGET)
