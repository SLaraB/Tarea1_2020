CC=g++
CFLAGS=-Wall -O3 -std=c++14
BINS=pila cola pilaArr
all: clean  cola 


cola:
	$(CC) $(CFLAGS) -o colasimple simpleQueue.cpp
	$(CC) $(CFLAGS) -o coladoble doubleQueue.cpp

clean:
	@echo " [CLN] Removing binary files"
	@rm -f $(BINS)
