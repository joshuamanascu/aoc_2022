CC = gcc
CFLAGS = -Wall -Wextra -g -I./src/include

SOURCES = day4.c
OBJS = day4.o
HEADERS =

day4: $(OBJS)
	$(CC) $(CFLAGS) -o day4 $(OBJS)

$(OBJS): $(SOURCES) $(HEADERS)
	$(CC) $(CFLAGS) -c $(SOURCES)


clean:
	rm $(OBJS)

