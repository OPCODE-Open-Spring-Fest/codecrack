//write you code here
// Code by Jagpreet153
// Approach: The problem is based on the concept of cycle detection in a graph. We can solve this problem by using the concept of cycle detection in a graph.
#include <iostream>
using namespace std;
const int MN = 1048576;
int arr[MN];
bool check[MN];
int main() {
int t;
cin>>t;
while(t--)
{
    int n,co=0,cc=0,x,p,temp;
    cin>>n;
    for(int i=0;i<n;++i) 
    {
        cin>>arr[i];
        --arr[i];
        check[i]=0;
    }
    for(int i=0;i<n;i++)
    {
        if(!check[i])
        {
            x=i;
            p=x;
            temp=x;
            while(!check[x]) {
            check[x]=1;
            int y = arr[x];
            temp=p;
            p=x;
            x=y;
            }
            if (x==temp) 
            ++co;
            else if (x==i) 
            ++cc;
        }
    }
    cout<<cc+!!co<<' '<<cc+co<<'\n';
}
}