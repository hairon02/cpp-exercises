#include<iostream>
#include<conio.h>

using namespace std;

int main(){
    int num, *p;

    cout << "Digite un numero: "; cin >> num;
    p = &num;   // guardando la pos de memoria

    if(*p%2 == 0 )
        cout << "Numero " << *p << " es par" << endl;
    else
        cout << "Numero " << *p << " es impar" << endl;
    cout << "Posicion: " << p << endl;

    getch();
    return 0;
}