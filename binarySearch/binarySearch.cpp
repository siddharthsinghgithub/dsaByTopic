#include <bits/stdc++.h>

using namespace std;

int binarySearch(vector<int> &A,int s){
  cout<<"binary search started";
  int l=0,r=A.size() - 1, m;
  while(l<r){
    m = (l+r)/2;

    if(A[m]== s){
      cout<<"element found at "<<m+1<<" position \n";
      return A[m];
    }
    else if(A[m] > s){
       r = m-1;
    }
    else{
       l = m+1;
    }
  }
  return -1;
}

int main(){

  vector<int> A = {1,3,5,7,8,10};
  int d = binarySearch(A, 8);

  return 0;
}
