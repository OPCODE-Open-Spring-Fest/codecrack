//write your code here
//write your code here
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    int ans=INT_MAX;
    for(int i=0; i<n; i++)
    {
        int temp=abs(a[i]);
        if(temp < ans) ans=temp;
    }
    cout<<ans<<endl;
    return 0;
}