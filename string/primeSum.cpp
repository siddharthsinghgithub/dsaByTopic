#include<bits/stdc++.h>

using namespace std;

int main(){
  unsigned long long int A = 16777214;
  bool *prime = new bool[A+1];
  memset(prime,true,sizeof(prime));

  for(unsigned long long int i=2;i*i<A;i++){
    if(prime[i] == true){
       for (unsigned long long int j = i*i; j <=A ; j+=i) {
           prime[j] = false;
         }
    }
  }


  for (unsigned long long int i = 2; i <= A; i++) {
    // cout<<i<<"\n";
    if(prime[i]  &&  prime[A-i]){
      cout<<i<<" "<<A-i;
      delete [] prime;
      return 0;
    }
  }

  return 0;

}
