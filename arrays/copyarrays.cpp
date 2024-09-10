#include<iostream>
#include<conio.h>

using namespace std;

int main(){
    int letras1[]={'a','b','c','d','e'};
    int letras2[]={'q','w','e','r','t'};
    int letras3[10];

    for(int i=0; i<5; i++)
        letras3[i] = letras1[i];

    for(int i = 5; i<10; i++)
        letras3[i] = letras2[i-5];
    
    for(int i=0; i<10; i++)
        cout<< letras3[i] << endl;

    getch();
    return 0;
}