//write your code here
// Code by Jagpreet153
#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        int a[m],d[m];
        for(int i=0;i<m;i++)
        cin>>a[i];
        sort(a,a+m);
        for(int i=0;i<m-1;i++)
        {
            d[i]=a[i+1]-a[i]-1;  // The distance is calculated as the difference between the positions of two consecutive infected houses minus one
        }
        d[m-1]=a[0]+n-a[m-1]-1;
        sort(d,d+m);
        int i,j=0,ans=0;
        for(i=0;i<m;i++)
        {
            d[m-1-i]=d[m-1-i]-1-4*i;
            if(d[m-1-i]>0) ans+=d[m-1-i];  //This is done to simulate the process of protecting the houses. If the resulting distance is greater than zero, it is added to the total number of houses that will be infected in the end
            if(d[m-1-i]==0 && j==0)  //If the resulting distance is zero and no house has been protected yet (j == 0), one house is protected and added to ans.
            { 
                ans++;
                j++;
            }
        }
        cout<<n-ans<<endl;
    }
    return 0;
}