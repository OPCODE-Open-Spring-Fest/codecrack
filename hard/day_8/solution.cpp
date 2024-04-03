//write your code here
#include <bits/stdc++.h>
using namespace std;

inline int in() { int x; scanf("%d", &x); return x; }
const int N = 505;

bool dp[2][N][N];

int main()
{
	int n, k;
	cin >> n >> k;
	dp[0][0][0] = 1;
	for(int i = 1; i <= n; i++)
	{
		int now = i % 2;
		int last = 1 - now;
		int x = in();
		for(int j = 0; j <= k; j++)
			for(int y = 0; y <= j; y++)
			{
				dp[now][j][y] = dp[last][j][y];
				if(j >= x)
				{
				    dp[now][j][y] |= dp[last][j - x][y];
				    if(y >= x)
    					dp[now][j][y] |= dp[last][j - x][y - x];
				}
			}
	}
	vector <int> res;
	for(int i = 0; i <= k; i++)
		if(dp[n % 2][k][i])
			res.push_back(i);
	cout << res.size() << endl;
	for(int x : res)
		cout << x << " ";
	cout << endl;
}