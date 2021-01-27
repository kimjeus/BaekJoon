CC = gcc
CFLAGS = -W -Wall
TARGET = teaching_exe
OBJS = teaching.o main.o

all = $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

teaching.o : teaching.c teaching.h
	$(CC) $(CFLAGS) -c -o $@ teaching.c

main.o : main.c teaching.h
	$(CC) $(CFLAGS) -c -o $@ main.c

clean :
	rm *.o $(TARGET)
