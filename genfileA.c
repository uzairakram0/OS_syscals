#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

#define filename "A"

int main(int argc, char **argv){
    remove(filename);
    /*Print USAGE if ran without Size*/
    if(argc < 2 ){fprintf(stderr, "usage: %s <file_size>\n", argv[0]); exit(1);}
    int file_size = atoi(argv[1]);
    
     FILE * pFile;
     pFile = fopen ( filename , "wb" );
     fseek ( pFile , file_size * 1000 * 1000 - 6 , SEEK_SET );
     fputs('\0', pFile);
     fclose ( pFile );
    
     return 0;
    
}
