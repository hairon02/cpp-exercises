#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;

struct Node{
    int value;
    Node *next;
};

void insertList(Node *&, int); // Insert value in sort
void showList(Node *);
void menu();
void search(Node *, int);
int size(Node *);
bool empty(Node *);
int value_at(Node *, int);
void pushFront(Node *&, int);
int popFront(Node *&);
void pushBack(Node *&, int);
int popBack(Node *&);
int front(Node *);
int back(Node *);
int insertIndex(Node *&, int, int);
int erase(Node *&, int);
int valueNfromEnd(Node *, int);

Node *list = NULL;

int main(){

    menu();
    return 0;
}

void menu(){
    int option, value, index;
    do{
        cout << "Menu"<<endl;
		cout << "0.- Salir"<<endl;
		cout << "1.- Insertar elementos a la salida  "<<endl;
		cout << "2.- Mostrar elementos de la lista"<<endl;
		cout << "3.- Buscar un elemento de la lista"<<endl;
		cout << "4.- Size de la lista"<<endl;
		cout << "5.- Is empty?"<<endl;
		cout << "6.- Obtener el valor del indice i"<<endl;
		cout << "7.- Push front"<<endl;
		cout << "8.- Pop front"<<endl;
		cout << "9.- Push Back"<<endl;
        cout << "10.- Pop Back" << endl;
        cout << "11.- Front" << endl;
        cout << "12.- Back" << endl;
        cout << "13.- Insert Index" << endl;
        cout << "14.- Erase" << endl;
        cout << "15.- Value n from end" << endl;
        cout << "Opcion: "; 
        cin >> option;

        switch(option){
            case 1: cout << "Digite un numero: ";
                    cin >> value;
                    insertList(list, value);
                    break;
            case 2: showList(list);
                    break;
            case 3: cout << "Digite un numero: ";
                    cin >> value;
                    search(list, value);
                    break;
            case 4: cout << "Size de la lista: " << size(list) << endl;
                    break;
            case 5: 
                    if(empty(list))
                        cout << "La lista esta vacia" << endl;
                    else 
                        cout << "La lista no esta vacia" << endl; 
                    break;
            case 6: cout << "Digite un numero: ";
                    cin >> value;
                    cout << "El valor de la posicion ["<<value<<"] es: " << value_at(list, value) << endl;
                    break;
            case 7: cout << "Digite un numero: ";
                    cin >> value;
                    pushFront(list, value);
                    break;
            case 8: value = popFront(list);
                    if(value == -1)
                        cout << "Lista vacia, no se puede eliminar elementos" << endl;
                    else    
                        cout << "Valor eliminado: " << value << endl;
                    break;
            case 9: cout << "Digite un numero: ";
                    cin >> value;
                    pushBack(list, value);
                    break;
            case 10: value = popBack(list);
                    if(value == -1)
                        cout << "Lista vacia, no se puede eliminar elementos" << endl;
                    else    
                        cout << "Valor eliminado: " << value << endl;
                    break;
            case 11: value = front(list);
                    if(value == -1)
                        cout << "Lista vacia" << endl;
                    else
                        cout << "Front: " << front(list) << endl;
                    break;
            case 12: value = back(list);
                    if(value == -1)
                        cout << "Lista vacia" << endl;
                    else
                    cout << "Back: " << back(list) << endl;
                    break;
            case 13: cout << "Index: "; 
                    cin >> index;
                    cout << endl << "Value: ";
                    cin >> value;
                    if(insertIndex(list, value, index) == 1)
                        cout << "Valor insertado" << endl;
                    else    
                        cout << "No se pudo insertar" << endl;
            case 14: cout << "Index: ";
                    cin >> index;
                    value = erase(list, index);
                    if(value == -1)
                        cout << endl << "Lista vacia" << endl;
                    if(value == 0)
                        cout << endl << "Index fuera de rango" << endl;
                    else    
                        cout << endl << "Elemento en el indice " << index <<" eliminado." << endl;
                    break;
            case 15: cout << "Index: ";
                    cin >> index;
                    value = valueNfromEnd(list, index);
                    if(value == -1)
                        cout << "Index fuera de rango" << endl;
                    if(value == 0)
                        cout << "Lista vacia" << endl;
                    if(value!= -1 && value != 0)    
                        cout << "Elemento en el indice " << index << ": "<< value << endl;
                    break;
        }

        cout << "Presiona una tecla para continuar..." << endl;
        if(option != 0)
            getch();
        system("cls");
    }while(option != 0);
}

