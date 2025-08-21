#include <iostream>
#include <stdexcept> // para std::underflow_error

using namespace std;

struct Node{
    int value;
    Node *next;
};

Node *stack = nullptr;
int sizeStack(Node *);
bool isEmpty(Node *);
void push(Node *&, int);
void showStack(Node *);
int pop(Node *&);
int main(){


    cout << sizeStack(stack) << endl;
    cout << isEmpty(stack)<< endl;
    push(stack, 5);
    showStack(stack);
    pop(stack);
    showStack(stack);
    pop(stack);

    return 0;
}

int sizeStack(Node *stack){
    int counter = 0;

    while(stack != nullptr){
        stack = stack->next;
        counter++;
    }

    return counter;
}

bool isEmpty(Node *stack){
    return (stack == nullptr)? true : false;
}

// Push an element on the stack
void push(Node *&stack, int value){
    Node *newNode = new Node();
    newNode->value = value;
    
    newNode->next = stack;

    stack = newNode;
}

void showStack(Node *stack){
    if(isEmpty(stack)){
        cout << "NULL" << endl;
        return;
    }

    while(stack != nullptr){
        cout << stack->value << " -> ";
        stack = stack->next;
    }
    
    cout << "NULL" << endl;
}

// Pop an element off the stack 
int pop(Node *&stack){
    if(isEmpty(stack))
        throw underflow_error("Stack vacio: no se puede hacer pop");
        
    Node *aux = stack;
    int value = stack->value;

    stack = stack->next;
    delete aux;

    return value;
}