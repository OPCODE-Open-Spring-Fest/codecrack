//write your code here
#include <bits/stdc++.h>
using namespace std;
#define int long long int

void solve ()
{
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    vector<int> index;
    for(int i=0;i<n;i++)
    {
        if (i+1>a[i])
        {
            index.push_back(i+1);
        }

    }   
    int ans=0;
    for (int i:index)
    {
        int val=a[i-1];
        ans+=lower_bound(index.begin(),index.end(),val)-index.begin();
    }   
    cout<<ans<<endl;  
    


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
