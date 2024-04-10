//write your code here
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int a[n];
        int one=0,mone=0;
        for(int i=0;i<n;i++)
        {
            cin >> a[i];
            if(a[i]==1)
            one++;
            else
            mone++;
        }
        int c=0;
        for(int i=0;i<n;i++)
        {
            if(one>=mone && mone%2==0)
            {
            break;}
            if(one<mone || mone%2!=0)
            {
                if(a[i]==-1){
                c++;one++;mone--;}
            }
            

        }
        cout << c << endl;
    }
}