CC=g++

trabalho2: main.o graph.o vertice.o aresta.o
	$(CC) -o trabalho2 main.o graph.o vertice.o aresta.o

