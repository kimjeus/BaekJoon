CC = gcc
CFLAGS = -W -Wall
TARGET = card2_exe
OBJS = card2.o main.o

all = $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

card2.o : card2.c card2.h
	$(CC) $(CFLAGS) -c -o $@ card2.c

main.o : main.c card2.h
	$(CC) $(CFLAGS) -c -o $@ main.c

clean :
	rm *.o $(TARGET)
