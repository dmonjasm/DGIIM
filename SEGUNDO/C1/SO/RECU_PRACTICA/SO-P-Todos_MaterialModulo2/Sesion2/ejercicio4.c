#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<errno.h>
#include<ftw.h>
#include<string.h>

int buscar(const char *pathname, const struct stat *statbuf, int typeflag, struct FTW *ftwbuf){
	if(S_ISREG(statbuf->st_mode)){
		printf("%s %d\n", pathname, statbuf->st_ino);
	}

return 0;
}


void mensaje_error(){
	printf("Modo ejecución: <programa> <dir_pathname>\n");
	exit(EXIT_FAILURE);
}

int main(int argc, char * argv[]){

if(argc < 2)
	mensaje_error();

if(nftw(argv[1], buscar, 1000, 0) != 0){
	perror("nftw");
	exit(EXIT_FAILURE);
}

return 0;
}
