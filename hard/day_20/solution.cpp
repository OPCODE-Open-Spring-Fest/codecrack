//write your code here
//Code by Jagpreet153
#include <bits/stdc++.h>
using namespace std;
void imp() {
	cout << "IMPOSSIBLE" << endl;
	exit(0);
}
int main () {
	int n,m,a,b,c;
	cin >> n >> m >> a >> b >> c;
	if (n%2==1 && m%2==1) imp();
	if (a*2+b*2+c*4<n*m) imp();
	if (n%2==1 && a<m/2) imp();
	if (m%2==1 && b<n/2) imp();
	bool swp=0;
	if (m%2==1) 
    {
		swp=1;
		swap(n,m);
		swap(a,b);
	}
	vector<string> res(n,string(m,0));
	for (int i=0;i<n/2;i++)
		for (int j=0;j<m/2;j++) 
        {
			vector<bool> used(20,0);
			if (i>0)
            used[res[i*2-1][j*2]]=1;
			if (i>0)
            used[res[i*2-1][j*2+1]]=1;
			if (j>0)
            used[res[i*2][j*2-1]]=1;
			if (j>0)
            used[res[i*2+1][j*2-1]]=1;
			int fu=0;
			while (used[fu]) 
            fu++;
			used[fu]=1;
			int su=0;
			while (used[su]) 
            su++;
			if (c>0) 
            {
				res[i*2][j*2]=fu;
				res[i*2][j*2+1]=fu;
				res[i*2+1][j*2]=fu;
				res[i*2+1][j*2+1]=fu;
				c--;
			}
             else if (b>1) 
             {
				res[i*2][j*2]=fu;
				res[i*2][j*2+1]=su;
				res[i*2+1][j*2]=fu;
				res[i*2+1][j*2+1]=su;
				b-=2;
			} 
            else if (a>1) 
            {
				res[i*2][j*2]=fu;
				res[i*2][j*2+1]=fu;
				res[i*2+1][j*2]=su;
				res[i*2+1][j*2+1]=su;
				a-=2;
			} 
            else imp();
		}
	if (n%2==1) 
    {
		for (int i=0;i<m/2;i++) 
        {
			vector<bool> used(20,0);
			if (i>0)
            used[res[n-1][i*2-1]]=1;
			if (n>1)
            used[res[n-2][i*2]]=1;
			if (n>1)
            used[res[n-2][i*2+1]]=1;
			int fu=0;
			while (used[fu]) 
            fu++;
			if (a>0) 
            {
				res[n-1][i*2]=fu;
				res[n-1][i*2+1]=fu;
				a-=1;
			} 
            else imp();
		}
	}
	if (swp) 
    swap(n,m);
	for (int i=0;i<n;i++) 
    {
		for (int j=0;j<m;j++) 
        {
			if (swp)
				cout << char(res[j][i]+'a');
			else
				cout << char(res[i][j]+'a');
		}
		cout << endl;
	}
}
