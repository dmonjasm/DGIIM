#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>

int main(int argc, char * argv[]){

int nprocs=20;
pid_t childpid;

for(int i=1; i < nprocs; i++){
	if((childpid=fork()) == -1){
		fprintf(stderr, "Could not create child %d: %s\n", i, strerror(errno));
	}

	if(!childpid)
		exit(EXIT_SUCCESS);
}

return 0;
}
