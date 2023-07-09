CC = gcc
CFLAGS = -Wall -Wextra -g -I./src/include

SOURCES = day11.c
OBJS = day11.o
HEADERS =

day11: $(OBJS)
	$(CC) $(CFLAGS) -o day11 $(OBJS)

$(OBJS): $(SOURCES) $(HEADERS)
	$(CC) $(CFLAGS) -c $(SOURCES)


clean:
	rm $(OBJS)

