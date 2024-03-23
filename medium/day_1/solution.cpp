#include<bits/stdc++.h>
using namespace std;

void correct(vector<int> &store,int temp,int index){
    if(index==0 || store[index]>store[index-1]){
        return;
    }

    if(store[index]<store[index-1]){
        swap(store[index],store[index-1]);
        correct(store,temp,index-1);
    }
}

int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        vector<int> store;

        for(int i=0;i<n;i++){
            int temp;
            cin>>temp;

            store.push_back(temp);
            correct(store,temp,i);
        }

        for(int i=0;i<n;i++){
            cout<<store[i]<<" ";
        }
        cout<<endl;
    }
}