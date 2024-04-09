//write you code here 
// Code by Jagpreet153
// Approach It can be solved using graph theory and depth-first search (DFS). The problem is to determine if it's possible to partition a set of dominoes into two sets such that each set contains dominoes with unique numbers.

#include <bits/stdc++.h>
using namespace std;
vector<long long int> adj[200005]; // Each domino is represented as an edge in the graph, and each number on the dominoes is represented as a node.
long long int color[200005];

bool dfs(long long int v,long long int c)  //  This function performs a DFS on the graph to check if it can be colored using two colors such that no two adjacent nodes have the same color.
{ 
    color[v]=c;
    for (long long int u:adj[v]) 
    {
        if (color[u]==-1) 
        {
            if (!dfs(u,1-c)) 
            {
                return false;
            }
        } else if (color[u]==color[v]) 
        {
            return false;
        }
    }
    return true;
}

int main() 
{
    int t,i,n;
    cin>>t;
    while (t--) 
    {
        cin>>n;
        for (i=1;i<=n;i++) 
        {
            adj[i].clear();
            color[i]=-1;
        }
        for (i=0;i<n;i++) 
        {
            long long int a,b;
            cin>>a>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        bool ok=true;
        for (i=1;i<=n;i++) 
        {
            if (color[i]==-1) 
            {
                if (!dfs(i, 0)) 
                {
                    ok=false;
                    break;
                }
            }
        }
        cout<<(ok?"YES":"NO")<<endl;
    }
    return 0;
}