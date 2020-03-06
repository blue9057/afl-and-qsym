CFLAGS := -fno-stack-protector
CC := gcc
CXX := g++

all: example3

example3: example3.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -rf example3
