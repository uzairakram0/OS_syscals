//The Program transfers file using standar I/O at diffrent chunk sizes
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define source_file "A"
#define target_file "B"

int main(int argc, char** argv){
    
    int size;   //size in bytes to be transfered
    //Gets the size of beuffer from argv
    if(argc != 1) { size = atoi(argv[1]); } else { size = 1; }
    char buf[size]; //Buffer for transfering file
    
    remove(target_file);    //Remove the target file before writing
    
    int target, source,fileread;    //File descriptors
    
    // target file opened or created
    if((target = open(target_file, O_CREAT | O_APPEND | O_RDWR, 0666))==-1){
      perror("open");
    }
    
    // open the source file
    source = open(source_file, O_RDONLY);
    
    //Time the copy of file using standard I/O
    clock_t start, end;
    double cpu_time_used;
    
    start = clock();
    while( (fileread=read(source, buf, sizeof(buf)) > 0) ){ // while there are things to read from the source
        //write to target file
      write(target, buf, sizeof(buf));
    }
    end = clock();
    
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    
    printf("Time used: %.5f s\n", cpu_time_used);
    
    close(source);
    close(target);
    
    return 0;
}
