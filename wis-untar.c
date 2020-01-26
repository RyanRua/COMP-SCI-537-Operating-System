#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv){
    
    char fileName[100];
    int* length = malloc(sizeof(int*));
    if(argc < 2){
        printf("wis-untar: tar-file\n");
        exit(1);
    }
    
    FILE *file = fopen(argv[1], "rb");
    if (file == NULL) {
        printf("wis-untar: cannot open file\n");
        exit(1);
    }
    while(fread(fileName, 1, 100, file) == 100){
        fread(length, 8, 1, file);
        FILE* subFile = fopen(fileName, "w");
        char* buffer = malloc((*length)*sizeof(char));
        fread(buffer, 1, *length, file);
        
        fwrite(buffer, sizeof(char), *length, subFile);
        

        
    }
    
    
    

    
    
    
    
    
}

