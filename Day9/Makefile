CC = gcc
CFLAGS = -Wall -Wextra -g -I./src/include

SOURCES = day9.c
OBJS = day9.o
HEADERS =

day9: $(OBJS)
	$(CC) $(CFLAGS) -o day9 $(OBJS)

$(OBJS): $(SOURCES) $(HEADERS)
	$(CC) $(CFLAGS) -c $(SOURCES)


clean:
	rm $(OBJS)

