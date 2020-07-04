/*
  Given an array of size n, find the majority element. The majority element is the element that appears more than floor(n/2) times.
  You may assume that the array is non-empty and the majority element always exist in the array.
*/

#include<bits/stdc++.h>

using namespace std;

int getMajorityElement(vector<int> &A){

    int majorityElement = A[0];
    int count = 1;
    for(int i=1;i < A.size();i++){
        
        if(A[i] == majorityElement){
            count++;
        }
        else{
            count--;
            
            if(count == 0){
                majorityElement = A[i];
                count = 1;
            }
        }
    }
    
    return majorityElement;
}

int main(){
    
    vector<int> A= { 1, 2, 1, 3, 2, 2, 2 };
    
    cout<<getMajorityElement(A);
    return 0;
}
