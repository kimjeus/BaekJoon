CC = gcc
CFLAGS = -W -Wall
TARGET = snake_exe
OBJS = snake.o main.o

all = $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

snake.o : snake.c snake.h
	$(CC) $(CFLAGS) -c -o $@ snake.c

main.o : main.c snake.h
	$(CC) $(CFLAGS) -c -o $@ main.c

clean :
	rm *.o $(TARGET)
