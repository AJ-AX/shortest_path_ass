#include "header.h"

int main(int argc, char **argv){
    if(argc < 3){
        printf("Incorrect Parameters: ./fta <Airports.txt> <Airport_Distance.txt>\n");
        exit(0);
    }

    Graph *g = load_airports(argv[1], argv[2]);
    //dijkstra(g, 1, 3);

    char inp[100];
    char *token;
    char input[3][100];

    while(1){
        printf("Enter Command> ");
        fgets(inp, 100, stdin);
        inp[strcspn(inp, "\n")] = 0;

        token = strtok(inp, " ");
        for(int i = 0; i < 3; i++){
            if(token == NULL){break;}
            strcpy(input[i], token);
            token = strtok(NULL, " ");
        }

        if(strcmp(input[0], "help") == 0){
            printf("Commands: <help> <quit> <airports> <distance>\n");
        }
        else if(strcmp(input[0], "quit") == 0){
            return 0;
        }
        else if(strcmp(input[0], "airports") == 0){
            for(int i = 0; i < g->vertex_count; i++){
                printf("%s %s\n", g->Vertices[i].val, g->Vertices[i].name);
            }
        }
        else if(strcmp(input[0], "distance") == 0){
            int srcnode;
            int destnode;
            int c1 = 0;
            int c2 = 0;
            for(int i = 0; i < g->vertex_count; i++){
                if(strcmp(input[1], g->Vertices[i].val) == 0){
                    srcnode = g->Vertices[i].index;
                    c1 = 1;
                }
                if(strcmp(input[2], g->Vertices[i].val) == 0){
                    destnode = g->Vertices[i].index;
                    c2 = 1;
                }
            }
            if(c1 == 0 || c2 == 0 || strcmp(input[1], input[2]) == 0){
                printf("Invalid Input. Please try again.");
            }
            else{
                //printf("[%d], [%d], [%d], [%d]", srcnode, destnode, c1, c2);
                dijkstra(g, srcnode, destnode);
            }
        }
        else{
            printf("Invalid command. Type <help> for a list of commands.\n");
        }
        
    }
}