CC = gcc
CFLAGS = -Wall -g `pkg-config --cflags glib-2.0`
LDFLAGS = `pkg-config --libs glib-2.0`
SRCS = main.c myapp-spell-checker.c
OBJS = $(SRCS:.c=.o)
EXECUTABLE = main

.PHONY: clean

$(EXECUTABLE): $(OBJS)
	$(CC) $(OBJS) $(LDFLAGS) -o $(EXECUTABLE)

all: $(EXECUTABLE)

clean:
	rm -f $(OBJS) $(EXECUTABLE)
