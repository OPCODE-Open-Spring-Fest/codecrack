//write your code here
#include<bits/stdc++.h>
using namespace std;
 int main()
 {
    long n;
    cin>>n;
    if(n%2==0)
    {
        long s=((n/2)+1)*((n/2)+1);
        cout<<s<<endl;

    }else{
        long s=n*4;
        cout<<s<<endl;
    }
 }
