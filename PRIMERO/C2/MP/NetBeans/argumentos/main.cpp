#include <iostream>
#include <cstdlib>

using namespace std;
int main(int nargs,char * args[]) {
    
    for(int i = 0; i < nargs; i++){
        cout << "Parámetro(" << i << ") = " << args[i] << endl;
    }
    
    int i =  atoi(args[1]);
    
    cout << i << endl<< endl;
    
    return 0;
}


