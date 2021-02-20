CC = gcc
CFLAGS = -W -Wall
TARGET = balanced_world_exe
OBJS = balanced_world.o main.o

all = $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

balanced_world.o : balanced_world.c balanced_world.h
	$(CC) $(CFLAGS) -c -o $@ balanced_world.c

main.o : main.c balanced_world.h
	$(CC) $(CFLAGS) -c -o $@ main.c

clean :
	rm *.o $(TARGET)
