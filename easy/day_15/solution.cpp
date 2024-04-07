//write your code 
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int t;
    cin>>t;
    while (t--)
    {
       ll a,b,c;
       cin>>a>>b>>c;
       if ((abs(a-b) + c)%2==0)
       {
        cout<<"Second"<<endl;
       }
       else
       {
        cout<<"First"<<endl;
       }
       
    }
    
}