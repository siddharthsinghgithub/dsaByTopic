#include <bits/stdc++.h>

using namespace std;

void dfs(vector<int> A[], vector<bool> &V, unordered_map<int, bool> &GP, int country, int cDist, int &minD, int &ans)
{
	cout << country << cDist << endl;
	V[country] = true;

	if (GP[country] && ((cDist < minD) || (cDist == minD && ans > country)))
	{
		minD = cDist;
		ans = country;
		return;
	}

	for (auto E : A[country])
	{
		if (!V[E])
			dfs(A, V, GP, E, cDist + 1, minD, ans);
	}
}

int main()
{
	int N;
	cin >> N;
	vector<int> A[N + 1];
	unordered_map<int, bool> GP;
	vector<bool> V(N + 1, false);
	int u, v;
	for (int i = 1; i < N; i++)
	{
		cin >> u >> v;
		A[u].push_back(v);
		A[v].push_back(u);
	}

	int NG, temp;
	cin >> NG;
	for (int i = 0; i < NG; i++)
	{
		cin >> temp;
		GP[temp] = true;
	}
	int country;
	int minD = INT_MAX;
	dfs(A, V, GP, 1, 0, minD, country);
	cout<<country << endl;
	return 0;
}