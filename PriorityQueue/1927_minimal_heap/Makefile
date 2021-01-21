CC = gcc
CFLAGS = -W -Wall
TARGET = minimal_heap_exe
OBJS = minimal_heap.o main.o

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

minimal_heap.o : minimal_heap.c minimal_heap.h
	$(CC) $(CFLAGS) -c -o $@ minimal_heap.c

main.o : main.c minimal_heap.h
	$(CC) $(CFLAGS) -c -o $@ main.c

clean :
	rm *.o $(TARGET)
