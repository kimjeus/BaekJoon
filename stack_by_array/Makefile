CC = gcc
CFLAGS = -W -Wall
TARGET = stack_by_array_exe
OBJS = stack_by_array.o main.o

all = $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

stack_by_array.o : stack_by_array.c stack_by_array.h
	$(CC) $(CFLAGS) -c -o $@ stack_by_array.c

main.o : main.c stack_by_array.h
	$(CC) $(CFLAGS) -c -o $@ main.c

clean :
	rm *.o $(TARGET)
