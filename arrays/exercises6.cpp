#include<iostream>
#include<conio.h>

using namespace std;

int main(){
    int arr1[5], arr2[5];

    cout << "Ingrese los datos"<<endl;

    for(int i = 0; i < 5; i++){
        cout<<"Posicion " << i << ":";
        cin >> arr1[i];
    }

    cout << "Arreglo 2:" <<endl;
    for( int i = 0; i < 5 ; i++){
        arr2[i] = arr1[i]*2;
        cout << arr2[i] << endl;
    }
    getch();
    return 0;
}