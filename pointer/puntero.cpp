#include<iostream>
#include<conio.h>

using namespace std;

int main(){
    int num, *p;

    num = 20;
    p = &num;

    cout << "Number: " << *p << endl;
    cout << "Dir: " << p << endl;
    getch();
    return 0;
}