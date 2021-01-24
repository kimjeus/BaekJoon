CC = gcc
CFLAGS = -W -Wall
TARGET = emoticon_exe
OBJS = emoticon.o main.o

all = $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ 

emoticon.o : emoticon.c emoticon.h
	$(CC) $(CFLAGS) -c -o $@ emoticon.c

main.o : main.c emoticon.h
	$(CC) $(CFLAGS) -c -o $@ main.c

clean :
	rm *.o $(TARGET)
