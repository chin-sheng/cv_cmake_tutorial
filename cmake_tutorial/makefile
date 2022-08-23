all: main

CC = g++
INCLUDE = /app/include 
CFLAGS = -g -Wall

main: calculator.o main.o
	$(CC) calculator.o main.o -o main
main.o: main.cpp include/calculator.h
	$(CC) -I$(INCLUDE) $(CFLAGS) -c main.cpp 
calculator.o: src/calculator.cpp include/calculator.h
	$(CC) -I$(INCLUDE) $(CFLAGS) -c src/calculator.cpp 

clean:
	rm -f main.out calculator.o main.o