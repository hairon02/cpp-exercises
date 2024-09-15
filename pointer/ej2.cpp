//Correspondencia entre arrays y punteros

#include<iostream>
#include<conio.h>
using namespace std;

int main(){
    int num[] = {15,72,63,85};
    int *p;

    p = num; // equivalente a p = &num[0]

    for( int i=0; i<4; i++){
        /*cout << p[0] << endl;
        p++;*/
        cout << "Elemento del vector ["<<i<<"]: "<< *p++ << endl; // out: 1,2,3,5
    }
    getch();        
    return 0;
}