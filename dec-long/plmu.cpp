#include<iostream>
using namespace std;

int main() {
  unsigned int t,n,temp;
  cin>>t;
  while (t--) {
    cin>>n;

    unsigned int twos = 0, zeros = 0 ,k = n;
    while(k--){

      cin>>temp;
      if(temp == 2){
        twos++;
      }
      if(temp == 0){
        zeros++;
      }
    }

    cout<<(zeros*(zeros-1))/2 + (twos*(twos-1))/2<<"\n";

}

  return 0;
}
