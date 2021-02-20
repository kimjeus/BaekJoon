CC = gcc
CFLAGS = -W -Wall
TARGET = queue2_exe
OBJS = queue2.o main.o

all = $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

queue2.o : queue2.c queue2.h
	$(CC) $(CFLAGS) -c -o $@ queue2.c

main.o : main.c queue2.h
	$(CC) $(CFLAGS) -c -o $@ main.c

clean :
	rm *.o $(TARGET)
