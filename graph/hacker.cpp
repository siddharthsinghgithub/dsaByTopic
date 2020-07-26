#include <bits/stdc++.h>

using namespace std;

void addDirectedEdge(vector<long long int> ADJ[], long long int v, long long int e)
{
	ADJ[v].push_back(e);
}

void TopologicalSort(vector<long long int> ADJ[], vector<double> &ways, long long int start)
{

	for (auto edge : ADJ[start])
	{
		ways[edge] = ways[edge] + double(ways[start]) / double(ADJ[start].size());
		TopologicalSort(ADJ, ways, edge);
	}
}

int main()
{
	long long int vertex, edge, start;
	cin >> vertex >> edge >> start;

	vector<long long int> ADJ[vertex + 1];
	while (edge--)
	{
		long long int v, e;
		cin >> v >> e;
		ADJ[v].push_back(e);
	}

	vector<double> ways(vertex + 1, 0.0);

	ways[start] = 1.0;
	TopologicalSort(ADJ, ways, start);
	ways[start] = 0.0;
	int m = max_element(ways.begin(), ways.end()) - ways.begin();
	for (auto i = 0; i < ways.size(); i++)
		if (ways[i] == ways[m])
			cout << i << " ";
	return 0;
}