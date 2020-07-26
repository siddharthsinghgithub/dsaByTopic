#include<bits/stdc++.h>

using namespace std;

int main(){
  int A = 20;
  vector<string> V;
  for(int i=1;i<=A;i++){
        if(i%15 == 0)
            V.push_back("FizzBuzz");
        else if(i%5 == 0)
             V.push_back("Buzz");
        else if(i%3 == 0)
             V.push_back("Fizz");
        else
            V.push_back(to_string(i))
    }

  return 0;
}
