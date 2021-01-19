CC = gcc
CFLAGS = -W -Wall
TARGET = tree_diameter_exe
OBJS = tree_diameter.o main.o

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^
				
tree_diameter.o : tree_diameter.c tree_diameter.h
	$(CC) $(CFLAGS) -c -o $@ tree_diameter.c

main.o : main.c tree_diameter.h
	$(CC) $(CFLAGS) -c -o $@ main.c

clean :
	rm *.o $(TARGET)
