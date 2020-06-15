// https://codeforces.com/contest/808/problem/D
#include <bits/stdc++.h>

using namespace std;

int main()
{
  int n;
  cin >> n;
  vector<int> A(n, 0);
  int t = n;
  long long s = 0;

  for (int i = 0; i < n; i++)
  {
    cin >> A[i];
    s+= A[i];
  }

  if (s % 2 != 0)
  {
    cout << "NO";
    return 0;
  }

  map<int, int> first, second;

  first[A[0]] = 1;
  for (int i = 1; i < n; i++)
    second[A[i]]++;

  long long sdash = 0;
  for (int i = 0; i < n ; i++)
  { cout<<"\n"<<sdash;
    sdash += A[i];
    if (sdash == s / 2)
    {
      cout << "YES\n";
      return 0;
    }
    else if (sdash < s / 2)
    {
      int sec2fst = s / 2 - sdash;
      if (second[sec2fst] > 0)
      {
        cout << "YES\n";
        return 0;
      }
    }
    else
    {
      int fst2sec = sdash - s / 2;
      if (first[fst2sec] > 0)
      {
        cout << "YES\n";
        return 0;
      }
    }

    first[A[i + 1]]++;
    second[A[i + 1]]--;
  }

  cout << "NO\n";
  return 0;
}
