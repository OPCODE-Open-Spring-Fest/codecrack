//write your code here
#include<bits/stdc++.h>
using namespace std;
int main(){
    int a ;
    cin>>a;
    while(a--){
        int b , c;
        cin>>b>>c;
        int arr[b][c];
        for(int i = 0 ; i<b ; i++){
            for(int j = 0 ; j<c ; j++){
                cin>>arr[i][j];
            }
        }
        int count = 0;
        int minimum = INT_MAX;
        int sum = 0;
        for(int i = 0 ; i<b ; i++){
            for(int j = 0 ; j<c ; j++){
                sum = sum + abs(arr[i][j]);
                minimum = min(minimum , abs(arr[i][j]));
                if(arr[i][j]<=0){
                count ++;
            }
            }
        }
        if(count%2 == 0){
            cout<<sum<<endl;
        }
        else{
            cout<<sum - 2 * minimum<<endl;
        }
            }
    return 0;
}
