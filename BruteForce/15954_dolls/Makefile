CC = gcc
CFLAGS = -W -Wall
TARGET = dolls_exe
OBJS = dolls.o main.o

all = $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ -lm

dolls.o : dolls.c dolls.h
	$(CC) $(CFLAGS) -c -o $@ dolls.c

main.o : main.c dolls.h
	$(CC) $(CFLAGS) -c -o $@ main.c

clean :
	rm *.o $(TARGET)
