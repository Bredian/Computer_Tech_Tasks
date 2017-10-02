#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>

int main(int argc, char * argv[]){
	int fd;

	if(argc!=3){
		perror("Wrong input");
		exit(-1);
	}

		if(access(argv[1],F_OK)!=0){

			if(mkfifo(argv[1],0777)<0){
				perror("file creation error");
				exit(-2);
			}
	}

	fd=open(argv[1],O_WRONLY);

	if(fd<0){
		perror("Can't open");
		exit(-3);
	}

	if(write(fd,argv[2],strlen(argv[2]))<0){
		perror("Write error");
		exit(-4);
	}

	if(close(fd)<0){
		perror("Can't close descriptor");
		exit(-5);
	}
}
