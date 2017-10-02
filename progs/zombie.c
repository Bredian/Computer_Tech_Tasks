#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main ()
{
    int status;
    
    int child_pid = fork ();
    if(child_pid<0){
        perror("fork error");
        exit(2);
    }
    if (child_pid > 0) {
        sleep (30);
        if(wait(&status)<0){
            perror("wait error");
            exit(1);
        }
    }
    else {
        printf("%d\n",getpid());
        exit (0);
    }
    return 0;
}
