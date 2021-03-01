CC = gcc
CFLAGS = -W -Wall
TARGET = music_program_exe
OBJS = music_program.o main.o

all = $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

music_program.o : music_program.c music_program.h
	$(CC) $(CFLAGS) -c -o $@ music_program.c

main.o : main.c music_program.h
	$(CC) $(CFLAGS) -c -o $@ main.c

clean :
	rm *.o $(TARGET)
