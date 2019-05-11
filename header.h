#ifndef HEADER_H
#define HEADER_H

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    typedef struct Edge{
        char *source;
        char *dest;
        int source_index;
        int dest_index;
        int cost;
    }Edge;

    typedef struct Vertex{
        char name[9999];
        char *val;
        int index;
    }Vertex;

    typedef struct Graph{
        int vertex_count;
        int edge_count;
        Vertex *Vertices;
        Edge *Edges;
    }Graph;

    Graph *load_airports(char *af, char *df);
    void dijkstra(Graph *graph, int src, int de);

#endif

