CC=g++
CFLAGS=-c -Wall

all:
	$(CC) tdlist.cpp -o tdlist

install:
	sudo cp ./tdlist /bin/

uninstall:
	sudo rm /bin/tdlist

clean:
	rm -rf tdlist
