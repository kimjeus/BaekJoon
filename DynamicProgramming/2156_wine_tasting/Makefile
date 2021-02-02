CC = gcc
CFLAGS = -W -Wall
TARGET = wine_tasting_exe
OBJS = wine_tasting.o main.o

all = $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

wine_tasting.o : wine_tasting.c wine_tasting.h
	$(CC) $(CFLAGS) -c -o $@ wine_tasting.c

main.o : main.c wine_tasting.h
	$(CC) $(CFLAGS) -c -o $@ main.c

clean :
	rm *.o $(TARGET)
