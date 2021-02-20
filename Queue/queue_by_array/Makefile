CC = gcc
CFLAGS = -W -Wall
TARGET = queue_by_array_exe
OBJS = queue_by_array.o main.o

all = $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

queue_by_array.o : queue_by_array.c queue_by_array.h
	$(CC) $(CFLAGS) -c -o $@ queue_by_array.c

main.o : main.c queue_by_array.h
	$(CC) $(CFLAGS) -c -o $@ main.c

clean :
	rm *.o $(TARGET)
