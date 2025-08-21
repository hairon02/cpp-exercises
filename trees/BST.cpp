#include <iostream>
#include <conio.h>

using namespace std;

struct Node{
    int value;
    Node *left;
    Node *right;
    Node *father;
};

Node *tree = nullptr;

void menu();
Node *createNode(int, Node *);
void insertNode(Node *&, int, Node *);
void showTree(Node *, int);
bool search(Node *, int);
void preOrden(Node *);
void InOrden(Node *);
void postOrden(Node *);
void eliminar(Node *, int);
void deleteNode(Node *);
Node *minimo(Node *);
void reemplazar(Node *, Node *);
void freeNode(Node *);
int main(){

    menu();
    return 0;
}

void menu(){
    int dato, option, count = 0;
    insertNode(tree, 8, nullptr);
    insertNode(tree, 3, nullptr);
    insertNode(tree, 1, nullptr);
    insertNode(tree, 6, nullptr);
    insertNode(tree, 4, nullptr);
    insertNode(tree, 7, nullptr);
    insertNode(tree, 10, nullptr);
    insertNode(tree, 14, nullptr);
    insertNode(tree, 13, nullptr);

    do{
        cout << "\tMenu\t" << endl;
        cout << "1. Insert new Node" << endl;
        cout << "2. Show BST" << endl;
        cout << "3. Search element BST" << endl;
        cout << "4. Recorrido preOrden" << endl;
        cout << "5. Recorrido InOrden" << endl;
        cout << "6. Recorrido postOrden" << endl;
        cout << "7. Eliminar un nodo del arbol" << endl;
        cout << "8. Exit" << endl;
        cout << "Option: ";
        cin >> option;
        switch (option)
        {
        case 1:
            cout << endl <<"Digite un numero: ";
            cin >> dato;
            cout << endl;
            insertNode(tree, dato, nullptr);
            system("pause");
            break;
        case 2:
            cout << "\t\tTree: " << endl;
            showTree(tree, count);
            cout << "\n";
            system("pause");
            break;
        case 3:
            cout<< "Insert element to search: ";
            cin >> dato;
            if(search(tree, dato))
                cout << "The element exist" << endl;
            else
                cout << "The element doesn't exist" << endl;
            system("pause");
        case 4: 
            cout << "Recorrido en profundidad - PreOrden" <<endl;
            preOrden(tree);
            cout << endl;
            system("pause");
            break;
        case 5:
            cout << "Recorrido en profundidad - InOrden" <<endl;
            InOrden(tree);
            cout << endl;
            system("pause");
            break;
        case 6:
            cout << "Recorrido en profundidad - IostOrden" << endl;
            postOrden(tree);
            cout << endl;
            system("pause");
            break;
        case 7:
            cout << "Digite el numero a eliminar: ";
            cin >> dato;
            eliminar(tree, dato);
            cout << "\n";
            system("pause");
            break;
        default:
            break;
        }
        system("cls");
    }while(option != 8);
}

Node *createNode(int n, Node *father){
    Node *newNode = new Node();

    newNode->value = n;
    newNode->left = nullptr;
    newNode->right = nullptr; 
    newNode->father = father;
    return newNode;
}

void insertNode(Node *&tree, int n, Node *father){
    
    if(tree == nullptr){
        Node *newNode = createNode(n, father);
        tree = newNode;
    }
    else{
        int valueHead = tree->value;
        if(n < valueHead)
            insertNode(tree->left, n, tree);
        else
            insertNode(tree->right, n, tree);
    }

}

void showTree(Node *tree, int count){
    if(tree == nullptr)
        return;

    showTree(tree->right, count + 1);
    
    for(int i = 0; i < count; i++)
        cout << "   ";
    cout << tree->value << endl;

    showTree(tree->left, count + 1);
}

bool search(Node *tree, int n){
    if(tree == nullptr)
        return false;
    
    if(tree->value == n)
        return true;
    
    if(n < tree->value)
        return search(tree->left, n);

    return search(tree->right, n);
}

//! Recorridos arbol

// Recorrido del arbol en preorden
void preOrden(Node *tree){
    if(tree == nullptr)
        return;
    
    cout << tree->value << " - ";
    preOrden(tree->left);
    preOrden(tree->right);
}

// Recorrido del arbol en InOrden
void InOrden(Node *tree){
    if(tree == nullptr)
        return;

    InOrden(tree->left);
    cout << tree->value << " - ";
    InOrden(tree->right);
}

// Recorrido del arbol en postOrden
void postOrden(Node *tree){
    if(tree == nullptr)
        return;
    
    postOrden(tree->left);
    postOrden(tree->right);

    cout << tree->value << " - ";
}

//! Funcion que busca el nodo a eliminar
void eliminar(Node *tree, int n){
    if(tree == nullptr)
        return;
    
    if(n < tree->value) // Si el valor es menor
        eliminar(tree->left, n); // Busca por la izq
    else if(n > tree->value)
        eliminar(tree->right, n);
    else    // Si ya encontro el valor
        deleteNode(tree); // El arbol es la posicion del nodo en la que vamos
}

//Funcion para eliminar el nodo encontrado
void deleteNode(Node *nodeDelete){

    //Caso 1: Si tiene hijo izq y der
    if(nodeDelete->left && nodeDelete->right){
        Node *menor = minimo(nodeDelete->right);
        nodeDelete->value = menor->value;
        deleteNode(menor);
        return;
    }
    //Caso 2: Si hay un hijo izq o der
    if(nodeDelete->left){// Si tiene hijo izq 
        reemplazar(nodeDelete, nodeDelete->left);
        freeNode(nodeDelete);
        return;
    }
    if(nodeDelete->right){// Si tiene hijo der 
        reemplazar(nodeDelete, nodeDelete->right);
        freeNode(nodeDelete);
        return;
    }
    //Nodos sin hijos
    reemplazar(nodeDelete, nullptr);
    freeNode(nodeDelete);
}

// Funcion para determinar el nodo mas izquierdo posible
Node *minimo(Node *tree){
    if(tree == nullptr)
        return nullptr;
    
    if(tree->left)// Si tiene hijo izq, llamamos a la func
        return minimo(tree->left);

    //Si no tiene hijo izq
    return tree;
}

//  Funcion para reemplazar dos nodos
void reemplazar(Node *tree, Node *newNode){
    if(tree->father){ //arbol->padre hay que asignarle su nuevo hijo
        if(tree == tree->father->left) // Si el nodo a eliminar es el hijo izq
            tree->father->left= newNode;
        else if(tree == tree->father->right) // Si el nodo a eliminar es el hijo der
            tree->father->right = newNode;
    }
    if(newNode) // Asignarle su nuevo padre
        newNode->father = tree->father;
    
} 

// Funcion para destruir un nodo
void freeNode(Node *node){
    node->left = nullptr;
    node->right= nullptr;

    delete node;
}