#include <bits/stdc++.h>

using namespace std;

#define V 6

void addDirectedEdge(vector<int> ADJ[], int v, int e)
{
	ADJ[v].push_back(e);
}

void TopologicalSortUtil(vector<int> ADJ[], bool visited[], int start, stack<int> &S)
{
	visited[start] = true;
	for (auto edge : ADJ[start])
	{
		if (!visited[edge])
		{
			TopologicalSortUtil(ADJ, visited, edge, S);
		}
	}

	S.push(start);
}

void TopologicalSort(vector<int> ADJ[])
{
	stack<int> S;

	bool visited[V];
	for (int i = 0; i < V; i++)
	{
		if (!visited[i])
		{

			TopologicalSortUtil(ADJ, visited, i, S);
		}
	}

	while (!S.empty())
	{
		cout << S.top() << "\t";
		S.pop();
	}
}

int main()
{

	vector<int> ADJ[V];

	addDirectedEdge(ADJ, 5, 0);
	addDirectedEdge(ADJ, 5, 2);
	addDirectedEdge(ADJ, 4, 0);
	addDirectedEdge(ADJ, 4, 1);
	addDirectedEdge(ADJ, 2, 3);
	addDirectedEdge(ADJ, 3, 1);

	TopologicalSort(ADJ);

	return 0;
}