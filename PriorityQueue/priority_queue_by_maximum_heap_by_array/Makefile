CC = gcc
CFLAGS = -W -Wall
TARGET = priority_queue_exe
OBJS = priority_queue.o main.o

all = $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

priority_queue.o : priority_queue.c priority_queue.h
	$(CC) $(CFLAGS) -c -o $@ priority_queue.c

main.o : main.c priority_queue.h
	$(CC) $(CFLAGS) -c -o $@ main.c

clean :
	rm *.o $(TARGET)
