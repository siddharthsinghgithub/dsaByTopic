// cycle detection

#include <bits/stdc++.h>

using namespace std;
void addDirectedEdge(vector<int> ADJ[], int u, int v)
{
	ADJ[u].push_back(v);
}

bool detectCycle(vector<int> ADJ[], vector<bool> &visited, vector<int> &rec, int start)
{
	if (!visited[start])
	{
		rec[start] = true;
		visited[start] = true;

		for (auto V : ADJ[start])
		{
			if (!visited[V] && detectCycle(ADJ, visited, rec, V))
				return true;
			if (rec[V])
				return true;
		}
	}
	rec[start] = false;
	return false;
}

int main()
{

	int N = 5;
	vector<int> ADJ[N + 1];

	addDirectedEdge(ADJ, 0, 1);
	addDirectedEdge(ADJ, 1, 2);
	addDirectedEdge(ADJ, 0, 2);
	addDirectedEdge(ADJ, 2, 3);
	addDirectedEdge(ADJ, 2, 0);

	vector<bool> visited(N, false);
	vector<bool> rec(N, false);

	int ans = 0;
	for (int i = 0; i < N; i++)
	{
		if (!visited[i])
			cout << " Cycle Detected" << detectCycle(ADJ, visited, rec, i);
	}

	return ans;
}