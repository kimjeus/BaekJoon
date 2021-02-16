CC = gcc
CFLAGS = -W -Wall
TARGET = string_set_exe
OBJS = string_set.o main.o

all = $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

string_set.o : string_set.c string_set.h
	$(CC) $(CFLAGS) -c -o $@ string_set.c

main.o : main.c string_set.h
	$(CC) $(CFLAGS) -c -o $@ main.c

clean :
	rm *.o $(TARGET)
