CC = gcc
CFLAGS = -W -Wall
TARGET = safe_area_exe
OBJS = safe_area.o main.o

all = $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

safe_area.o : safe_area.c safe_area.h
	$(CC) $(CFLAGS) -c -o $@ safe_area.c

main.o : main.c safe_area.h
	$(CC) $(CFLAGS) -c -o $@ main.c

clean :
	rm *.o $(TARGET)
