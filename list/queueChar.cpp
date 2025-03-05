#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

struct Node{
    char value;
    Node *next;
};


//prototypes functions
void menu();
void insertNode(Node *&, Node *&, char);
void deleteNode(Node *&, Node *&, char &);
bool isEmpty(Node *); 

int main(){

    menu();
    
    getch();
    return 0;
}


void menu(){
    Node *start = nullptr;
    Node *end = nullptr; 
    int option;
    char value;

    do{
        cout << "\tMenu: \n" <<endl;
        cout << "1. Insert char." <<endl;
        cout << "2. Show elements from queue." <<endl;
        cout << "3. Exit." <<endl;
        cout << "Option: ";
        cin >> option;

        switch(option){
            case 1: cout << "Insert value: ";
                    cin >> value;
                    insertNode(start, end, value);
                    break;
            case 2: cout << "Delete elements from que" << endl;
                    while(start != nullptr){
                        deleteNode(start, end, value);

                        if(start != nullptr)
                            cout << value <<" ->";
                        else
                            cout << value << " -> NULL"; 
                    }
                    system("pause");
                    break;
            case 3: break;
        }
        system("cls");
    }while(option != 3);
}

// enqueue: O(1) (amortizado, Lista enlazada y arreglo [sondaje])
void insertNode(Node *&start, Node *&end, char value){
    Node *newNode = new Node();

    newNode->value = value;

    if(isEmpty(start))
        start = newNode;
    else
        end->next = newNode;
        
    end = newNode;
}

// empty: O(1) (Lista enlazada y arreglo)
bool isEmpty(Node *p){
    return (p == nullptr)? true : false;
}

// dequeue: O(1) (Lista enlazada y arreglo)
void deleteNode(Node *&start, Node *&end, char &value){
    value = start->value;
    Node *aux = start;

    if(start==end){
        start = nullptr;
        end = nullptr;
    }
    else
        start = start->next;
        
    delete aux;
}