CC = gcc
CFLAGS = -Wall -Wextra -g -I./src/include

SOURCES = day10.c
OBJS = day10.o
HEADERS =

day10: $(OBJS)
	$(CC) $(CFLAGS) -o day10 $(OBJS)

$(OBJS): $(SOURCES) $(HEADERS)
	$(CC) $(CFLAGS) -c $(SOURCES)


clean:
	rm $(OBJS)

