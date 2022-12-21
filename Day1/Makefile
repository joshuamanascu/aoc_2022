CC = gcc
CFLAGS = -Wall -Wextra -g -I./src/include

SOURCES = day1.c
OBJS = day1.o
HEADERS =

day1: $(OBJS)
	$(CC) $(CFLAGS) -o day1 $(OBJS)

$(OBJS): $(SOURCES) $(HEADERS)
	$(CC) $(CFLAGS) -c $(SOURCES)


clean:
	rm $(OBJS)

