//write your code here
// Code by Jagpreet153
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,k,x,i,s=0,e=0,total=0;
    cin>>n>>k;
    vector<int> arr;
    for(i=0;i<n;i++)
    {
        cin>>x;
        arr.push_back(x);
    }
    unordered_map<int,int> count;
    while (e<arr.size()) {
        count[arr[e]]++;
        while (count.size()> k) {
            count[arr[s]]--;
            if (count[arr[s]]==0) {
                count.erase(arr[s]);
            }
            s++;
        }
        total+=e-s+1;
        e++;
    }
     cout<<total<<endl;
}