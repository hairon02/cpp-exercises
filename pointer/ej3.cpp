/*Pedir al usuario n calificaciones y almacenarlos en un arreglo dinamico*/

#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;

//Prototipo de Funcion
void pedirNotas();
void mostrarNotas();
int numCalif, *calif;
int main(){
    
    pedirNotas();
    mostrarNotas();

    delete[] calif; // Liberar el espacio en bytes utilizados anteriormente

    getch();
    return 0;
}

void pedirNotas(){
    cout << "Digite el numero de calificaciones: " ;
    cin >> numCalif;

    calif = new int[numCalif]; //Crear el arreglo
    for(int i = 0; i<numCalif; i++){
        cout << "Ingrese una nota: ";
        cin >> calif[i];    
    }

}

void mostrarNotas(){
    cout << "\nNotas del usuario \n";
    for(int i=0; i<numCalif; i++)
        cout << calif[i] << endl;
}