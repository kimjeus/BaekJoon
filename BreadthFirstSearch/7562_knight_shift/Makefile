CC = gcc
CFLAGS = -W -Wall
TARGET = knight_shift_exe
OBJS = knight_shift.o main.o

all = $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

knight_shift.o : knight_shift.c knight_shift.h
	$(CC) $(CFLAGS) -c -o $@ knight_shift.c

main.o : main.c knight_shift.h
	$(CC) $(CFLAGS) -c -o $@ main.c

clean :
	rm *.o $(TARGET)
