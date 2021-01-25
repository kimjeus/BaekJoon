CC = gcc
CFLAGS = -W -Wall
TARGET = bridge_building_exe
OBJS = bridge_building.o main.o

all = $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

bridge_building.o : bridge_building.c bridge_building.h
	$(CC) $(CFLAGS) -c -o $@ bridge_building.c

main.o : main.c bridge_building.h
	$(CC) $(CFLAGS) -c -o $@ main.c

clean :
	rm *.o $(TARGET)
