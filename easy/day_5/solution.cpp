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
        cout << prev << " ";
        for(int i = 1 ; i < n ; i++){
            long long int temp;
            cin >> temp;
            if(temp%prev == 0){
                temp++;
            }
            cout << temp << " ";
            prev = temp;
        } 
        cout << endl;
    }
    return 0;
}