CC = g++
CFLAGS = -Wextra -Wall -pedantic

all: main.o gen.o
	$(CC) -std=c++14 $(CFLAGS) -o main main.o gen.o
	
main.o: main.cpp gen.h 
	$(CC) $(CFLAGS) -c main.cpp

gen.o: gen.cpp gen.h
	$(CC) $(CFLAGS) -c gen.cpp
