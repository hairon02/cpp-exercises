#include <iostream>
#include <string>
#include<conio.h>
using namespace std;

int diffMax(int px[], int n){
    int minValue = px[0];
    int maxDiff = 0;

    for(int i = 1; i < n ; i++){
        if(px[i] > minValue)
            maxDiff = max(maxDiff, px[i] - minValue);
        else
            minValue = px[i];
    }

    return (maxDiff > 0)? maxDiff: -1;

}

int main(){
    int px[5] = {6,1,8,7,4};

    cout << "Diferencia max: " << diffMax(px, 5);



    getch();
    return 1;
}
