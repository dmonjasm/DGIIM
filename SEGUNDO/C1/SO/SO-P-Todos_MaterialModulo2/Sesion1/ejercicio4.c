#include <sys/stat.h>
#include <stdlib.h>
#include <errno.h>

#define S_ISREG2(mode)  (mode & 0170000) == 0100000 ? printf("Archivo regular\n"):printf("No es un archivo regular\n")

int main(int narg, char * argv[])
{
    struct stat atributos;

    if(narg != 2){
        perror("Error numero de argumentos erroneo");
        exit(EXIT_FAILURE);
    }

    lstat(argv[1], &atributos);

    S_ISREG2(atributos.st_mode);

    return 0;
}