#include "header.h"

void print_airports(char *fp){
    char c;
    while((c = fgetc(fp)) != EOF){
        printf("%c", c);
    }
}

int count_lines(FILE *fp){
    char c;
    int count = 0;
    for(c = getc(fp); c != EOF; c = getc(fp)){
        if(c == '\n'){
            count++;
        }
    }
    return count;
}