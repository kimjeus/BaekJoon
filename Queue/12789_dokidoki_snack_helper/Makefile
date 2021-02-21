CC = gcc
CFLAGS = -W -Wall
TARGET = dokidoki_snack_helper_exe
OBJS = dokidoki_snack_helper.o main.o

all = $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

dokidoki_snack_helper.o : dokidoki_snack_helper.c dokidoki_snack_helper.h
	$(CC) $(CFLAGS) -c -o $@ dokidoki_snack_helper.c

main.o : main.c dokidoki_snack_helper.h
	$(CC) $(CFLAGS) -c -o $@ main.c

clean :
	rm *.o $(TARGET)
