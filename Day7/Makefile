CC = gcc
CFLAGS = -Wall -Wextra -g -I./src/include

SOURCES = day7.c
OBJS = day7.o
HEADERS =

day7: $(OBJS)
	$(CC) $(CFLAGS) -o day7 $(OBJS)

$(OBJS): $(SOURCES) $(HEADERS)
	$(CC) $(CFLAGS) -c $(SOURCES)


clean:
	rm $(OBJS)

