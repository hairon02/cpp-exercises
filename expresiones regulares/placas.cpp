// AAA-00-00
// Expresion regular:   [A-Z]{3}-\d{2}-\d{2}

#include <iostream>
#include <regex>    //Libreria para trabajar las expresiones regulares
#include <string>

using namespace std;

bool validarPlaca(const string& );    //recibe un string de manera constante y por refencia

int main(){
    string placa;   //cadena a ingresar

    while(true){
        cout << "Ingrese la placa" << endl; 
        getline(cin, placa);
        if(validarPlaca(placa))
            cout << "Placa valida"<< endl;
        else
            cout << "Placa invalida"<< endl;

    }

    return 0;
}

bool validarPlaca(const string& placa){
    //Regex para las placas

    //Almacenar nuestra expresion regular en una variable
    const regex expReg("[A-Z]{3}-\\d{2}-\\d{2}");
    /*Al momento de usar "\", tenemos que ser cuidadosos, algunos compiladores no reconocen este caracter,
    para que nuestra expresion regular funcione del todo bien es necesario agregar otra "\", quedando \\d{2}*/

    //Validacion de la placa con la expresion regular usando regex match
    //Recibe la cadena a comparar y la expresion regular a comparar. Devuelve un bool
    return regex_match(placa, expReg);
}