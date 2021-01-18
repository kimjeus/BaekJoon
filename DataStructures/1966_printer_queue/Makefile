CC = gcc
CFLAGS = -W -Wall
TARGET = printer_queue_exe
OBJS = printer_queue.o main.o

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

printer_queue.o : printer_queue.h printer_queue.c
	$(CC) $(CFLAGS) -c -o $@ printer_queue.c

main.o : printer_queue.h main.c
	$(CC) $(CFLAGS) -c -o $@ main.c

clean :
	rm *.o $(TARGET)
