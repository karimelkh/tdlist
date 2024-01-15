CC=g++
CFLAGS=-c -Wall

all:
	$(CC) tdlist.cpp -o tdlist

clean:
	rm -rf tdlist
