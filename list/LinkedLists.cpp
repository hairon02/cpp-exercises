#include<iostream>
#include<conio.h>
using namespace std;

struct Node{
    int value;
    Node *next;
};

void insertList(Node *&, int); // Insert value in sort
void showList(Node *);

int main(){
    Node *list = NULL;

    insertList(list, 8);
    insertList(list, 10);
    insertList(list, 9);
    showList(list);
    getch();
    return 0;
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
        cout << p->value << endl;
        p = p->next;
    }
} 