#include <list>
#include <iostream>

using namespace std;

void rotalista (list<int> & l, int n){
    list<int>::iterator it=l.begin();

    for(int i=0; i < n; i++){
        l.push_back(*it);
        ++it;
        l.pop_front();
    }
}
int main(int argc, char * argv[]){
    list<int> lista={0,1,2,3,4,5};
    int n=4;

    rotalista(lista,n);

    list<int>::iterator iterador=lista.begin();

    for( ; iterador != lista.end(); ++iterador){
        cout << *iterador << endl;
    }

    return 0;

}