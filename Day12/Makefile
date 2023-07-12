CC = gcc
CFLAGS = -Wall -Wextra -g -I./src/include

SOURCES = day12.c
OBJS = day12.o
HEADERS =

day12: $(OBJS)
	$(CC) $(CFLAGS) -o day12 $(OBJS)

$(OBJS): $(SOURCES) $(HEADERS)
	$(CC) $(CFLAGS) -c $(SOURCES)


clean:
	rm $(OBJS)

