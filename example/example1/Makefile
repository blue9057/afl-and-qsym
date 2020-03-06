CFLAGS := -fno-stack-protector
CC := gcc
CXX := g++

all: example1

example1: example1.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -rf example1
