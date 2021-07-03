#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>

int main(int argc, char * argv[]){

pid_t childpid;
int fd_1,fd_2;

if((childpid=fork()) < 0){
	perror("error fork");
	exit(EXIT_FAILURE);
}

if(childpid==0){
	struct flock cerrojo_1;
		
	cerrojo_1.l_type=F_WRLCK;
	cerrojo_1.l_whence=SEEK_SET;
	cerrojo_1.l_start=0;
	cerrojo_1.l_len=0;
	cerrojo_1.l_pid=getpid();

	if((fd_1=open("temporal",O_RDWR,S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH)) < 0){
		perror("error open");
		exit(EXIT_FAILURE);
	}

	if(fcntl(fd_1,F_SETLKW, &cerrojo_1) < 0){
		perror("fcntl");
		exit(EXIT_FAILURE);
	}

	fd_2=open("temporal2",O_RDWR,S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH);
	fcntl(fd_2,F_SETLKW, &cerrojo_1);
	
	while(1){
	}
}

if(childpid != 0){
	struct flock cerrojo_2;
		
	cerrojo_2.l_type=F_RDLCK;
	cerrojo_2.l_whence=SEEK_SET;
	cerrojo_2.l_start=0;
	cerrojo_2.l_len=0;
	cerrojo_2.l_pid=getpid();

	if((fd_2=open("temporal2",O_RDWR,S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH)) < 0){
		perror("error open");
		exit(EXIT_FAILURE);
	}

	if(fcntl(fd_2,F_SETLK, &cerrojo_2) < 0){
		perror("fcntl");
		exit(EXIT_FAILURE);
	}


	fd_1=open("temporal",O_RDWR,S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH);
	fcntl(fd_1,F_SETLKW, &cerrojo_2);
}
while(1){
}

return 0;
}


