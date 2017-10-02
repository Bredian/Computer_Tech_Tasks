#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

int main(int argc,char * argv[]){
	if(argc!=2){
		 perror("Wrong input");
		 exit(-1);
	 }
	int fd[2];
	if(pipe(fd)<0){
		perror("Pipe fail");
		exit(-2);
	}
	int pid = fork();
	if(pid<0){
		perror("Fork fail");
		exit(-3);
	}
	if(pid>0){
		if(close(fd[0])<0){
			perror("Close read descriptor parent error");
			exit(-4);
		}
		if(write(fd[1],argv[1],strlen(argv[1]))<0){
			perror("write error");
			exit(-5);
		}
		printf("Parent pid: %d Parent ppid: %d\n",getpid(),getppid());
		if(close(fd[1])<0){
			perror("Close write descriptor parent error");
			exit(-6);
		}
		//only to not lose parent
		sleep(1);
		return 0;
	}
	if(pid==0){
		
		if(close(fd[1])<0){
			perror("Close write descriptor child error");
			exit(-7);
		}
		char * str = malloc (strlen(argv[1])*sizeof(char));
		if(read(fd[0],str,strlen(argv[1]))<0){
			perror("read error");
			exit(-8);
		}
		
		printf("%s\n",str);
		printf("Child pid: %d Child ppid: %d\n",getpid(),getppid());
		if(close(fd[0])<0){
			perror("Close read descriptor child error");
			exit(-9);
		}
		return 0;
	}
	return 0;
}
