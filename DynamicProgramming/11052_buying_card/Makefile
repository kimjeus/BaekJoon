CC = gcc
CFLAGS = -W -Wall
TARGET = buying_card_exe
OBJS = buying_card.o main.o

all = $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

buying_card.o : buying_card.c buying_card.h
	$(CC) $(CFLAGS) -c -o $@ buying_card.c

main.o : main.c buying_card.h
	$(CC) $(CFLAGS) -c -o $@ main.c

clean :
	rm *.o $(TARGET)
