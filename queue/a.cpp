#include <bits/stdc++.h>

using namespace std;

int main()
{
	int N;
	cin >> N;
	int A[N];

	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}

	vector<int> vis(N, 0);
	int S = N;
	for (int i = 0; i < S; i++)
	{

		// cout<<A[i]<<N<<endl;
		vis[A[i]] = 1;

		if (N == A[i])
		{
			while (vis[N] == 1)
			{
				cout << N << " ";
				vis[N] = -1;
				N--;
			}
		}

		cout << endl;
	}

	return 0;
}
