CC = gcc
CFLAGS = -W -Wall
TARGET = lets_go_travel_exe
OBJS = lets_go_travel.o main.o

all = $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

lets_go_travel.o : lets_go_travel.c lets_go_travel.h
	$(CC) $(CFLAGS) -c -o $@ lets_go_travel.c

main.o : main.c lets_go_travel.h
	$(CC) $(CFLAGS) -c -o $@ main.c

clean :
	rm *.o $(TARGET)
