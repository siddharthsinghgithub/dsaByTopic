#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
vector<int> adj[100001];
int vis[100001];
int cc_size;
void dfs(int node)
{
	vis[node] = 1;
	cc_size++;
	for (int i : adj[node])
	{
		if (vis[i] == 0)
			dfs(i);
	}
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, m, i, j;
		cin >> n >> m;
		for (int i = 1; i <= n; i++)
		{
			vis[i] = 0;
			adj[i].clear();
		}
		for (int i = 1; i <= m; i++)
		{
			cin >> i >> j;
			adj[i].push_back(j);
			adj[j].push_back(i);
		}
		int cnt = 0;
		long long int ans = 1;
		for (int i = 1; i <= n; i++)
		{
			if (vis[i] == 0)
			{
				cc_size = 0;
				dfs(i);
				cnt++;
				ans = (ans * cc_size) % mod;
			}
		}
		cout << cnt << " " << ans << endl;
	}
	return 0;
}