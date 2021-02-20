CC = gcc
CFLAGS = -W -Wall
TARGET = greedy_panda_exe
OBJS = greedy_panda.o main.o

all = $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

greedy_panda.o : greedy_panda.c greedy_panda.h
	$(CC) $(CFLAGS) -c -o $@ greedy_panda.c
	
main.o : main.c greedy_panda.h
	$(CC) $(CFLAGS) -c -o $@ main.c

clean :
	rm *.o $(TARGET)