void insertList(Node *&list, int n){
    Node *new_node = new Node();
    new_node->value = n;

    Node *aux1 = list;
    Node *aux2;

    while( aux1 != NULL && aux1->value < n){
        aux2 = aux1;
        aux1 = aux1->next;
    }

    if(list == aux1)    // No entro al ciclo while. La lista esta vacio o el primer valor es mayor a n.
        list = new_node;
    else // No se encuentra en list, esta en medio o al final.
        aux2->next = new_node;
    
    new_node->next = aux1;
}

void showList(Node *list){
    Node *p = list;

    while(p != NULL){
        cout << p->value << " -> ";
        p = p->next;
    }
    cout << "NULL" << endl;
} 

void search(Node *list, int item){
    Node *p = list;
    bool isFound = false;

    while(p != NULL && p->value <= item){
        if(p->value == item)
            isFound = true;
        p = p->next;
    }

    if(isFound)
        cout << "El elemento " << item << " si se encuentra" << endl;
    else    
        cout << "El elemento " << item << " no se encuentra" << endl;
}

int size(Node *list){
    Node *aux = list;
    int i = 0;

    while(aux != NULL){
        aux = aux->next;
        ++i;
    }
    return i;
}

bool empty(Node *list){
    return list == NULL;
}

int value_at(Node *list, int index){
    Node *aux = list;

    if(index < 0 || index >= size(list))
        return -1;//throw out_of_range("Fuera de rango");
    
    for(int i = 0; i < index; ++i)
        aux = aux->next;

    return aux->value;
}

void pushFront(Node *&list, int value){
    Node *new_node = new Node();

    new_node->value = value;

    new_node->next = list; 
    list = new_node;    
}

int popFront(Node *&list){
    if(empty(list))
        return -1;
    
    Node *aux = list;
    int value = list->value;

    list = list->next;
    delete aux;

    return value;
}

void pushBack(Node *&list, int value){
    Node *new_node = new Node();
    new_node->value = value;

    Node *aux1 = list;
    Node *aux2;
    
    while(aux1 !=NULL){
        aux2 = aux1;
        aux1 = aux1->next;
    }
    if(list == aux1)
        list = new_node;
    else
        aux2->next = new_node;
    
    new_node->next = NULL;
}

int popBack(Node *&list){
    if(empty(list))
        return -1;

    Node *aux1 = list;
    Node *aux2;
    int item;

    while(aux1->next != NULL){
        aux2 = aux1;
        aux1 = aux1->next;
    }

    item = aux1->value;
    aux2->next = NULL;
    delete aux1;

    return item;   
}

int front(Node *list){
    if(empty(list))
        return -1;
    return list->value;
}

int back(Node *list){
    if(empty(list))
        return -1;
    
    Node *aux = list;

    while(aux->next != NULL)
        aux = aux->next;

    return aux->value;
}

int insertIndex(Node *&list, int value, int index){
    if(index < 0 || index >= size(list))
        return -1;
    Node *new_node = new Node();
    Node *aux1 = list;
    Node *aux2;

    new_node->value = value;

    for(int i=0; i < index; ++i){
        aux2 = aux1;
        aux1 = aux1->next;
    }

    if(list == aux1)
        list = new_node;
    else
        aux2->next = new_node;
    new_node->next = aux1;

    return 1;
}

int erase(Node *&list, int index){
    if(empty(list))
        return -1;
    if(index < 0 || index >= size(list))
        return 0;

    Node *aux1 = list;
    Node *aux2;

    for(int i= 0; i < index; ++i){
        aux2 = aux1;
        aux1 = aux1->next;
    }

    if(list == aux1)
        list = list->next;
    else
        aux2->next = aux1->next;
    
    delete aux1;

    return 1;
}

int valueNfromEnd(Node *list, int index){
    if(empty(list))
        return 0;

    int sizex = size(list);
    if(index < 0 || index >= sizex || sizex - 1 - index < 0)
        return -1;

    Node * aux = list;

    for(int i = 0; i < sizex - 1 - index; ++i)
        aux = aux->next; 
    
    return aux->value;
}