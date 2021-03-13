CC = gcc
CFLAGS = -Wall -Wextra -Werror
OBJS = main.o makewatch.o rush01.o checking.o
TARGET = a.out

all: $(TARGET)

clean:
	rm -f *.o
	rm -f $(TARGET)

$(TARGET) : $(OBJS)
	      $(CC) -o $@ $(OBJS)

main.o : main.c
makewatch.o : makewatch.c
rush01.o : rush01.c
checking.o : checking.c
