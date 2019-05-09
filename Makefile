CC=gcc
CFLAGS=-Wall -std=gnu99

fta: main.o utils.o graph.o dijkstra.o
	$(CC) $(CFLAGS) main.o utils.o graph.o dijkstra.o -o fta