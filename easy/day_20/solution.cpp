#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        if (n==1){
            cout << 1 << endl;
            continue;
        }
        if(n==4){
            cout << "3 4 1 2" << endl;
            continue;
        }
        if(n%2 !=0){
            cout << -1 << endl;
            continue;
        } 
        
        else{
            int arr[n];
            for(int i = 1 ; i <= n ; i++){
                arr[i] = i;
                if(i%2 == 0 && i!=2){
                    swap(arr[i] , arr[i-2]);
                }
            }
            for(int i = 1 ; i<=n ; i++){
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}