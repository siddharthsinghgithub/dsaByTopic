#include<bits/stdc++.h>

using namespace std;

// int main(){
//     string s= "010";
//     string::iterator it;

//     for (it=s.begin();it!=s.end();it++){
//       if(strcmp(*it, '0')){
//         break;
//       }
//       else{
//         *it = '1';
//       }
//   }

//   cout<<s;fla
//   return 0;
// }

vector<int> gray_code(int A) {

    vector<int> sol = {0,1};

    int mSize = 1<<A;
    for(int i=2; i < mSize ; i = i<<1 ){
        
        for(int j=i-1;j>=0;j++){
            sol.push_back(sol[j]);
        }
        
        for(int j=i; j <2*i;j++){
            sol.push_back(1<<(i-1) || sol[j]);
        }
        
        cout<<"i"<<i;
        
    }
    
    return sol;
    
}

int main(){
  gray_code(3);
}