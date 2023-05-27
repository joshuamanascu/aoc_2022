CC = gcc
CFLAGS = -Wall -Wextra -g -I./src/include

SOURCES = day5.c
OBJS = day5.o
HEADERS =

day5: $(OBJS)
	$(CC) $(CFLAGS) -o day5 $(OBJS)

$(OBJS): $(SOURCES) $(HEADERS)
	$(CC) $(CFLAGS) -c $(SOURCES)


clean:
	rm $(OBJS)

