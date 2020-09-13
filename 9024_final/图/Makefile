CC = gcc
# CCFLAGS = -Wall -Werror -std=c11

warshall:
	$(CC) $(CCFLAGS) -o warshall warshall.c

kruskal: kruskal.o WGraph.o
	$(CC) $(CCFLAGS) -o kruskal WGraph.o kruskal.o

floyd: floyd.o WGraph.o
	$(CC) $(CCFLAGS) -o floyd WGraph.o floyd.o

dijkstra: dijkstra.o WGraph.o PQueue.o
	$(CC) $(CCFLAGS) -o dijkstra WGraph.o dijkstra.o PQueue.o

edmonds-karp: edmonds-karp.o WGraph.o queue.o
	$(CC) $(CCFLAGS) -o edmonds-karp WGraph.o queue.o edmonds-karp.o

kruskal.o: kruskal.c WGraph.h
	$(CC) $(CCFLAGS) -c kruskal.c

floyd.o: floyd.c WGraph.h
	$(CC) $(CCFLAGS) -c floyd.c

dijkstra.o: dijkstra.c WGraph.h PQueue.h
	$(CC) $(CCFLAGS) -c dijkstra.c

edmonds-karp.o: edmonds-karp.c WGraph.h queue.h
	$(CC) $(CCFLAGS) -c edmonds-karp.c

WGraph.o: WGraph.c WGraph.h
	$(CC) $(CCFLAGS) -c WGraph.c

queue.o: queue.c queue.h
	$(CC) $(CCFLAGS) -c queue.c

PQueue.o: PQueue.c PQueue.h
	$(CC) $(CCFLAGS) -c PQueue.c

clean:
	rm -f warshall kruskal floyd edmonds-karp *.o