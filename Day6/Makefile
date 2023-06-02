CC = gcc
CFLAGS = -Wall -Wextra -g -I./src/include

SOURCES = day6.c
OBJS = day6.o
HEADERS =

day1: $(OBJS)
	$(CC) $(CFLAGS) -o day6 $(OBJS)

$(OBJS): $(SOURCES) $(HEADERS)
	$(CC) $(CFLAGS) -c $(SOURCES)


clean:
	rm $(OBJS)

