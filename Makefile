CC=g++
CFLAGS = -c -Wall -Wextra -std=c++17

EXEC=tdlist


all:
	$(CC) tdlist.cpp -o tdlist

install: all
	sudo cp ./$(EXEC) /bin/

uninstall:
	sudo rm /bin/$(EXEC)
	
clean:
	rm -rf $(EXEC)
