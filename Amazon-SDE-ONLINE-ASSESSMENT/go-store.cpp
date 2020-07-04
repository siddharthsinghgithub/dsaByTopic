#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> dir = {
	{0, 1},
	{0, -1},
	{-1, 0},
	{1, 0}};

void dfs(vector<vector<int>> &Grid, int i, int j)
{

	if (Grid[i][j] == 0)
		return;

	Grid[i][j] = 0;

	for (int d = 0; d < 4; d++)
	{

		int x = i + dir[d][0];
		int y = j + dir[d][1];

		if ((x >= 0 && x < Grid.size()) && (y >= 0 && y < Grid[0].size()))
		{
			dfs(Grid, x, y);
		}
	}
}

int numberAmazonGoStores(int rows, int column, vector<vector<int>> Grid)
{

	int ans = 0;
	for (int i = 0; i < Grid.size(); i++)
	{

		for (int j = 0; j < Grid[0].size(); j++)
		{

			if (Grid[i][j] != 0)
			{
				dfs(Grid, i, j);
				ans++;
			}
		}
	}

	return ans;
}

int main()
{
	vector<vector<int>> A = {
		{1, 0, 0, 0, 0, 0, 0},
		{0, 1, 0, 0, 0, 0, 0},
		{0, 0, 1, 0, 0, 0, 0},
		{0, 0, 0, 1, 0, 0, 0},
		{0, 0, 0, 0, 1, 0, 0},
		{0, 0, 0, 0, 0, 1, 0},
		{0, 0, 0, 0, 0, 0, 1},
	};
	cout
		<< numberAmazonGoStores(4, 5, A);
	return 0;
}