#include<bits/stdc++.h>

using namespace std;

int main(){

  int A = 7;
  int n = (2*A -1);
  vector<vector<int>> arr(n, vector<int>(n));

  for (int i = 0; i < A; i++) {

    for (int j = i; j < n-i; j++) {
      arr[j][i] =  arr[j][n-i-1] = A - i;
    }

    for (int j = i; j < n-i; j++) {
      arr[i][j] = arr[n-i-1][j] = A - i;
    }

  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout<<arr[i][j]<<" ";
    }
    cout<<"\n";
  }

  return 0;
}
