CC = gcc
CFLAGS = -W -Wall
TARGET = value_of_parentheses_exe
OBJS = value_of_parentheses.o main.o

all = $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

value_of_parentheses.o : value_of_parentheses.c value_of_parentheses.h
	$(CC) $(CFLAGS) -c -o $@ value_of_parentheses.c

main.o : main.c value_of_parentheses.h
	$(CC) $(CFLAGS) -c -o $@ main.c

clean :
	rm *.o $(TARGET)
