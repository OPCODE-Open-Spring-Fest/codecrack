#include <iostream>

using namespace std;

int main() {
    int x,y;
    cin>>x>>y;

    while (x>=0 && y>=0) {
        if (x >= 2 && y >= 2) {
            x -= 2;
            y -= 2;
        } 
        else if (x == 1 && y >= 12) {
            x -= 1;
            y -= 12;
        } 
        else if(x == 0 && y>=22){
            y -= 22;
        }
        else {
            cout<<"Biraj"<<endl;
            break;
        }
        if(y>=22){
            y -= 22;
        }
        else if((y>=12 && y<22) && x>=1){
            y -= 12;
            x -=1;
        }
        else if((y<12 && y>=2) && x>=2){
            y -= 2;
            x -= 2;
        }
        else{
            cout<<"Bluemin"<<endl;
            break;
        }

    return 0;
}