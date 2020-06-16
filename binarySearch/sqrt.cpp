#include <bits/stdc++.h>

using namespace std;



int main(){

  int A = 2147483647;
  int l = 0, r = A,m;

  while(l<=r){
    cout<<l<<" "<<r<<"\n";
    m = (l+r)/2;

    if(m*m == A){
      return m;
    }
    else if(m*m > A){
       r = m-1;
    }
    else{
       l = l+1;
    }

  }

  cout<<m-1;
  return 0;
}
