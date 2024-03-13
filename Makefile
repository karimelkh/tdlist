CC=g++
CFLAGS = -c -Wall -Wextra -std=c++17

EXEC=tdlist


all:
	$(CC) tdlist.cpp -o tdlist

install:
	sudo cp ./$(EXEC) /bin/

uninstall:
	sudo rm /bin/$(EXEC)
	
clean:
	rm -rf $(EXEC)
