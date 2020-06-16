#include<bits/stdc++.h>

using namespace std;

int binarySearch(int A[],int n, int s){

  int l= 0, r = n-1,m,result;

  while(l<=r){
    m = (l+r)/2;
    if(A[m] == s){
        result = m;
        r = m-1;
    }
    else if(A[m] > s){
      r = m-1;
    }
    else{
      l = m + 1;
    }

  }
  return result;
}

int main(){

  int A[] = {1,1,2,2,3,4,5,5,5,5,6,7,8,9,9,9,10,12,13,14,15};
  int n = sizeof(A)/sizeof(int);

  cout<<binarySearch(A,23,5);

  return 0;
}
