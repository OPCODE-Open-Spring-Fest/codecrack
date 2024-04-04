// code by guptaanshuman7

#include<bits/stdc++.h>
using namespace std;

int main(){
    int q;
    cin>>q;

    while(q--){
        long long n;
        cin>>n;
        string s="";//for storing the sequence
        long long i=1;

        while(s.length()<n){
            s+=to_string(i);
            i++;
        }

        cout<<s[n-1]<<endl;
    }
}