/*Desarrolle un programa que lea de la entrada estandar un vector de enteros y determine el mayor elemento del vector*/

#include<iostream>
#include<conio.h>

using namespace std;

int main(){
    int numbers[100], n, max=0;
    cout << "Ingrese el numero de elementos del arreglo: ";
    cin >> n;

    for(int i=0;i<n;i++){
        cout << i+1 << ". Ingrese un numero:";
        cin >> numbers[i];

    if(numbers[i]> max)
        max = numbers[i];
    }

    cout << "El numero mayor es: " << max << endl;
    return 0;
}