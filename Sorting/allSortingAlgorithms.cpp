#include <bits/stdc++.h>

using namespace std;

void printVector(vector<int> &A)
{
	for (int i = 0; i < A.size(); i++)
	{
		cout << A[i] << "\t";
	}
}

/**
 * bubbleSort
 * basically interate over the array N times
 * and compare the adjecent indices
 * and if grater then swap
 */
void bubbleSort(vector<int> &A)
{

	for (int i = 0; i < A.size(); i++)
	{
		for (int j = 0; j < A.size() - i - 1; j++)
		{
			if (A[j] > A[j + 1])
			{
				int temp = A[j];
				A[j] = A[j + 1];
				A[j + 1] = temp;
			}
		}
	}
}

// void selectionSort(vector<int> &A){
//
// }
//
void insertionSort(vector<int> &A)
{
	for (int i = 1; i < A.size(); i++)
	{

		int temp = A[i], j = i;

		while (A[j - 1] > temp && j > 0)
		{
			A[j] = A[j - 1];
			j--;
		}

		A[j] = temp;
	}
}

int merge(vector<int> &A, int start, int mid, int end)
{
	cout << "start" << start << "mid" << mid << "end" << end << "\n";
	vector<int> temp(end - start);

	int left = start;
	int right = mid;
	int tempCount = 0;
	while ((left < mid) && (right <= end))
	{
		if (A[left] < A[right])
		{
			temp[tempCount] = A[left];
			left++;
		}
		else
		{
			temp[tempCount] = A[right];
			right++;
		}

		tempCount++;
	}

	while (left <= mid)
	{
		temp[tempCount] = A[left];
		left++;
		tempCount++;
	}

	while (right <= end)
	{
		temp[tempCount] = A[right];
		right++;
		tempCount++;
	}

	for (int i = start, j = 0; i < end; i++, j++)
	{
		cout << temp[j] << "\t";
		A[i] = temp[j];
	}
	cout << "\n";
}

int mergeSort(vector<int> &A, int start, int end)
{
	if (start < end)
	{
		int mid = (start + end) / 2;
		mergeSort(A, start, mid);
		mergeSort(A, mid + 1, end);
		merge(A, start, mid, end);
	}
}

// int partition( vector<int> &A, int low,int high){

// 	int i = low -1;
// 	int pivot = A[high-1];
// 	for(int j=0;j< high-1;j++){

// 		if( A[j] <= pivot){
// 			i++;
// 			int temp = A[i];
// 			A[i] = A[j];
// 			A[j] = temp;
// 		}

// 	}

// 	int temp = A[i+1];
// 	A[i+1] = pivot;
// 	pivot = A[i+1];

// 	return (i+1);
// }

int partition(vector<int> &A, int low, int high)
{
	int pivot = A[high - 1]; // pivot
	int i = (low - 1);		 // Index of smaller element

	for (int j = low; j <= high - 1; j++)
	{

		if (A[j] < pivot)
		{
			i++;
			int temp = A[i];
			A[i] = A[j];
			A[j] = temp;
		}
		else
		{
		}
	}

	int temp = A[i + 1];
	A[i + 1] = A[high - 1];
	A[high - 1] = temp;

	return (i + 1);
}

int quickSort(vector<int> &A, int low, int high)
{
	if (low < high)
	{
		int pivot = partition(A, low, high);
		partition(A, low, pivot - 1);
		partition(A, pivot + 1, high);
	}
}

int main()
{

	// vector<int> A = {10, 13, 21, 1, 4, 5, 6, 323, 32};
	vector<int> A = {5, 9, 15, 4, 5, 6, 32};

	// bubbleSort(A);
	// insertionSort(A);
	// merge(A, 0,A.size()/2, A.size());
	// mergeSort(A, 0, A.size()-1);
	// printVector(A);
	// partition(A, 0, A.size());

	// quickSort(A, 0, A.size() - 1);

	cout << "\n";
	printVector(A);
	return 0;
}