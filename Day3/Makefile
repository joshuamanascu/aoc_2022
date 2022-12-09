CC = gcc
CFLAGS = -Wall -Wextra -g -I./src/include

SOURCES = day3.c
OBJS = day3.o
HEADERS =

dice: $(OBJS)
	$(CC) $(CFLAGS) -o day3 $(OBJS)

$(OBJS): $(SOURCES) $(HEADERS)
	$(CC) $(CFLAGS) -c $(SOURCES)


clean:
	rm $(OBJS)

