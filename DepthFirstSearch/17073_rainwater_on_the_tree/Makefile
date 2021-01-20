CC = gcc
CFLAGS = -W -Wall
TARGET = rainwater_on_the_tree_exe
OBJS = rainwater_on_the_tree.o main.o

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ -lm

rainwater_on_the_tree.o : rainwater_on_the_tree.c rainwater_on_the_tree.h
	$(CC) $(CFLAGS) -c -o $@ rainwater_on_the_tree.c

main.o : main.c rainwater_on_the_tree.h
	$(CC) $(CFLAGS) -c -o $@ main.c

clean :
	rm *.o $(TARGET)
