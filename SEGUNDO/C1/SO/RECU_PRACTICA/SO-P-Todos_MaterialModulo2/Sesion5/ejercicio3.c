#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int main(int argc, char * argv[]){

sigset_t conjunto;

sigfillset(&conjunto);
sigdelset(&conjunto,SIGUSR1);

sigsuspend(&conjunto);

return 0;
}
