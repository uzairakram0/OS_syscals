//This program demostrates the operation of system calls from homework 1 question 1
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>

int main(){
    
    pid_t cpid = fork();
    
    if (cpid == 0){
        /*CHILD*/
        //The print statement returns the process id perpspective from child
        printf("CHILD: pid:%d ppid:%d cpid:*%d*\n", getpid(), getppid(), cpid);
        //exce() family of system calls that change the process image to a new process
        execl("/bin/ls", "/bin/ls", "-a", "-r", "-t", "-l", NULL);
        
    } else if(cpid > 0){
        /*PARENT*/
        wait(&cpid);        // Wait system call waits for the child process
        //The print statement returns the process id perpspective from parent
        printf("\nPARENT: pid:%d ppid:%d cpid:*%d*\n", getpid(), getppid(), cpid);
    } else {
        perror("fork");
        //The exit system call terminates the process
        exit(1);
    }
    
    //The exit system call terminates the process
    exit(0);
}
