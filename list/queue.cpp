#include <iostream>
#include <conio.h>

using namespace std;

struct Node{
    int dato;
    Node *siguiente;
};

void insertNode(Node *&, Node *&, int);
bool colaVacia(Node *);

int main(){
    Node *frente = nullptr;
    Node *fin = nullptr;
    int dato;

    cout << "Digite un numero: ";
    cin >> dato;
    insertNode(frente, fin, dato);
    getch();

    return 0;
}

void insertNode(Node *&frente, Node *&fin, int n){
    //Crear espacio en memoria para almacenar un nodo
    Node *nuevo_nodo = new Node();

    // Asignar ese nuevo nodo al dato que queremos insertar.
    nuevo_nodo->dato = n;
    nuevo_nodo->siguiente = nullptr;

    // Asignar los punteros frente y fin hacie el nuevo nodo
    if (colaVacia(frente))
        frente = nuevo_nodo;
    else 
        fin->siguiente = nuevo_nodo;
    
    fin = nuevo_nodo;

    cout << "\tElemento " << n << " insertado correctamente. " << endl;

}

bool colaVacia(Node *p){
    return (p == nullptr)? true : false;
}