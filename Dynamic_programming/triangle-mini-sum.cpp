// Q1
// Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.
//
// For example, given the following triangle
//
// [
//      [2],
//     [3,4],
//    [6,5,7],
//   [4,1,8,3]
// ]
// The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
//
//  Note:
// Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.


#include<bits/stdc++.h>

using namespace std;

int main(){
  int A [5][5]= {
    {2},
    {3,4},
    {6,5,7},
    {4,1,8,3},
    {9,6,7,1,8}
  };
 int n = 5;
  for(int  i = n-2 ;i >= 0;i--){
    for(int j=0;j<i+1;j++){
      A[i][j] += A[i+1][j]<A[i+1][j+1]?A[i+1][j]:A[i+1][j+1];
    }
  }

  for (int i = 0; i < n; i++) {
    for(int j=0;j<i+1;j++){
      cout<<A[i][j]<<"\t";
    }
    cout<<"\n";
}

  return 0;
}
