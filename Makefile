CC=g++ -std=c++11

CFLAGS=-c -Wall

all: main.o node.o eval.o search_alg.o
		$(CC) main.o node.o eval.o search_alg.o -o search

main.o: main.cpp
		$(CC) $(CFLAGS) main.cpp

node.o: node.cpp 
		$(CC) $(CFLAGS) node.cpp

eval.o: eval.cpp
		$(CC) $(CFLAGS) eval.cpp

search_alg.o: search_alg.cpp
		$(CC) $(CFLAGS) search_alg.cpp

clean: 
		rm -rf *o search
		
