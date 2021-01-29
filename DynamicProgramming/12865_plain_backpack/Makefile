CC = gcc
CFLAGS = -W -Wall
TARGET = plain_backpack_exe
OBJS = plain_backpack.o main.o

all = $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

plain_backpack.o : plain_backpack.c plain_backpack.h
	$(CC) $(CFLAGS) -c -o $@ plain_backpack.c

main.o : main.c plain_backpack.h
	$(CC) $(CFLAGS) -c -o $@ main.c

clean :
	rm *.o $(TARGET)
