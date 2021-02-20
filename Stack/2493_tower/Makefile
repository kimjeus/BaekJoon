CC = gcc
CFLAGS = -W -Wall
TARGET = tower_exe
OBJS = tower.o main.o

all = $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

tower_.o : tower.c tower.h
	$(CC) $(CFLAGS) -c -o $@ tower.c

main.o : main.c tower.h
	$(CC) $(CFLAGS) -c -o $@ main.c

clean :
	rm *.o $(TARGET)
