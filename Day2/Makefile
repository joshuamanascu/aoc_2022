CC = gcc
CFLAGS = -Wall -Wextra -g -I./src/include

SOURCES = day2.c
OBJS = day2.o
HEADERS =

dice: $(OBJS)
	$(CC) $(CFLAGS) -o day2 $(OBJS)

$(OBJS): $(SOURCES) $(HEADERS)
	$(CC) $(CFLAGS) -c $(SOURCES)


clean:
	rm $(OBJS)

