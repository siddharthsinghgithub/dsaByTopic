#include<bits/stdc++.h>

using namespace std;

int main(){
  vector<int> A = {8, 89};
  auto compare = [](int a, int b){
      string as = to_string(a),bs = to_string(b);
      if((as.size() == bs.size()) && a > b){
        return true;
      }

      if((as.size() == bs.size()) && a < b){
        return false;
      }

      int n;
      if(as.size() < bs.size()){
          n = as.size();
          for (int i = n; i < bs.size(); i++) {
            as+=as[0];
        }
      }
      else{
        n = bs.size();
        for (int i = n; i < as.size(); i++) {
          bs+=bs[0];
        }
      }

      if(stoi(as) > stoi(bs)){
        return true;
      }
      else{
        return false;
      }
  };

  sort(A.begin() , A.end(), compare);
  for (i = 0; i < n-1; i++)
   {
     swapped = false;
     for (j = 0; j < n-i-1; j++)
     {
        if (arr[j] > arr[j+1])
        {
           swap(&arr[j], &arr[j+1]);
           swapped = true;
        }
   } 
  string S;
  for (int i = 0; i < A.size(); i++) {
    S.append(to_string(A[i]));
  }

  return 0;
}
