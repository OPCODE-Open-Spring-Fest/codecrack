//write your code here
// Code by Jagpreet153
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){
	string s;
	cin >> s;
	int n=s.size();
	string t;
	for(auto c:s){
		t+=c;
		int m=t.size();
		while(m>=3 && ((int)t[m-3]+t[m-2]+t[m-1])%3==0){
			if(m==3 || t[m-4]==t[m-1]){
				t.pop_back();t.pop_back();t.pop_back();
				m=t.size();
			}
			else break;
		}
	}
	{
		int m=t.size();
		while(m>=3 && ((int)t[m-3]+t[m-2]+t[m-1])%3==0){
			{
				t.pop_back();t.pop_back();t.pop_back();
				m=t.size();
			}
		}
	}
	int m=t.size();
	if(t.size()==2) sort(t.begin(),t.end());
	if(n==m){
		cout << t << '\n';
		return;
	}
	bool check=false;
	for(auto c:t) if(c=='C') check=true;
	int k=(n-m)/3;
	if(!t.empty() && t[0]!='A'){
		if(t[0]=='B') t="ABC"+t;
		else t="ACB"+t;
		k--;
	}
	else if(!check){
		if(t.empty() || t.back()=='B') t+="ABC";
		else t+="BAC";
		k--;
	}
	int temp=0;
	while(t[temp+1]=='A'+((temp+1)%2)) ++temp;
	for(int i=0; i<=temp ;i++) cout << t[i];
	for(int i=1; i<=k ;i++){
		if(i%2!=temp%2) cout << "B";
		else cout << "A";
	}
	for(int i=k; i>=1 ;i--){
		if(i%2!=temp%2) cout << "CA";
		else cout << "CB";
	}
	for(int i=temp+1; i<t.size() ;i++) cout << t[i];
	cout << '\n';
}
int main(){
	int t;
	cin >> t;
	while(t--) 
	solve();
}