#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>

int main(int argc, char** argv){
    
    struct stat info;
    int err;
    char ch;
    if(argc < 3){
        printf("wis-tar: tar-file file [...]\n");
        exit(1);
    }
    
    FILE *dstFile = fopen(argv[1], "w");
    
    
    for(int i = 2 ;i < argc; i++){
        FILE *fp = fopen(argv[i], "r");
        if (fp == NULL) {
            printf("wis-tar: cannot open file\n");
            exit(1);
        }
        
        
        if(strlen(argv[i])<100){
            fprintf(dstFile, "%s", argv[i]);
            char* padding = malloc((100 - strlen(argv[i]) * sizeof(char)));
            memset(padding,'\0',(100 - strlen(argv[i]) * sizeof(char)));
            fwrite(padding, sizeof(char), 100 - strlen(argv[i]), dstFile);
        }else{
            fprintf(dstFile, "%.*s", 100, argv[i]);
        }
        
        
        
        
        err = stat(argv[i], &info);
        if(err == 0){
            fwrite(&info.st_size, sizeof(long), 1, dstFile);
        }
        while ((ch=fgetc(fp))!=EOF)
        {
            fputc(ch,dstFile);
        }
    }
    
    
    
    
    
}
