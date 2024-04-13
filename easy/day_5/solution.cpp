#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        long long int prev;
        cin >> prev;
        if(prev == 1){
            prev++;
        }
        cout << prev << " ";
        for(int i = 1 ; i < n ; i++){
            long long int temp;
            cin >> temp;
            if(temp == 1){
                temp++;
            }
            if(temp%prev == 0){
                temp = temp + 1;
            }
            cout << temp << " ";
            prev = temp;
        } 
        cout << endl;
    }
    return 0;
}