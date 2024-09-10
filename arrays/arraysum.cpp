/* Escribe un programa que defina un vector de numeros y calcule la suma de sus elementos*/

#include<iostream>
#include<conio.h>

using namespace std;

int main(){
    int numbers[] = {1,2,3,4,5};
    int sum = 0;
    for(int i=0;i<5;i++)
        sum += numbers[i];
    cout << "La suma de los elementos del vector es: " << sum << endl;

    getch();
    return 0;
}