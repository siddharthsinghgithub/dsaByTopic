#include<iostream>

using namespace std;

int main(){

  unsigned int t,n,index,value;
  cin>>t;

  while(t--){

    cin>>n;
    int score[13] = {0};

    while(n--){
      index = value = 0;
      cin>>index;
      cin>>value;

      if(score[index] < value)
        score[index] = value;

    }

    unsigned int sum = 0;
    for(int i=1;i<=8;i++){
        sum+=score[i];
    }

    cout<<sum;
  }

  return 0;
}
