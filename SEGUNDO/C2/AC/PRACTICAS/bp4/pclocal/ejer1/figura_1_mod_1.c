#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>


struct {
    int a[5000];
    int b[5000];
}  s;

int R[40000];

int main(int argc, char *argv[]){
    int ii;
    int i=0;
    int x1, x2;
    struct timespec cgt1,cgt2;
    double ncgt;

    for (i = 0; i < 5000; i++) {
      s.a[i] = 1;
      s.b[i] = 1;
    }

    clock_gettime(CLOCK_REALTIME,&cgt1);
    for (ii = 0; ii < 40000; ii++){
        x1=0; x2=0;

        for(i = 0; i < 5000; i++){
            x1 += 2*s.a[i]+ii;
            x2 += 3*s.b[i]-ii;
        }

        if(x1 < x2)
            R[ii] = x1;

        else
            R[ii] = x2;
        
    }

    clock_gettime(CLOCK_REALTIME,&cgt2);

    ncgt=(double)(cgt2.tv_sec-cgt1.tv_sec) + (double)((cgt2.tv_nsec - cgt1.tv_nsec)/(1.e+9));

    printf("Tiempo: %f\n", ncgt);
    printf("R[0]=%d -- R[%d]=%d\n",R[0], 39999, R[39999]);

    return 0;
}