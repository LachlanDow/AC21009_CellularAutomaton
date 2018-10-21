CC = g++
CFLAGS = -Wextra -Wall -pedantic
 
%: %.cpp
	$(CC) -std=c++14 $(CFLAGS) $< -o $@
