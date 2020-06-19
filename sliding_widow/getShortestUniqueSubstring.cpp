/*  PROBLEM STATEMENT ---------->
	Smallest Substring of All Characters
	Given an array of unique characters arr and a string str, Implement a function getShortestUniqueSubstring that finds the smallest substring of str containing all the characters in arr. Return "" (empty string) if such a substring doesn't exist.
	Come up with an asymptotically optimal solution and analyze the time and space complexities.
	Example:
	input:  arr = ['x','y','z'], str = "xyyzyzyx"
	output: "zyx"
	Constraints:
	[time limit] 5000ms
	[input] array.character arr
	1 ≤ arr.length ≤ 30
	[input] string str
	1 ≤ str.length ≤ 500
	[output] string
*/
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

string getShortestUniqueSubstring(const vector<char> &A, const string &S)
{
	unordered_map<int, bool> M;

	for (int i = 0; i < A.size(); i++)
	{
		M[A[i]] = true;
	}

	unordered_map<int, int> M1;
	int i = 0, j = 0;
	int ans = 0;
	int m = INT8_MAX;
	string s = "";

	while (j < S.size())
	{

		cout << i << " " << j << " " << ans << " " << endl;
		while (j < S.size())
		{
			if (ans == A.size())
				break;

			if (M[S[j]])
			{
				if (M1[S[j]] == 0)
					ans++;
				M1[S[j]]++;
			}

			j++;
		}

		if (ans == A.size() && m > j - i)
		{
			m = j - i;

			s = S.substr(i, j - i);
		}

		while (i < j && ans == A.size())
		{
			if (M[S[i]])
			{
				M1[S[i]]--;
				if (M1[S[i]] == 0)
				{
					ans--;
				}
			}

			i++;

			if (ans == A.size() && m > j - i)
			{
				m = j - i;
				s = S.substr(i, j - i);
			}
		}
	}

	return s;
}

int main()
{

	cout << getShortestUniqueSubstring({'A', 'B', 'C'}, "ADOBECODEBANCDDD");

	return 0;
}