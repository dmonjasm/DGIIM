#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    if(argc < 3){
        cerr << "Modo ejecución: <primera iteración> <chunk>" << endl;
        exit(-1);
    }

    int chunk=atoi(argv[2]);
    int iter=atoi(argv[1]);
    int operaciones=0;
    int j=1;
    int op_64=0;
    int num_chunk=0;
    
    for(int i = 0; i < 1440; i++){
	operaciones += 12*i + 1;

    }
   
    while (j <= 1440){
	for(int i=1; i <= chunk; i++){
		op_64 += 64*12*num_chunk + i;
		j++;
 	}
	
	num_chunk= j/(chunk);
	cout << j << " " << num_chunk << endl;
    }

    

    cout << "Nº multiplicaciones = Nº sumas = " << operaciones << endl; 
    cout << "64: " << operaciones << endl;

    return 0;
}
