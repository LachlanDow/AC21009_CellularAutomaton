CC = g++
CFLAGS = -Wextra -Wall -pedantic

all: main.o gen.o gen2d.o
	$(CC) -std=c++14 $(CFLAGS) -o main main.o gen.o gen2d.o
	
main.o: main.cpp gen.h gen2d.h
	$(CC) $(CFLAGS) -c main.cpp

gen.o: gen.cpp gen.h
	$(CC) $(CFLAGS) -c gen.cpp

gen2d.o: gen2d.cpp gen2d.h
	$(CC) $(CFLAGS) -c gen2d.cpp
