CC = gcc
CFLAGS = -W -Wall
TARGET = expression_of_set_exe
OBJS = expression_of_set.o main.o

all = $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

expression_of_set.o : expression_of_set.c expression_of_set.h
	$(CC) $(CFLAGS) -c -o $@ expression_of_set.c

main.o : main.c expression_of_set.h
	$(CC) $(CFLAGS) -c -o $@ main.c

clean :
	rm *.o $(TARGET)
