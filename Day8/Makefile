CC = gcc
CFLAGS = -Wall -Wextra -g -I./src/include

SOURCES = day8.c
OBJS = day8.o
HEADERS =

day8: $(OBJS)
	$(CC) $(CFLAGS) -o day8 $(OBJS)

$(OBJS): $(SOURCES) $(HEADERS)
	$(CC) $(CFLAGS) -c $(SOURCES)


clean:
	rm $(OBJS)

