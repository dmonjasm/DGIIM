#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main(int argc, char * argv[]){

int fd;

if((fd=open(argv[0],O_RDWR,S_IRWXU|S_IRGRP|S_IXGRP|S_IROTH|S_IXOTH)) < 0){
	perror("error en el open");
	exit(EXIT_FAILURE);
}

struct flock cerrojo;

cerrojo.l_type=F_WRLCK;
cerrojo.l_whence=SEEK_SET;
cerrojo.l_start=0;
cerrojo.l_len=0;
cerrojo.l_pid=getpid();

if(fcntl(fd,F_SETLK,&cerrojo) < 0){
	perror("fcntl");
	exit(EXIT_FAILURE);
}

while(1){
}

return 0;
}
