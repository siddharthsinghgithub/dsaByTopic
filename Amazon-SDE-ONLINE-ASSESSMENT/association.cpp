#include <bits/stdc++.h>
using namespace std;

vector<string> dfsPath(unordered_map<string, vector<string>> &M, unordered_map<string, bool> &V, string P, vector<string> &result)
{
	if (V[P])
		return {};
	V[P] = true;

	result.push_back(P);

	for (auto E : M[P])
	{
		dfsPath(M, V, E, result);
	}

	return result;
}

int dfs(unordered_map<string, vector<string>> &M, unordered_map<string, bool> &V, string P)
{
	int ans = 1;
	if (V[P])
		return 0;

	V[P] = true;

	for (auto E : M[P])
	{

		ans += dfs(M, V, E);
	}
	return ans;
}

vector<string> largestItemAssociation(vector<pair<string, string>> itemA)
{

	unordered_map<string, vector<string>> M;
	unordered_map<string, bool> V;
	unordered_map<string, bool> V1;

	for (auto item : itemA)
	{
		M[item.first].push_back(item.second);
		M[item.second].push_back(item.first);
	}

	string ans;
	int size = 0;
	for (auto P : M)
	{

		if (!V[P.first])
		{
			int newSize = dfs(M, V, P.first);
			if (newSize > size)
			{
				ans = P.first;
				size = newSize;
			}
			if (newSize == size and ans > P.first)
			{
				ans = P.first;
			}
		}
	}

	vector<string> result;
	dfsPath(M, V1, ans, result);
	sort(result.begin(), result.end());
	return result;
}

int main()
{

	vector<pair<string, string>> itemA = {
		{"item1", "item2"},
		{"item3", "item4"},
		{"item4", "item5"},
	};

	vector<string> res = largestItemAssociation(itemA);

	for (auto r : res)
	{
		cout << r << " ";
	}
	return 0;
}