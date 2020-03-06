CFLAGS := -fno-stack-protector
CC := gcc
CXX := g++

all: example2

example2: example2.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -rf example2
