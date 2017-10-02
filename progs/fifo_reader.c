#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>

int main(int argc, char * argv[]){

	if(argc!=2){
		perror("Wrong input");
		exit(-1);
	}

	if(access(argv[1],F_OK)!=0){
		perror("No fifo file");
		exit(-2);
	}

	int fd=open(argv[1],O_RDONLY);

	if(fd<0){
		perror("Open error");
		exit(-3);
	}

    char ch;

    while(read(fd,&ch,1)>0){
        printf("%c",ch);
    }
    printf("\n");


	if(close(fd)<0){
		perror("Can't close descriptor");
		exit(-5);
	}
	return 0;
}
