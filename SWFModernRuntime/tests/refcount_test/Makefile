# Makefile for Reference Counting Test
#
# Builds a standalone test for the ASObject reference counting implementation

CC = gcc
CFLAGS = -Wall -Wextra -std=c17 -DDEBUG -g
INCLUDES = -I../../include -I../../include/actionmodern

SRCS = refcount_test.c ../../src/actionmodern/object.c
OBJS = $(SRCS:.c=.o)
TARGET = refcount_test

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) $(INCLUDES) $(SRCS) -o $(TARGET)

clean:
	rm -f $(TARGET) $(OBJS)

run: $(TARGET)
	./$(TARGET)

test: run

.PHONY: all clean run test
