CC = gcc
CFLAGS = -W -Wall
TARGET = shortest_path_exe
OBJS = shortest_path.o main.o

all = $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

shortest_path.o : shortest_path.c shortest_path.h
	$(CC) $(CFLAGS) -c -o $@ shortest_path.c

main.o : main.c shortest_path.h
	$(CC) $(CFLAGS) -c -o $@ main.c

clean :
	rm *.o $(TARGET)
