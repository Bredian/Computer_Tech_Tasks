#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <ctype.h>

int main(){
    int fdin = open("in.txt",O_RDONLY);
    int fdout = open("out.txt",O_WRONLY);
    if(fdin<0){
        perror("in.txt open error");
        exit(1);
    }
    if(fdout<0){
        perror("out.txt open error");
        exit(2);
    }
    char c;
    while (read(fdin,&c,1)>0) {
        c=toupper(c);
        if(write(fdout,&c,1)<0){
            perror("write error");
            exit(3);
        }
    }
    

    if(close(fdin)<0){
        perror("in.txt close error");
        exit(4);
    }
    if(close(fdout)<0){
        perror("out.txt close error");
        exit(5);
    }
    return 0;
}
