#include <iostream>
#include <conio.h>

using namespace std;

struct Node{
    int value;
    Node *left;
    Node *right;
};

Node *tree = nullptr;

void menu();
Node *createNode(int);
void insertNode(Node *&, int);
void showTree(Node *, int);
bool search(Node *, int);

int main(){

    menu();
    return 0;
}

void menu(){
    int dato, option, count = 0;

    do{
        cout << "\tMenu\t" << endl;
        cout << "1. Insert new Node" << endl;
        cout << "2. Show BST" << endl;
        cout << "3. Search element BST" << endl;
        cout << "4. Exit" << endl;
        cout << "Option: ";
        cin >> option;

        switch (option)
        {
        case 1:
            cout << endl <<"Digite un numero: ";
            cin >> dato;
            cout << endl;
            insertNode(tree, dato);
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
        default:
            break;
        }
        system("cls");
    }while(option != 4);
}

Node *createNode(int n){
    Node *newNode = new Node();

    newNode->value = n;
    newNode->left = nullptr;
    newNode->right = nullptr; 

    return newNode;
}

void insertNode(Node *&tree, int n){
    
    if(tree == nullptr){
        Node *newNode = createNode(n);
        tree = newNode;
    }
    else{
        int valueHead = tree->value;
        if(n < valueHead)
            insertNode(tree->left, n);
        else
            insertNode(tree->right, n);
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