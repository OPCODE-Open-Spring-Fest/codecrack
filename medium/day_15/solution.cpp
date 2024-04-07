//write your code here
//Code by Jagpreet153
//Approach : Using unordered map to store the frequency of the difference of the element and its index the number of pairs (i, j) where j > i and a[j] - a[i] = j - i is equal to the number of indices j where j > i and a[j] - j = a[i] - i.
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,i;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int arr[n];
        for(i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        unordered_map<int, long long int> count;
        long long pair=0;
        for (i=0;i<n;i++) {
            pair +=count[arr[i] -i]++;
        }
        cout<<pair<<endl;   
    }
}