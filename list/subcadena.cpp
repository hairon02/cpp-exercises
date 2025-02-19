#include <iostream>
#include <string>
#include <conio.h>
using namespace std;

int lengthOfLongestSubstring(string s){
    string aux1;
    char k;
    int i = 0;

    while(i < (int) s.length()){
        k = s[i];
        if(aux1.find(k)!= string::npos)
            return i;
        else
            aux1.append(1,s[i]);    // or push_back(s[i]) or aux1 += s[i]
        i++;
    }
    return i;
}

int main(){
    string placa;   //cadena a ingresar

    while(true){
        cout << "Ingrese la placa" << endl; 
        getline(cin, placa);
        cout << "Valor de la longitud: " << lengthOfLongestSubstring(placa)<< endl;

    }

    return 0;
}