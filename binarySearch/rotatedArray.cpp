#include<bits/stdc++.h>

using namespace std;

int binarySearch(int A[],int n){

  int l= 0, r = n-1,m,i=20;

  while(l+1 != r ){
    m = (l+r)/2;
    cout<<l<<" "<<m<<" "<<r<<"\n";

    if(A[l] > A[m]){
      r = m;
    }
    else{
      l = m = 1;
    }

  }
  return m;
}


int main(){
  int A[] = { 5 , 6 , 1 , 2 , 3 , 4};

  cout<<binarySearch(A,6);



  return 0;
}
