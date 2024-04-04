//write your code here
#include <bits/stdc++.h>
using namespace std;
#define int long long int





void solve ()
{
   
    int n;
    cin>>n; 
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    for (int i=0;i<n-1;i++)
    {
        int p=0;
        for (int j=0;j<i+1;j++)
        {
            p^=a[j];
        }
        bool ans=false;
        int x=0;
        for (int j=i+1;j<n;j++)
        {
            x^=a[j];
            if (x==p)
            {
                ans=true;
                x=0;
            }
        
        }
        if (x==0 && ans)
        {
            cout<<"YES"<<endl;
            return;
        }
    }
    cout<<"NO"<<endl;
    return;
}


signed  main() {

	int t;
	cin>>t;
    // cout<<t;
	while(t--)
    {
        solve();

    }  

    

}
