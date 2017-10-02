#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <sys/wait.h>

int main(){

    char  PATH[100];
    int pid,status;
    //printf("%s",PATH);
    
    while(1){
        scanf("%s",PATH);
        if(strcmp(PATH,"quit")==0) exit(0);
        //because cd is not working and I want to change directory
        if(strcmp(PATH,"cd")==0){
            printf("Choose path\n");
            scanf("%s",PATH);
            chdir(PATH);
            continue;
        }
        int N,i;
        scanf("%d",&N);
        char ** args = (char **) malloc(N*sizeof(char *));
        for(i=0;i<N;i++){
            args[i]=malloc(100*sizeof(char));
        }
        for(i=0;i<N;i++){
            scanf("%s",args[i]);
        }
        args[N]=NULL;
        pid=fork();
        if(pid==0){
            if(execv(PATH,args)<0){
                perror("Cannot exec");
                exit(1);
            }
        
    }
        if(pid>0){
            if(wait(&status)<0){
                perror("wait error");
                exit(2);
            }
        }
    }
    return 0;
}
