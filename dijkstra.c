#include "header.h"
#define INFINITY 9999

void PrintNode(Graph *g, int index1, int index2, int vert, int edg){
    char *n1 = malloc(sizeof(char)*3);
    char *n2 = malloc(sizeof(char)*3);
    int dist;
    for(int i = 0; i < vert; i++){
        if(g->Vertices[i].index == index1){
            strcpy(n1, g->Vertices[i].val);
        }
        if(g->Vertices[i].index == index2){
            strcpy(n1, g->Vertices[i].val);
        }
    }

    for(int i = 0; i < edg; i++){
        if(g->Edges[i].source_index == index1 && g->Edges[i].dest_index == index2){
            dist = g->Edges[i].cost;
        }
    }
    printf("%s => %s [%d]", n1, n2, dist);
}

void dijkstra(Graph *graph, int src, int de){

    
    int vertices = graph->vertex_count;
    char *NodeName[vertices];
    int dists[graph->vertex_count][graph->vertex_count];
    for(int i = 0; i < graph->vertex_count; i++){
        for(int j = 0; j < graph->vertex_count; j++){
            dists[i][j] = -1;
        }
        NodeName[i] = malloc(sizeof(char)*3);
        strcpy(NodeName[i], graph->Vertices[i].val);
    }
    // Load Edge Count into Graph
    for(int i = 0; i < graph->edge_count; i++){
        //printf("[%d] [%d] [%d]", graph->Edges[i].source_index, graph->Edges[i].dest_index)
        dists[graph->Edges[i].source_index][graph->Edges[i].dest_index] = graph->Edges[i].cost;
        dists[graph->Edges[i].dest_index][graph->Edges[i].source_index] = graph->Edges[i].cost;
    }

    /*for(int i = 0; i < graph->vertex_count; i++){
        for(int j = 0; j < graph->vertex_count; j++){
            printf("[%d] ", dists[i][j]);
        }
        printf("\n");
    }*/

    int cost[vertices];
    int visited[vertices];
    int parent[vertices]; 
        parent[src] = -1;

    for(int i = 0; i < vertices; i++){
        cost[i] = INFINITY;
        visited[i] = 0;
    }

    cost[src] = 0;

    for(int num = 0; num < vertices - 1; num++){

        // Get the next index
        int min = INFINITY;
        int mindex;

        for(int i = 0; i < vertices; i++){
            if(visited[i] == 0 && cost[i] <= min){
                min = cost[i];
                mindex = i;
            }
        }

        visited[mindex] = 1;
        for(int j = 0; j < vertices; j++){
            if(visited[j] == 0 && dists[mindex][j] != -1 && cost[mindex] != INFINITY && (cost[mindex] + dists[mindex][j] < cost[j])){
                cost[j] = cost[mindex] + dists[mindex][j];
                parent[j] = mindex;
            }
        }
    }

    /*for(int i = 0; i < vertices; i++){
        int pNode = parentNode[i];
        printf("[%d] tt [%d] ", i, cost[i]);
        printf("[");
        while(pNode != -1){
            printf("%d", pNode);
            pNode = parentNode[pNode];
        }
        printf("]\n");
    }*/

    for(int i = 0; i < vertices; i++){
        if(i == de){
            printf("Total Length: [%d]\n", cost[i]);
            int pNode = parent[i];
            //printf("%d %s\n", i, NodeName[i]);
            printf("%s => %s [%d]\n", NodeName[pNode], NodeName[i], dists[i][pNode]);
            while(pNode != -1){
                if(parent[pNode] != -1){
                    printf("%s => %s [%d]\n", NodeName[parent[pNode]], NodeName[pNode], dists[parent[pNode]][pNode]);
                    pNode = parent[pNode];
                }
                else{
                    break;
                }
            }
        }

    }
    
    return;
}