CC = gcc
CFLAGS = -W -Wall
TARGET = escape_exe
OBJS = escape.o main.o

all = $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

escape.o : escape.c escape.h
	$(CC) $(CFLAGS) -c -o $@ escape.c

main.o : main.c escape.h
	$(CC) $(CFLAGS) -c -o $@ main.c

clean :
	rm *.o $(TARGET)
