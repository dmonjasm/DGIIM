#include <signal.h>
#include <stdio.h>

int main(int argc, char * argv[]){
    sigset_t new_mask;

    sigfillset(&new_mask);

    sigdelset(&new_mask, SIGUSR1);

    sigsuspend(&new_mask);

}