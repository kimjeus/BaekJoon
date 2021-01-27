CC = gcc
CFLAGS = -W -Wall
TARGET = editor_exe
OBJS = editor.o main.o

all = $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

editor.o : editor.c editor.h
	$(CC) $(CFLAGS) -c -o $@ editor.c

main.o : main.c editor.h
	$(CC) $(CFLAGS) -c -o $@ main.c

clean :
	rm *.o $(TARGET)
