#include <stdio.h>
#include <stdlib.h>
#include <regex.h>
#include <string.h>

int main(int argc, char** argv){
    
    if(argc < 2){
        printf("wis-grep: searchterm [file ...]\n");
        exit(1);
    }
    
    
    char* pattern = malloc(strlen(argv[1])+5);
    
    strcpy(pattern,".*");
    strcat(pattern,argv[1]);
    
    strcat(pattern,".*");
    
    regex_t regex;
    
    regcomp( &regex, pattern, REG_EXTENDED);
    
    char* line = NULL;
    size_t linecap = 0;
    ssize_t linelen;
    
    
    for(int i = 2 ;i < argc; i++){
        FILE *fp = fopen(argv[i], "r");
        if (fp == NULL) {
            printf("wis-grep: cannot open file\n");
            exit(1);
        }
        while((linelen = getline(&line, &linecap, fp)) > 0){
            if(regexec( &regex, line, 0, NULL, 0) == 0) printf("%s",line);
        }
    }
    
    if(argc == 2){
        while((linelen = getline(&line, &linecap, stdin)) > 0){
            if(regexec( &regex, line, 0, NULL, 0) == 0) printf("%s",line);
        }
    }
    
    
    
}
