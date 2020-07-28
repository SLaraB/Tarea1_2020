CC=g++
CFLAGS=-Wall -O3 -std=c++14
BINS= simple doble array
all: clean simple doble array

simple:
	$(CC) $(CFLAGS) -o simple SimpleQueue.cpp

doble:
	$(CC) $(CFLAGS) -o doble DobleQueue.cpp

array:
	$(CC) $(CFLAGS) -o array ArrayQueue.cpp

clean:
	@echo " [CLN] Removing binary files"
	@rm -f $(BINS)
