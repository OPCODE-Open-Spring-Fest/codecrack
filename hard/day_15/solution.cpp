//write you code here 
#include<bits/stdc++.h>
using namespace std;
bool isBip(vector<vector<int> > &adj, int n){
	vector<int> side(n, -1);
	bool is_bipartite = true;
	queue<int> q;
	for (int st = 0; st < n; ++st) {
	    if (side[st] == -1) {
	        q.push(st);
	        side[st] = 0;
	        while (!q.empty()) {
	            int v = q.front();
	            q.pop();
	            for (int i = 0; i < adj[v].size() ; i++) {
	            	int u = adj[v][i];
	                if (side[u] == -1) {
	                    side[u] = side[v] ^ 1;
	                    q.push(u);
	                } else {
	                    is_bipartite &= side[u] != side[v];
	                }
	            }
	        }
	    }
	}
	return is_bipartite;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,a,b;
		cin>>n;
		vector<pair<int,int> > in(n);
		bool flag = true;
		int cnt[n+1] = {0};
		int i = 0;
		vector<vector<int> > edge;
		edge.resize(n+1);
		while(i<n){
			cin>>a>>b;
			in[i].first  = a;
			in[i].second = b;
			edge[a].push_back(i);
			edge[b].push_back(i);
			if(!flag){
				i++;
				continue;
			}
			if( a == b)	{
				flag = false;
			}
			cnt[a]++;
			cnt[b]++;
			if(cnt[a] > 2 || cnt[b] > 2)	{
				flag = false;
			}
			i++;
		}
		if(!flag){
			cout<<"NO\n";
			continue;
		}
		vector<vector<int> > adj;
		adj.resize(n);
		for(i = 1 ; i <= n ; i ++ ){
			int u = edge[i][0];
			int v = edge[i][1];
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		if(!isBip(adj,n))	cout<<"NO\n";
		else cout<<"YES\n";
		
	}
	return 0;
}