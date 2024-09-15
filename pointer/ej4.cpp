/*
Transmision de arreglos
Hallar el maximo elemento de un arreglo.
*/

#include<iostream>
#include<conio.h>
using namespace std;

void max(int *, int);

int main(){
    const int n = 5;
    int numeros[n] = {1,23,56,4445,65};

    max(numeros, n);

    getch();
    return 0;
}

void max(int *p, int n){
    int max = 0;

    for(int i=0; i<n; i++)
        if( *(p+i)>max)
            max = *(p+i);
    
    cout << max;
}