//write your code here


#include <iostream>
using namespace std;
long long int a[1000002]={0};
int main() {
    // cout<<5;
    long long int n;
    cin>>n;
    long long int mod=1000000007;

    long long int i,s;
    s=0;
    a[0]=0;
    a[1]=1;
    a[2]=2;
    s=3;
    for(i=3;i<=n;i++)
    {
        a[i]=(a[i]+a[i-1]+1)%mod;
        s=(s+a[i])%mod;
        a[i]=(a[i]+a[i-2])%mod;
    }
    if(n==1)
    cout<<1;
    else if(n==2)
    cout<<3;
    else
    cout<<s;
        return 0;
}
