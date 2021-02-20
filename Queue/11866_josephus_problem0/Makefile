CC = gcc
CFLAGS = -W -Wall
TARGET = josephus_problem0_exe
OBJS = josephus_problem0.o main.o

all = $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

josephus_problem0.o : josephus_problem0.c josephus_problem0.h
	$(CC) $(CFLAGS) -c -o $@ josephus_problem0.c

main.o : main.c josephus_problem0.h
	$(CC) $(CFLAGS) -c -o $@ main.c

clean :
	rm *.o $(TARGET)
