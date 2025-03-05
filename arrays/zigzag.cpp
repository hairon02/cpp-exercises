#include <iostream>
#include <conio.h>
#include <vector>

using namespace std;

string convert(string s, int numRows){
    int numPos = 0;
    int index = 1;
    vector <string> p(numRows); // es lo mismo que vector<vector<char>>, string=vector<char> pero es mas optimo string
    string cad= "";

    if(numRows == 1)
        return s;
        
    for(char c: s){ 
        p[numPos].push_back(c); // p[numPos] += c;
        if(numPos == 0)
            index = 1;
        else if(numPos == numRows - 1)
            index = -1;

        numPos += index;
    }
    /*
    for(int i= 0; i < p.size(); i++)
        for(char c: p[i])
            cad += c;
    */
    for(const string&row: p) // auto reconoce que tipo debe ser row(vector<int>). & para indicar que es una referencia a cada fila de p, no una copia.
        cad += row; // igual que  string(row.begin(), row.end())    
        
    return cad;
}


int main(){

    string s = "PAYPALISHIRING";

    cout << convert(s, 3);
    getch();
    return 0;
}





