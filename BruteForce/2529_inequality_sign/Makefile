CC = gcc
CFLAGS = -W -Wall
TARGET = inequality_sign_exe
OBJS = inequality_sign.o main.o

all = $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

inequality_sign.o : inequality_sign.c inequality_sign.h
	$(CC) $(CFLAGS) -c -o $@ inequality_sign.c

main.o : main.c inequality_sign.h
	$(CC) $(CFLAGS) -c -o $@ main.c

clean :
	rm *.o $(TARGET)
