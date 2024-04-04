//write your code here
#include <bits/stdc++.h>
using namespace std;
int main()
{
    string n,m;
    cin >> n >> m;
    sort(n.begin(),n.end());
    if(n[0]=='0'&& n.length()>1)
    swap(n[0],n[1]);
    if(m==n)
    cout << "OK" << endl;
    else
    cout << "WRONG_ANSWER" << endl;
}