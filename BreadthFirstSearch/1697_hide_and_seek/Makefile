CC = gcc
CFLAGS = -W -Wall
TARGET = hide_and_seek_exe
OBJS = hide_and_seek.o main.o

all = $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

hide_and_seek.o : hide_and_seek.c hide_and_seek.h
	$(CC) $(CFLAGS) -c -o $@ hide_and_seek.c

main.o : main.c hide_and_seek.h
	$(CC) $(CFLAGS) -c -o $@ main.c

clean :
	rm *.o $(TARGET)
