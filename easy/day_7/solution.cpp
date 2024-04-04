//Write your code here
//_______ rohityadav_1390 ______

//Approach: we have to find "a" from given "d". we know 1 is divisor of every number so for making "a", we will start with 1 and store it in a vector.
//Now we have to keep a minimum difference of "d", so for this will add d to first element of vector and will check is it prime. if it is? then store them in vector and so on till we get 3 divisor and last divisor will be number itself.
//and finally we will multiply first three element of that vector and that will be our answer.

#include<bits/stdc++.h>
#define int long long
using namespace std;

bool checkDivisor(int x){
    int count=0;
    for(int i=2;i<x;i++){
        if(x%i==0){
            return true;
        }
    }
    return false;
}
int32_t main(){
    int t;
    cin>>t;
    while(t--){
            int d;
            cin>>d;
            int a=1;
            vector<int>v(4,0);
            v[0]=1;
            for(int i=1;i<4;i++){
                int x;
                x=v[i-1]+d;
                while(checkDivisor(x)){
                    x++;
                }
                v[i]=x;
            }
            for(int i=0;i<3;i++){
                a*=v[i];
            }
            cout<<a<<endl;
    }
}