/*
// Sample code to perform I/O:

#include <iostream>

using namespace std;

int main() {
	int num;
	cin >> num;										// Reading input from STDIN
	cout << "Input number is " << num << endl;		// Writing output to STDOUT
}

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/

// Write your code here

#include <bits/stdc++.h>

using namespace std;

void dfs(vector<int> ADJ[], vector<bool> &visited, int start)
{

	visited[start] = true;

	for (auto V : ADJ[start])
	{
		if (!visited[V])
		{
			dfs(ADJ, visited, V);
		}
	}
}

int main()
{

	int N, E;
	cin >> N >> E;
	vector<int> ADJ[N + 1];
	vector<bool> visited(N + 1, false);
	int u, v;
	while (E--)
	{

		cin >> u >> v;
		ADJ[u].push_back(v);
		ADJ[v].push_back(u);
	}

	int ans = 0;
	for (int i = 1; i <= N; i++)
	{
		if (!visited[i])
		{
			dfs(ADJ, visited, i);
			ans++;
		}
	}

	return ans;
}