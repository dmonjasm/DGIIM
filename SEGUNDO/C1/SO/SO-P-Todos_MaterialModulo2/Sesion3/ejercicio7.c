#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

int main(int argc, char * argv[]){

    int wstatus;

    for(int i=0; i < argc-1; i++){
        argv[i]=argv[i+1];

        if(i==argc-2 && argc > 2){
            if(strcmp(argv[argc-1], "bg") == 0){
                argv[i]="&";
                argv[i+1]=NULL;
            }

            else{
                argv[i]=NULL;
                argv[i+1]=NULL;
            }
        }
    }

    if((execv(argv[0],argv) < 0 )){
        perror("\nError en el execv\n");
        exit(EXIT_FAILURE);
    }

    return 0;
}