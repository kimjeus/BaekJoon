CC = gcc
CFLAGS = -W -Wall
TARGET = zero_exe
OBJS = zero.o main.o

all = $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

zero.o : zero.c zero.h
	$(CC) $(CFLAGS) -c -o $@ zero.c

main.o : main.c zero.h
	$(CC) $(CFLAGS) -c -o $@ main.c

clean :
	rm *.o $(TARGET)
