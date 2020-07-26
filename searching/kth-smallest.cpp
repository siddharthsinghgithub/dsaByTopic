#include <bits/stdc++.h>

using namespace std;

int partition(vector<int> &A, int l, int r)
{

	int i = l - 1, j = l, pivot = r;

	for (j; j <= A.size() - 1; j++)
	{

		if (A[j] < A[pivot])
		{
			i++;
			int temp = A[i];
			A[i] = A[j];
			A[j] = temp;
		}
	}

	int temp = A[i+1];
	A[i+1] = A[pivot];
	A[pivot] = temp;

	return i+1;
}

int kthSmallest(vector<int> &A, int l, int r, int K)
{

	if (l < r)
	{
		int pivot = partition(A, l, r);
		// cout << "pivot" << pivot << "  value" << A[pivot] << "\n";
		for(int i=0;i<A.size();i++){
			cout<<A[i]<<"\n";
		}
		if (pivot == K)
		{
			return A[K];
		}
		else if (pivot > K)
		{
			return kthSmallest(A, l, pivot - 1, K);
		}
		else
		{
			return kthSmallest(A, pivot + 1, r, K);
		}
		return 0;
	}
}


int main()
{

	int T, N, K;
	cin >> T;
	while (T--)
	{
		cin >> N;
		vector<int> V;
		for (int i = 0; i < N; i++)
		{
			int k;
			cin >> k;
			V.push_back(k);
		}

		cin >> K;
		cout << kthSmallest(V, 0, V.size(), K-1) << "\n";
	}

	return 0;
}