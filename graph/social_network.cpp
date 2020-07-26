class Solution
{
public:
	int orangesRotting(vector<vector<int>> &A)
	{

		int n = A.size(), m = A[0].size();
		queue<vector<int>> Q;

		for (int i = 0; i < A.size(); i++)
		{
			for (int j = 0; j < A[i].size(); j++)
			{
				if (A[i][j] == 2)
					Q.push({i, j, 1});

				if (A[i][j] == 1)
				{
					bool f = false;
					if (i > 0)
						f = f || (A[i - 1][j] == 0) ? false : true;

					if (i < (n - 1))
						f = f || (A[i - 1][j] == 0) ? false : true;

					if (j > 0)
						f = f ||(A[i][j-1] == 0))?false:true;

					if (j < (m - 1))
						f = f || (A[i - 1][j] == 0) ? false : true;

					if (f == false)
						return -1;
				}
			}
		}

		if (Q.empty())
			return -1;

		int ans;
		vector<int> temp;
		while (!Q.empty())
		{

			temp = Q.front();
			ans = temp[2];
			Q.pop();
			if ((temp[0] > 0) && A[temp[0]][temp[1]] == 1)
			{
				A[temp[0] - 1][j] = 2;
				Q.push({temp[0] - 1, j, ans + 1});
			}

			if ((temp[0] < n - 1) && A[temp[0]][temp[1]] == 1)
			{
				A[temp[0] + 1][j] = 2;
				Q.push({temp[0] + 1, j, ans + 1});
			}

			if ((temp[1] > 0) && A[temp[0]][temp[1]] == 1)
			{
				A[temp[0] + 1][j] = 2;
				Q.push({temp[0], j - 1, ans + 1});
			}

			if ((temp[0] < m - 1) && A[temp[0]][temp[1]] == 1)
			{
				Q.push({temp[0] + 1, j, ans + 1});
			}
		}

		return ans;
	}
};