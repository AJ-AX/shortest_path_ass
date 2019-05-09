#include "header.h"

Graph *load_airports(char *af, char *df){

    FILE *airports = fopen(af, "r");
    FILE *distances = fopen(df, "r");

    Graph *graph = malloc(sizeof(graph));

    graph->vertex_count = 0;
    graph->edge_count = 0;
    
    char c;
    char d;

    for(c = getc(airports); c != EOF; c = getc(airports)){
        if(c == '\n'){
            graph->vertex_count++;
        }
    }
    for(d = getc(distances); d != EOF; d = getc(distances)){
        if(d == '\n'){
            graph->edge_count++;
        }
    }

    graph->Vertices = malloc(sizeof(Vertex) * graph->vertex_count);

    char buffer[100];
    int index = 0;

    fseek(airports, 0, SEEK_SET);
    while(fgets(buffer, 100, airports)){
        char buf1[3];
        char buf2[999];
        sscanf(buffer, "%s %[^\n]s", buf1, buf2);
        graph->Vertices[index].val = malloc(sizeof(char)*3);
        strcpy(graph->Vertices[index].name, buf2);
        strcpy(graph->Vertices[index].val, buf1);
        graph->Vertices[index].index = index;
        //printf("[%s] [%s]\n", graph->Vertices[index].val, graph->Vertices[index].name);
        //printf("[%s] [%d]", graph->Vertices[index].val, graph->Vertices[index].index);
        index++;
    }

    graph->Edges = malloc(sizeof(Vertex) * graph->edge_count);
    index = 0;
    fseek(distances, 0, SEEK_SET);

    while(fgets(buffer, 100, distances)){
        char buf1[3];
        char buf2[3];
        int dis3;
        sscanf(buffer, "%s %s %d", buf1, buf2, &dis3);
        graph->Edges[index].source = malloc(sizeof(char)*3);
        graph->Edges[index].dest = malloc(sizeof(char)*3);
        strcpy(graph->Edges[index].source, buf1);
        strcpy(graph->Edges[index].dest, buf2);
        graph->Edges[index].cost = dis3;

        for(int j = 0; j < graph->vertex_count; j++){
            if(strcmp(graph->Edges[index].source, graph->Vertices[j].val) == 0){
                graph->Edges[index].source_index = graph->Vertices[j].index;
            }
        }
        for(int j = 0; j < graph->vertex_count; j++){
            if(strcmp(graph->Edges[index].dest, graph->Vertices[j].val) == 0){
                graph->Edges[index].dest_index = graph->Vertices[j].index;
            }
        }
        index++;
    }

    /*for(int i = 0; i < graph->edge_count; i++){
       printf("[%s(%d)] [%s(%d)] [%d]\n",graph->Edges[i].source, graph->Edges[i].source_index, graph->Edges[i].dest, graph->Edges[i].dest_index, graph->Edges[i].cost);
    }*/

    return graph;

}